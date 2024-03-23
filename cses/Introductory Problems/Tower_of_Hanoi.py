n = int(input())

sol = ["1 3"]
for _ in range(n - 1):
    sol = (
        [s.replace("2", "4").replace("3", "2").replace("4", "3") for s in sol]
        + ["1 3"]
        + [s.replace("2", "4").replace("1", "2").replace("4", "1") for s in sol]
    )
print(len(sol), *sol, sep="\n")
