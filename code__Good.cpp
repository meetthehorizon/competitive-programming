#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long nCr(int n, int r) {
    r = max(r, n - r); 
    long long ans = 1;

    for(int i = 1; i <= r; i++) {
        ans *= (n - r + i);
        ans /= i;
    }
    return ans;
}

int main(void) {
    int k; cin >> k;
    if (k == 0 || k == 4) {
        cout << "2\n";
        exit(0);
    }
    if (k == 1 || k == 2) {
        cout << "4\n";
        exit(0);
    }

    int pow2 = ceil(log2(k));
    long long num = pow(2, pow2);
    long long r = num - k;
    
    if (r < 0 || r > pow2 + 1) cout << "0\n";
    else nCr(pow2 + 1, r);
}

