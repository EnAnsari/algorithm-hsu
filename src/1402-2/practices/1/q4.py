def find_majority_element(nums):
    def majority_element_in_range(low, high):
        if low == high:
            return nums[low]

        mid = (low + high) // 2

        left_majority = majority_element_in_range(low, mid)
        right_majority = majority_element_in_range(mid + 1, high)

        if left_majority == right_majority:
            return left_majority

        left_count = sum(1 for i in range(low, high + 1) if nums[i] == left_majority)
        right_count = sum(1 for i in range(low, high + 1) if nums[i] == right_majority)
        
        if left_count > (high - low + 1) // 2:
            return left_majority
        elif right_count > (high - low + 1) // 2:
            return right_majority
        else:
            return None

    return majority_element_in_range(0, len(nums) - 1)

arr = [3, 3, 4, 2, 4, 4, 2, 4, 4]
print("Majority element:", find_majority_element(arr))

# time complexity: O(n log n)