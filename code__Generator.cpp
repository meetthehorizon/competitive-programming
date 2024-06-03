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

vector<vector<int>> gen_perm(int n) {
	vector<int> vec(n); iota(vec.begin(), vec.end(), 1);
	vector<vector<int>> perm;
	do{
		perm.push_back(vec);
	}while(next_permutation(vec.begin(), vec.end()));

	return perm;
}

vector<vector<int>> gen_all(int n, int low, int high) {
	vector<vector<int>> perms;
}

int main(void) {
	int seed; cin >> seed;
	srand(seed);

	int tc = 1;
	int l = rand()%((int)1e9), r = rand()%((int)1e9);

	if (l > r) swap(l, r);
	cout << tc << '\n';
	cout << ++l << ' ' << ++r << '\n';
}
