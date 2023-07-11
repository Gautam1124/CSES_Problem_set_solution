//*********************Gautam Kumar|||||||||||||Hare Krishna****************

#include <bits/stdc++.h>
#define F first
#define S second
#define p_b push_back
#define M_K make_pair
#define pii pair<int, int>
#define ll long long
#define vi vector<int>
using namespace std;

int X[] = {-1, 1, 0, 0};
int Y[] = {0, 0, 1, -1};
vector<vector<pair<ll, ll>>> graph(100010);
vector<bool> vst(100010);
ll dist[100010];

void solve()
{
    int n, m;
    cin >> n >> m;
    ll a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].p_b(M_K(b, c));
    }
    // memset(dist, -1, sizeof(dist));
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    for (int i = 0; i <= n; i++)
        dist[i] = 1000000000LL * m + 1LL;
    dist[1] = 0;
    pq.push(M_K(0, 1));

    while (!pq.empty())
    {
        ll cost = pq.top().F;
        int node = pq.top().S;

        pq.pop();
        if (vst[node] == true)
            continue;
        vst[node] = true;
        for (auto ele : graph[node])
        {

            if (dist[ele.F] <= dist[node] + ele.S)
                continue;
            dist[ele.F] =  dist[node] + ele.S;
            pq.push(M_K(dist[ele.F], ele.F));
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}