"""
Kshitij Sharma
github: meetthehorizon
   /\_/\
  (= ._.)
  / >  \>
"""

import sys

def input(): return sys.stdin.readline().strip()
def solve():
	# CHILL BRO
   # I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
   s = input()
   if (s != "AtCoder Land"):
   	print("No")
   else:
   	print("Yes")

is_test = False
for _ in range(1 if not is_test else int(input())): solve()
