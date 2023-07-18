//*********************Gautam Kumar|||||||||||||Hare Krishna****************

#include <bits/stdc++.h>
#pragma GCC target("popcnt")

#define F first
#define S second
#define p_b push_back
#define M_K make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
using namespace std;
 
int X[] = {-1,1,0,0};
int Y[] = {0,0,1,-1};

vector<vi> graph(50010);
bitset<50010> bits[50010];
vector<int> vst(50010);
vector<int> ans(50010);

void dfs(int node){
    vst[node] = 1;
    for(auto ele: graph[node]){
        if(vst[ele] == 0){
            dfs(ele);
        }
        bits[node] |= bits[ele];
    }
    bits[node].set(node);
    ans[node] = bits[node].count();
    return;

}

void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        graph[a].p_b(b);
    }

    for(int i=1;i<=n;i++){
        if(vst[i] == 0){
            dfs(i);
        }
    }
    for(int i=1;i<=n;i ++)cout<<ans[i]<<" ";

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}