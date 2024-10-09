# Function to count the occurrences
def count_occurrences(arr, num):
    count = 0
    for i in arr:
        if i == num:
            count += 1
    return count

# Function to find the majority element using recursion
def find_majority_util(arr, low, high):
    # Base case: single element array
    if low == high:
        return arr[low]

    # Divide the array into left and right halves
    mid = (low + high) // 2
    left_majority = find_majority_util(arr, low, mid)
    right_majority = find_majority_util(arr, mid+1, high)

    # If left and right halves have the same majority element
    if left_majority == right_majority:
        return left_majority

    # Count the occurrences of the majority element in the entire array
    left_count = count_occurrences(arr[low:high+1], left_majority)
    right_count = count_occurrences(arr[low:high+1], right_majority)

    # Return the element that occurs more than n/2 times
    if left_count > (high-low+1) // 2:
        return left_majority
    if right_count > (high-low+1) // 2:
        return right_majority

    # No majority element
    return -1

# Function to find the majority element
def find_majority(arr):
    n = len(arr)
    majority = find_majority_util(arr, 0, n-1)
    if majority != -1:
        print(majority)
    else:
        print("No Majority Element")

# Driver Code
if __name__ == "__main__":
    arr = [3, 2, 9, 2, 2]
    n = len(arr)

    find_majority(arr)
