import math

c = 2

def multiply(x, y):
    if y == 0:
        return 0
    else:
        return multiply(c * x, math.floor(y / c)) + x * (y % c)

# def multiply(x, y, counter):
#     if y == 0:
#         return 0
#     else:
#         counter[0] += 1
#         print(f"x={x}, y={y}, [y/c]={ math.floor(y / c)}, x * (y % c) = {x * (y % c)}")
#         return multiply(c * x, math.floor(y / c), counter) + x * (y % c)

a = 4
b = 31
# counter = [0]
# print(multiply(a, b, counter))
print(multiply(a, b))
# print(counter[0])