"""
Kshitij Sharma
github: meetthehorizon
   /\\_/\
  (= ._.)
  / >  \\>
"""

import sys

def input(): return sys.stdin.readline().strip()

def solve():
    # Start From Here
    points = []

    for _ in range(4):
        points.append(list(map(int, input().split())))

    points.sort()
    x = points[1][1] - points[0][1]

    print(x ** 2)

is_test = True
t = 1 if not is_test else int(input())
for _ in range(t):
    solve()