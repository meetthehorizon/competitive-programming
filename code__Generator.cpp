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

void printTreeEdges(vector<int> prufer, int m)
{
    int vertices = m + 2;
    vector<int> vertex_set(vertices);

    for (int i = 0; i < vertices; i++)
        vertex_set[i] = 0;
 
    for (int i = 0; i < vertices - 2; i++)
        vertex_set[prufer[i] - 1] += 1;
 
    int j = 0;

    for (int i = 0; i < vertices - 2; i++) 
    {
        for (j = 0; j < vertices; j++)
        {
            if (vertex_set[j] == 0)
            {
                vertex_set[j] = -1;
                cout << (j + 1) << " "
                                << prufer[i] << "\n";
 
                vertex_set[prufer[i] - 1]--;
 
                break;
            }
        }
    }
 
    j = 0;
    for (int i = 0; i < vertices; i++)
    {
        if (vertex_set[i] == 0 && j == 0)
        {
 
            cout << (i + 1) << " ";
            j++;
        }
        else if (vertex_set[i] == 0 && j == 1)
            cout << (i + 1) << "\n";
    }
}

int ran(int l, int r)
{
    return l + (rand() % (r - l + 1));
}
 
void generateRandomTree(int n)
{
 
    int length = n - 2;
    vector<int> arr(length);
 
    // Loop to Generate Random Array
    for (int i = 0; i < length; i++) 
    {
        arr[i] = ran(0, length + 1) + 1;
    }
    printTreeEdges(arr, length);
}


vector<int> gen_vec(int x, int high) {
	vector<int> ret;
	while (x >= 25) {
		int n = ran(5, high);
		ret.push_back(n);
		x -= n * n;
	}

	return ret;
}

int main(void) {

    int seed;
	srand(time(0));

    freopen("out.txt", "w", stdout);

    // cout << "1\n2000\n";
    // // generateRandomTree(2000);

    // for (int i = 1; i < 2000; ++i) {
    //     cout << i << ' ' << i+1 << '\n';
    // }

	auto tc = gen_vec(4e6, 1e3);
// 
	cout << tc.size() << '\n';
	for (auto &n: tc) {
		cout << n << '\n';
		generateRandomTree(n);
	}
}	 
	