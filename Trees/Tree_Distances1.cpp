//*********************Gautam Kumar|||||||||||||Hare Krishna****************

#include <bits/stdc++.h>
#define F first
#define S second
#define p_b push_back
#define M_K make_pair
#define pii pair<int, int>
#define ll long long
using namespace std;

int X[] = {-1, 1, 0, 0};
int Y[] = {0, 0, 1, -1};
vector<vector<int>> graph(200100);
vector<int> depth(200100);
vector<int> depth_ans(200100);
int find_depth(int node, int par)
{
    // cout<<" ching"<<endl;
    int ans = 0;
    // cout<<node<<" "<<par<<endl;
    for (auto ele : graph[node])
    {
        if (ele != par)
        {
            int x = find_depth(ele, node);
            ans = max(ans, x);
        }
    }
    depth[node] = ans;
    // cout<<depth[node]<<endl;
    return 1 + ans;
}

void find_all_depth(int node, int par, int par_ans)
{
    vector<int> prefix_max;
    vector<int> suffix_max;
    int a = -1;
    for (auto ele : graph[node])
    {
        if (ele != par){
            suffix_max.p_b(depth[ele]);
            prefix_max.p_b(depth[ele]);
        }
    }
    a = INT_MIN;
    for (int i = suffix_max.size() - 1; i >= 0; i--)
    {
        a = max(a, suffix_max[i]);
        suffix_max[i] = a;
    }
    a = INT_MIN;
    for(int i=0;i<prefix_max.size();i++){
        a = max(a,prefix_max[i]);
        prefix_max[i] = a;
    }
    // cout<<node<<" "<<par_ans<<endl;
    
    int ch_no = 0;
    // cout << node <<" "<<par_ans<< endl;
    for (auto ele : graph[node])
    {
        if (ele != par)
        {
            int p_mx = ch_no == 0 ? INT_MIN : prefix_max[ch_no - 1];
            int s_mx = ch_no == (suffix_max.size() - 1) ? INT_MIN : suffix_max[ch_no + 1];
            int par = 1 + max(par_ans, max(p_mx, s_mx));
            find_all_depth(ele, node, par);
            ch_no++;
        }
    }
    // cout<<par_ans<<endl;
        depth_ans[node] = 1 + max(prefix_max.empty() ? -1 : prefix_max.back() , par_ans);
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].p_b(b);
        graph[b].p_b(a);
    }
    int a = find_depth(1, -1);
    // for(int i=1;i<=n;i++){
    // cout<<"ching"<<" ";
    //     cout<<depth[i]<<endl;
    // }
    // cout<<depth[2]<<endl;
    find_all_depth(1, -1, -1);
    for (int i = 1; i <= n; i++)
    {
        cout << depth_ans[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}