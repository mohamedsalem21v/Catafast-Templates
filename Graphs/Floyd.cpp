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

template <typename T = int, int Base = 0>
struct Floyd
{

    int n;
    vector<vector<T>> dist;

    Floyd(int _n = 0) : n(_n)
    {
        dist.assign(n + Base, vector<T>(n + Base, INF));
        for (int i = Base; i < n + Base; i++)
            dist[i][i] = 0; // self loops
    }

    Floyd(int _n, const vector<vector<T>> &D) : n(_n), dist(D) { build(); }

    T operation(T a, T b) { return min(a, b); }

    void add_edge(int u, int v, T w) { dist[u][v] = operation(dist[u][v], w); }

    void build()
    {
        for (int i = Base; i < n + Base; i++)
            for (int u = Base; u < n + Base; u++)
                for (int v = Base; v < n + Base; v++)
                    dist[u][v] = operation(dist[u][v], dist[u][i] + dist[i][v]);
    }

    T get_dist(int u, int v) { return dist[u][v]; }

    void update_dist(int u, int v, int a, int b)
    {
        dist[u][v] = operation(dist[u][v], dist[u][a] + dist[a][b] + dist[b][v]);
        dist[u][v] = operation(dist[u][v], dist[u][b] + dist[b][a] + dist[a][v]);
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