#include <iostream>
using namespace std;

const int maxn = 100;
int adj[maxn][maxn];
int visit[maxn];

void dfs(int u, int n) {
    cout << u << " ";
    visit[u] = 1;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && visit[v] == 0) {
            dfs(v, n);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    int start;
    cin >> start;
    dfs(start, n);
    return 0;
}
