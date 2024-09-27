# Kshitij Sharma
# github: meetthehorizon
#    /\_/\
#   (= ._.)
#   / >  \>


import sys

def input(): return sys.stdin.readline().strip()
def solve():
    n = int(input())
    vec = [0] + list(map(int, input().split()))
    s = input()

    l, r, ret = 0, n - 1, 0
    for i in range(len(vec) - 1): vec[i+1] += vec[i]

    while l < r:
        while l < n and s[l] != 'L': l += 1
        while r >= 0 and s[r] != 'R': r -= 1

        if l == n or r == -1: break
        
        ret += vec[r+1] - vec[l]
        l += 1
        r += -1

    print(ret)

is_test = True

t = 1 if not is_test else int(input())
for _ in range(t): solve()
