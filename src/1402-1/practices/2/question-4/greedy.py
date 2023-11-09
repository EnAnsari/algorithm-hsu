def min(list, validation):
    indexes = [index for index, is_true in enumerate(validation) if is_true] # filtered indexes
    if not indexes:
        return None
    min_index = indexes[0]

    for i in indexes[1:]:
        if list[min_index] > list[i]:
            min_index = i
    return min_index

def greedy_assignment(cost_matrix, n):
    assignments = []
    temp = [True] * n
    for person in range(n):
        min_index = min(cost_matrix[person], temp)
        assignments.append(min_index)
        temp[min_index] = False

    return assignments

# cost matrix
c = [
    [4, 2, 8],
    [3, 5, 2],
    [8, 7, 4]
]

n = len(c)
assignments = greedy_assignment(c, n)

print("Greedy assignment:")
for i in range(n):
    print(f"Person {i + 1} is assigned to Job {assignments[i] + 1} with cost {c[i][assignments[i]]}")
