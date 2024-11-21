#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Function to print a directed graph as a test case
void print_graph(int n, const set<pair<int, int>>& edges) {
    cout << n << " " << edges.size() << endl;
    for (const auto& edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }
}

// Function to generate up to max_graphs random directed graphs with n nodes
void generate_random_graphs(int n, int max_graphs) {
    vector<pair<int, int>> non_self_edges;
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            if (u != v) {
                non_self_edges.push_back({u, v});
            }
        }
    }

    int non_self_edge_count = non_self_edges.size();
    int total_graphs = 0;
    set<vector<bool>> used_masks; // Track used masks to avoid duplicates
    vector<set<pair<int, int>>> graphs;

    while (total_graphs < max_graphs) {
        vector<bool> mask(non_self_edge_count);
        for (int i = 0; i < non_self_edge_count; ++i) {
            mask[i] = uniform_int_distribution<int>(0, 1)(rng); // Random 0 or 1 for each edge
        }

        if (used_masks.find(mask) != used_masks.end()) {
            continue; // Skip duplicate configurations
        }
        used_masks.insert(mask);

        set<pair<int, int>> edges;
        for (int i = 0; i < non_self_edge_count; ++i) {
            if (mask[i]) {
                edges.insert(non_self_edges[i]);
            }
        }

        // Add a self-loop at a random node or none
        int self_loop_node = uniform_int_distribution<int>(0, n)(rng);
        if (self_loop_node > 0) {
            edges.insert({self_loop_node, self_loop_node});
        }

        graphs.push_back(edges);
        total_graphs++;
    }

    // Print total number of graphs and each graph as a test case
    cout << graphs.size() << endl;
    for (const auto& edges : graphs) {
        print_graph(n, edges);
    }
}

int main() {
    int n=10, max_graphs = 100;
    // cout << "Enter the number of nodes (n): ";
    // cin >> n;

    generate_random_graphs(n, max_graphs);
    return 0;
}
