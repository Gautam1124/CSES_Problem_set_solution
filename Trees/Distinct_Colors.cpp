//*********************Gautam Kumar|||||||||||||Hare Krishna****************

#include <bits/stdc++.h>
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
vector<int> colors(200010);
vector<vi> graph(200010);
set<int>*st_ptr[200010];
vector<int> res(200010);
int dfs(int node,int par){
    int mx = -1,mxnode;

    for(auto ele:graph[node]){
        if(ele != par){
            int a = dfs(ele,node);
            if(a>mx){
                mxnode = ele;
                mx = a;
            }
        }
    }
    if(mx == -1)st_ptr[node] = new set<int>();
    else st_ptr[node] = st_ptr[mxnode];

    st_ptr[node]->insert(colors[node]);
    for(auto ele: graph[node]){
        if(ele != par && ele != mxnode){
            for(int ele1 : *st_ptr[ele]){
                st_ptr[node]->insert(ele1);
            }
        }
    }
    res[node] = st_ptr[node]->size();
    return res[node];
}


void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>colors[i];

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        graph[a].p_b(b);
        graph[b].p_b(a);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++)cout<<res[i]<<" ";

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}