q = 6

ncr = [[0] * q] * q
for i in range(q):
    ncr[i][0] = 1

for i in range(1, q):
    for j in range(1, i + 1):
        print(f"({i}, {j})", end=" ")
    print()

print(*ncr, sep="\n")
