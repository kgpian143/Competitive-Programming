#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // (distance, node)

vector<int> dijkstra(const unordered_map<int, unordered_map<int, int>>& graph, int source) {
    vector<int> dist(graph.size() + 1, INT_MAX);
    dist[source] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (current_dist > dist[current_node]) {
            continue;
        }

        for (const auto& neighbor : graph.at(current_node)) {
            int neighbor_node = neighbor.first;
            int weight = neighbor.second;
            if (dist[current_node] + weight < dist[neighbor_node]) {
                dist[neighbor_node] = dist[current_node] + weight;
                pq.push({dist[neighbor_node], neighbor_node});
            }
        }
    }

    return dist;
}

vector<int> min_cost_of_travel(int g_nodes, const vector<int>& g_from, const vector<int>& g_to, const vector<int>& g_weight, int source, int target) {
    unordered_map<int, unordered_map<int, int>> graph;
    unordered_map<int, unordered_map<int, int>> reverse_graph;

    for (int i = 0; i < g_from.size(); ++i) {
        graph[g_from[i]][g_to[i]] = g_weight[i];
        reverse_graph[g_to[i]][g_from[i]] = g_weight[i];
    }

    vector<int> dist_s = dijkstra(graph, source);
    vector<int> dist_t = dijkstra(reverse_graph, target);

    vector<int> result;

    for (int i = 0; i < g_from.size(); ++i) {
        int temp_weight = graph[g_from[i]][g_to[i]];
        graph[g_from[i]][g_to[i]] = 0;

        int cost_s_to_v1 = dist_s[g_from[i]];
        int cost_v2_to_t = dist_t[g_to[i]];

        if (cost_s_to_v1 == INT_MAX || cost_v2_to_t == INT_MAX) {
            result.push_back(-1);
        } else {
            result.push_back(cost_s_to_v1 + cost_v2_to_t);
        }

        graph[g_from[i]][g_to[i]] = temp_weight;
    }

    return result;
}

int main() {
    int g_nodes = 3;
    vector<int> g_from = {1, 2};
    vector<int> g_to = {2, 3};
    vector<int> g_weight = {1, 2};
    int source = 1;
    int target = 3;

    vector<int> result = min_cost_of_travel(g_nodes, g_from, g_to, g_weight, source, target);

    for (int cost : result) {
        cout << cost << " ";
    }
    cout << endl;

    return 0;
}