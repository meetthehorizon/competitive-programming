#include <bits/stdc++.h>
using namespace std;


vector<int> adj[200002];
vector<int> adj_t[200002];
vector<int> topo;
int colors[200002];
bool visited[200002];

void dfs(int node){
    visited[node] = true;
    for (int child: adj[node]){
        if (!visited[child])
            dfs(child);
    }
    topo.push_back(node);
}

void dfs2(int node, int color){
    visited[node] = true;
    colors[node] = color;
    for (int child: adj_t[node]){
        if (!visited[child])
            dfs2(child, color);
    }
}

int main(){
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++){
        char c1, c2;
        int x1, x2;
        cin >> c1 >> x1 >> c2 >> x2;
        x1--;
        x2--;
        int b1 = c1 == '+' ? 1 : 0;
        int b2 = c2 == '+' ? 1 : 0;
        adj[n * (1 - b1) + x1].push_back(n * b2 + x2);
        adj_t[n * b2 + x2].push_back(n * (1 - b1) + x1);
        adj[n * (1 - b2) + x2].push_back(n * b1 + x1);
        adj_t[n * b1 + x1].push_back(n * (1 - b2) + x2);
    }
    
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 2 * n; i++){
        if (!visited[i])
            dfs(i);
    }
    
    memset(visited, false, sizeof(visited));
    reverse(topo.begin(), topo.end());
    int color = 0;
    for (int node:topo){
        if (!visited[node])
            dfs2(node, color++);
    }
    vector<char> ans(n);
    for (int i = 0; i < n; i++){
        if (colors[i] == colors[i + n]){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        if (colors[i] < colors[i + n]){
            ans[i] = '+';
        }
        if (colors[i] > colors[i + n]){
            ans[i] = '-';
        }
    }
    
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}
