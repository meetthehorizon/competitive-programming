#include <bits/stdc++.h>
using namespace std;

vector<int> gen_arr(int n, int low, int high) {
	vector<int> vec;
	while(n--) vec.push_back(rand() % (high - low) + low);
	return vec;
}

void print_vec(vector<int> vec, int off=0) {
	for (auto &v: vec) {
		cout << v + off<< ' ';
	} cout << '\n';
}

int gen_int(int low, int high) {
	return rand() % (high - low) + low;
}

int main(void) {

    int seed; cin >> seed;
    srand(seed);

    cout << "1\n7\n";
    for (auto &v: gen_arr(7, 1, 7)) cout << v << ' ';
}	 
	