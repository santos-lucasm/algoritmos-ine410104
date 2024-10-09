import subprocess
import math
import sys

left_count = 0
right_count = 0


def count_occurrences(arr, num):
    count = 0
    for i in arr:
        if i == num:
            count += 1
    return count


def test_number_pair(n1: int, n2: int):
    res = subprocess.getoutput(f"./tester_descomprimido {n1} {n2}")
    # res = subprocess.getoutput(f"python3 tester-descomprimido.py {n1} {n2}")
    if (int(res.strip()) == 1):
        return 1
    return 0


def verify_set(numbers: list):
    global left_count
    global right_count

    if (len(numbers) == 2):
        return test_number_pair(numbers[0], numbers[1])

    left = numbers[:len(numbers)//2]
    right = numbers[len(numbers)//2:]
    left_result = verify_set(left)
    left_count += left_result

    right_result = verify_set(right)
    right_count += right_result

    print(left, right, left_result, right_result)
    print(len(numbers))
    print("---")

    if left_result == right_result:
        return left_result

    # left_count = count_occurrences(numbers, left_result)
    # right_count = count_occurrences(numbers, right_result)

    if left_count > (len(numbers) // 2):
        return left_result
    if right_count > (len(numbers) // 2):
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
