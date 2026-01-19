#include <bits/stdc++.h>
#define sp " "
#define endl "\n"
const int MOD = 1e9 + 7;
#define ll long long
#define ld long double
#define ull unsigned long long
#define ve vector<int>
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()
#define fixed(n) fixed << setprecision(n)
#define input(v)       \
    for (auto &it : v) \
    cin >> it
#define output(v)      \
    for (auto &it : v) \
    cout << it << " "
#define int long long
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
struct Prim
{
    struct Edge
    {
        T v, w;

        Edge(T V = 0, T W = 0) : v(V), w(W) {}

        bool operator<(const Edge &e) const
        {
            return w < e.w;
        }
    };

    vector<vector<Edge>> adj;
    vector<T> marked;

    Prim(int n = 0)
    {
        adj = vector<vector<Edge>>(n + 10);
        marked = vector<T>(n + 10, 0);
    }

    void build_adj(int edges, bool is_directed = false)
    {
        for (int i = 0, u, v, w; i < edges && cin >> u >> v >> w; i++)
        {
            adj[u].push_back(Edge(v, w));
            if (!is_directed)
                adj[v].push_back(Edge(u, w));
        }
    }

    T get_cost(int root)
    {
        T cost = 0;
        priority_queue<Edge> pq;
        pq.push(Edge(root, 0));
        while (!pq.empty())
        {
            auto [u, curr_cost] = pq.top();
            pq.pop();
            // Checking for cycle
            if (marked[u])
                continue;
            marked[u] = true;
            cost += curr_cost;
            for (auto &[v, w] : adj[u])
            {
                if (!marked[v])
                    pq.push(Edge(v, w));
            }
        }
        return cost;
    }
};

void solve()
{
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