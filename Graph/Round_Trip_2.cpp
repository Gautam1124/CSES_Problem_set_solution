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
vector<vi> graph(100010);
vector<int> vst(100010);
vector<int> parent(100010);
vector<int> ans;
bool done = false;
void dfs(int node, int par)
{
    vst[node] = -1;
    for (auto ele : graph[node])
    {
        if (vst[ele] == 0)
        {
            parent[ele] = node;
            dfs(ele, node);
            if (done)
                return;
        }
        else if (vst[ele] == -1)
        {
            ans.push_back(ele);
            int n = node;
            ans.push_back(n);
            while (n != ele)
            {
                n = parent[n];
                ans.p_b(n);
            }
            done = true;
            return;
        }
    }
    vst[node] = 1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].p_b(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vst[i] == 0)
        {
            parent[i] = -1;
            dfs(i, -1);
        }
        if (done)
            break;
    }
    if (ans.size() == 0)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}