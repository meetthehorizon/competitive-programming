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

vector<vector<int>> gen_perm(int n) {
	vector<int> vec(n); iota(vec.begin(), vec.end(), 1);
	vector<vector<int>> perm;
	do{
		perm.push_back(vec);
	}while(next_permutation(vec.begin(), vec.end()));

	return perm;
}

int main(void) {
	int seed; cin >> seed;
	srand(seed);

	cout << "1\n";
	while(1) {
		vector<int> vec;
		for (int i = 0; i < 7; ++i) vec.push_back(gen_int(-(int(100)), (int(100))));

		vec[0] = 0;
		if (vec[5] <= vec[6] && vec[3] <= vec[4]) {
			for (auto &v: vec) cout << v << ' ';
			break;
		}
	}
	
}	 
	