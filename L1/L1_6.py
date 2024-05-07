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
    if(n1 == n2):
        return n1 
    return False
#    res = subprocess.getoutput(f"./tester {n1} {n2}")
#    if int(res.strip()) == 1:
#        print("Equivalentes")
#    else:
#        print("Nao equivalentes")
#

def verify_set(numbers: list):
    if(len(numbers) == 2):
        return numbers[0]
        #test_number_pair(int(numbers[0]), int(numbers[1]))

    left = numbers[:len(numbers)//2]
    right = numbers[len(numbers)//2:]
    left_result = verify_set(left)
    right_result = verify_set(right)
    
    print("{} RESULT: {}".format(left, left_result))
    print("{} RESULT: {}".format(right, right_result))

    if left_result == right_result:
        return left_result

    left_count = count_occurrences(numbers[0:len(numbers)], left_result)
    right_count = count_occurrences(numbers[0:len(numbers)], right_result)

    if left_count > len(numbers) // 2:
        return left_result
    if right_count > len(numbers) // 2:
        return right_result
    return -1

if __name__ == "__main__":
    input_set = sys.argv[1:]
    if(math.log2(len(input_set)).is_integer() == True):
        print(verify_set(input_set))
    else:
        print("Invalid set")

