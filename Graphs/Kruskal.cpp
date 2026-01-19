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


struct Edge
{
    int id, u, v;
    ll w; // [edge_index,to,from,cost]
    Edge() {}
    Edge(int Id, int U, int V, ll W) { this->id = Id, this->u = U, this->v = V, this->w = W; }
    bool operator<(const Edge &e) const { return w < e.w; }
};

struct MST
{
    vector<Edge> edges;
    vector<int> parent, rank, mst_edges;
    int n;
    int get_parent(int u) { return parent[u] == u ? u : parent[u] = get_parent(parent[u]); }
    void join(int u, int v)
    {
        u = get_parent(u);
        v = get_parent(v);
        if (u != v)
        {
            if (rank[u] < rank[v])
            {
                swap(u, v);
            }
            parent[v] = u;
            if (rank[u] == rank[v])
            {
                rank[u]++;
            }
        }
    }
    MST(int n, const vector<Edge> &edges) : n(n), edges(edges)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        iota(all(parent), 0);
        sort(all(edges));
    }
    pair<ll, vector<int>> process()
    {
        ll cost = 0;
        for (Edge &e : edges)
        {
            if (get_parent(e.u) != get_parent(e.v))
            {
                cost += e.w;
                join(e.u, e.v);
                mst_edges.push_back(e.id);
            }
        }
        return {cost, mst_edges};
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