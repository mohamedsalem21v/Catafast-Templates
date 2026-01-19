#include <bits/stdc++.h>
#define sp " "
#define endl "\n"
#define ll long long
#define int long long
#define ld long double
#define ull unsigned long long
#define ve vector<int>
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()
#define fixed(n) fixed << setprecision(n)
#define debug cout << "\n======================\n"
const int MOD = 1e9 + 7;
const int inf = 1e18;
#define input(v)       \
    for (auto &it : v) \
    cin >> it
#define output(v)      \
    for (auto &it : v) \
    cout << it << " "
using namespace std;

void FastIo()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

template <typename T = int>
struct Dijkstra
{

    struct Edge
    {
        T v, w;
        Edge(T V = 0, T W = 0) : v(V), w(W) {}
        bool operator<(const Edge &e) const { return w > e.w; }
    };

    vector<vector<Edge>> adj;

    Dijkstra(int edges, bool indirected = true)
    {
        adj.resize(edges + 10);
        for (int i = 0, u, v, w; i < edges; i++)
        {
            cin >> u >> v >> w;
            adj[u].push_back(Edge(v, w));
            if (indirected)
                adj[v].push_back(Edge(u, w));
        }
    }

    T Min_Cost(int src, int dest)
    {
        int n = adj.size();
        vector<T> dist(n, LLONG_MAX);
        dist[src] = 0;
        priority_queue<Edge> Dij;
        Dij.push(Edge(src, 0));
        while (!Dij.empty())
        {
            Edge top = Dij.top();
            T u = top.v;
            T cost = top.w;
            Dij.pop();
            if (cost > dist[u])
                continue;
            for (const Edge &edge : adj[u])
            {
                T v = edge.v;
                T w = edge.w;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    Dij.push(Edge(v, dist[v]));
                }
            }
        }
        return (dist[dest] == LLONG_MAX ? -1 : dist[dest]);
    }

    vector<T> get_dist(int src)
    {
        int n = adj.size();
        vector<T> dist(n, LLONG_MAX);
        dist[src] = 0;
        priority_queue<Edge> Dij;
        Dij.push(Edge(src, 0));
        while (!Dij.empty())
        {
            Edge top = Dij.top();
            T u = top.v;
            T cost = top.w;
            Dij.pop();
            if (cost > dist[u])
                continue;
            for (const Edge &edge : adj[u])
            {
                T v = edge.v;
                T w = edge.w;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    Dij.push(Edge(v, dist[v]));
                }
            }
        }
        return dist;
    }

    vector<T> get_path(int src, int dest)
    {
        int n = adj.size();
        vector<T> dist(n, LLONG_MAX);
        vector<T> parent(n, -1);
        dist[src] = 0;
        priority_queue<Edge> Dij;
        Dij.push(Edge(src, 0));
        while (!Dij.empty())
        {
            Edge top = Dij.top();
            T u = top.v;
            T cost = top.w;
            Dij.pop();
            if (cost > dist[u])
                continue;
            for (const Edge &edge : adj[u])
            {
                T v = edge.v;
                T w = edge.w;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    Dij.push(Edge(v, dist[v]));
                }
            }
        }
        vector<T> path;
        for (int i = dest; i != -1; i = parent[i])
            path.push_back(i);
        reverse(path.begin(), path.end());
        return path;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    Dijkstra<long long> dij(m, false);
    vector<long long> dist = dij.get_dist(1);

    for (int i = 1; i <= n; i++)
        cout << dist[i] << sp;
    cout << endl;
}

signed main()
{
    FastIo();
    int test = 1;
    // cin >> test;
    for (int tc = 1; tc <= test; tc++)
    {
        solve();
    }
}