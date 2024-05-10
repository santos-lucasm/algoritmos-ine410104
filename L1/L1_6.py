import subprocess
import math
import sys


def count_occurrences(arr, num):
    count = 0
    for i in arr:
        if i == num:
            count += 1
    return count


def test_number_pair(n1: int, n2: int):
    res = subprocess.getoutput(f"./tester {n1} {n2}")
    # res = subprocess.getoutput(f"python3 tester-descomprimido.py {n1} {n2}")
    if (int(res.strip()) == 1):
        return 1
    return 0


def verify_set(numbers: list):
    if (len(numbers) == 2):
        return test_number_pair(numbers[0], numbers[1])

    left = numbers[:len(numbers)//2]
    right = numbers[len(numbers)//2:]
    left_result = verify_set(left)
    right_result = verify_set(right)

    if left_result == right_result:
        return left_result

    left_count = count_occurrences(numbers[0:len(numbers)], left_result)
    right_count = count_occurrences(numbers[0:len(numbers)], right_result)

    if left_count > len(numbers) // 2:
        return left_result
    if right_count > len(numbers) // 2:
        return right_result
    return 0


def test_procedure(input_set):
    if (math.log2(len(input_set)).is_integer() is True):
        result = verify_set(input_set)
        return result
    else:
        return 0


if __name__ == "__main__":
    print(test_procedure(sys.argv[1:]))
