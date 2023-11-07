def find_majority_element(arr, start, end):
    if start == end:
        return arr[start]

    mid = (start + end) // 2

    left_majority = find_majority_element(arr, start, mid)
    right_majority = find_majority_element(arr, mid + 1, end)

    if left_majority == right_majority:
        return left_majority

    left_count = 0
    right_count = 0
    for element in arr[start : end + 1]:
        if element == left_majority:
            left_count += 1
        elif element == right_majority:
            right_count += 1

    return left_majority if left_count > right_count else right_majority

def find_majority(arr):
    if not arr:
        return None

    majority_element = find_majority_element(arr, 0, len(arr) - 1)

    count_majority = sum(1 for element in arr if element == majority_element)
    if count_majority > len(arr) // 2:
        return majority_element
    else:
        return None

arr = [4, 3, 3, 1, 3, 3, 9, 3]
result = find_majority(arr)

if result is not None:
    print(f"The majority element is: {result}")
else:
    print("No majority element found.")