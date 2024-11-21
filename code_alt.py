# Kshitij Sharma
# github: meetthehorizon
#    /\_/\
#   (= ._.)
#   / >  \>


import sys

def input(): return sys.stdin.readline().strip()
def solve():
   arr = [input() for _ in range(8)]

is_test = False

t = 1 if not is_test else int(input())
for _ in range(t): solve()