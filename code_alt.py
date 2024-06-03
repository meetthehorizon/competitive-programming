from itertools import product

n = 3
lst = list(product(range(1, n+1), repeat=n))

print(lst)