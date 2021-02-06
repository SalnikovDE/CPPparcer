import random
import string

#use python gen.py > biginput.txt

def get_random_string(length):
    letters = string.ascii_letters
    result_str = ''.join(random.choice(letters) for i in range(length))
    return result_str

size = 500
length = 20
for i in range(size):
    print(get_random_string(length))
