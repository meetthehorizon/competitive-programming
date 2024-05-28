#include <bits/stdc++.h>
using namespace std;

vector<int> gen_arr(int n, int low, int high) {
	vector<int> vec;
	while(n--) vec.push_back(rand() % (high - low) + low);
	return vec;
}

template<typename T>
void print_vec(T vec) {
	for (auto &v: vec) {
		cout << v << ' ';
	} cout << '\n';
}

int main(void) {
	int seed; cin >> seed;
	srand(seed);

	int tc = 1;
	cout << tc << '\n';
	while (tc--) {
		auto vec = gen_arr(10, 1, 500);

		cout << vec.size() << '\n';
		print_vec(vec);
	}	
}