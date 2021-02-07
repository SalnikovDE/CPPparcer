# Тестовое задание 
## Парсер текста на C++

#### Интерфейс

В файле config в следующем порядке каждый раз с новой строки указываются:
  1. Путь к файлу с фильтрами. (По умолчанию "filters.txt")
  2. Путь к входным данным. (По умолчанию "input.txt")
  3. Пусть к выходным данным. (По умолчанию "output.txt").

Фильтры имеют следующий синтаксис:
  1. Каждый новый фильтр с новой строки.
  2. Первый символ служебный и указывает на тип фильтрации.
  
    2.1. + Подстрока входит в строку без учета регистра.
    2.2. - Подстрока не входит в строку без учета регистра.
    2.3. # Подстрока входит в строку с учетом регистра.
    2.4. = Подстрока не входит в строку с учетом регистра.
  3. Все символы начиная со второго до конца строки проверяются.
  4. Если строка не соответствует символу, она игнорируется при проверке.
Программа запускается из консоли без параметров.

#### Компиляция и запуск
  Перейти в директорию с main.cpp выполнить make и запустить parser, указав при этом рабочие файлы в config и необходимые фильтры.
#### Ограничения
  1. Программа собиралась на линукс с помощью g++. У других систем/компиляторов могут быть другие реализации std::string и работы с файлами, что может повлиять на работоспособность.
  2. Строка должна помещаться в память целиком. В теории можно обойти это ограничение, сохраняя обрабатываемую строку и, например, префикс функцию для поиска в отдельный файл, но это сильно усложнит код, и вряд-ли необходимо. 
  3. Символы в файлах должны восприниматься стандартным вводом, выводом, например нельзя использовать '\0' в файле. Это ограничение можно обойти, если считывать файл побайтово, не пользуясь стандартными функциями, вроде getline, но я посчитал, что это также не необходимо.
  4. Если не удается прочитать какие либо файлы, то программа завершается с ошибкой и выводом сообщения в консоль. Если же ошибка случатся во время работы программы, например при отключении от сети или при принудительном завершении, то поведение неопределено.
 
 #### Алгоритм работы
 
 Для поиска строк в любом случае необходимо проверить все строки, следовательно проверить все символы, а т.к. лучшая асимптотика поиска подстроки в стоке это
 O(n), то из этого следует, что программа будет иметь линейное время работы, значит возможные оптимизации заключаются в уменьшении константы.
 
 Строки удовлетворяющие условию, должны пройти проверку всеми фильтрами, но строки не удовлетворяющие, должны не пройти хотя бы одну проверку. На основе этого факта и строится моя оптимизация. Фильтры применяются не в порядке заданом пользователем, а в порядке убывания строгости.
 
 Строгость - некоторое отношение порядка заданое на фильтрах. Оно показывает насколько больше строк один фильтр исклюючает по сравниению с другим. Эта оптимизация
эвристическая, так что лучший порядок не гарантируется, но отношение строится изходя из предположения, что чем длиннее строка, тем меньше ее вероятность появления в поиске, и тем больше ее вероятноть не появления, а также что вероятность не найти строку больше вероятности найти.
 
 Для поиска подстроки в строке испльзуется алгоритм Кнута-Морриса-Пратта, для поддержания порядка строгости std::set (конкретная реализация страндартом не гарантируется, но почти всегда это красно-черное дерево), в любом случае количество фильтров обычно много меньше количества данных, так что это слабо влият на производительность.
 
 #### Возможные оптимизации
 Одна из возможных попыток оптимизации, это учучшение эвристики строгости. Например можно считать процент отсеяных каждым фильтром строк и каждые k строк обновлять порядок, но это не поможет при неоднородных данных.
 
 Также можно оптимизировать ввод вывода, считывая и записывая в файл блоками "сырых" данных, которые можно будет парсить внутри, но я выбрал страндартный ввод/вывод для читаемости кода.
