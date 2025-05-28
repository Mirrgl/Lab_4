import random
import time

def print_vector(vec):
    print(' '.join(map(str, vec)))

def count_even_numbers(arr1):
    count = 0
    for i in range(0, len(arr1), 2):
        if arr1[i] % 2 == 0:
            print(arr1[i], end=' ')
            count += 1
    print(f"\nВсего {count}")

def arr2_into_arr1(arr1, arr2):
    count = 0
    common_exists = False
    for num2 in arr2:
        count = 0
        for num1 in arr1:
            if num2 == num1:
                count += 1
                common_exists = True
        if count > 0:
            print(f"Число {num2} повторяется {count}")
    if not common_exists:
        print("В первом и втором массивах нет общих чисел")

def sort_symbols(array):
    signs = []
    upper = []
    brackets = []
    digits = []
    lower = []
    
    for char in array:
        code = ord(char)
        if code in {33, 34, 39, 46, 58, 59, 60, 62, 63}:
            signs.append(char)
        elif code in range(65, 91):
            upper.append(char)
        elif code in {34, 39, 40, 41, 60, 62, 91, 93, 123, 125}:
            brackets.append(char)
        elif code in range(48, 58):
            digits.append(char)
        elif code in range(97, 123):
            lower.append(char)
    
    return (signs + upper + brackets + digits + lower)

def sort_numbers(array):
    return sorted([int(''.join(sorted(str(i)))) for i in array])

random.seed(time.time())

arr1 = [random.randint(10, 30) for _ in range(random.randint(15, 30))]
print_vector(arr1)

arr2 = [random.randint(10, 30) for _ in range(5)]
print_vector(arr2)

count_even_numbers(arr1)
arr2_into_arr1(arr1, arr2)
print()

symbols = list(input().replace(' ', ''))
print(' '.join(sort_symbols(symbols)))

arr3 = [random.randint(1000, 9000) for _ in range(random.randint(5, 10))]
print_vector(arr3)

print_vector(sort_numbers(arr3))