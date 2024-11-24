#include <bits/stdc++.h>
using namespace std;
    
string btos(long long x) {
    string s = "";
    while (x) {
        if (x&1) s.push_back('1');
        else s.push_back('0');
        x /= 2;
    }
    return s;
}

long long solve(long long l, long long r, long long x) {

    return 0;
}

int main(void) {
    int q; cin >> q;

    for (int i = 1; i <= 10000; ++i) {
        string s = btos(i);
        if (s.find("101") != string::npos) {
            cout << i << ": " << s << '\n';
        }
    }

    while (q--) {
        long long l, r, k; cin >> l >> r >> k;
        cout << solve(l, r, k) << '\n';
    }
}
