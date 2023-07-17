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
 const int INF = 1e9;
int X[] = {-1,1,0,0};
int Y[] = {0,0,1,-1};
vector<vector<int>> graph(100010);
vector<int> in(100010);
vector<int> vst(100010);
vector<int>parent(100010);
void dfs(int node){
    vst[node] = 1;
    for(auto ele:graph[node]){
        if(!vst[ele])dfs(ele);
    }
}


void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        graph[a].p_b(b);
        in[b]++;
    }
    dfs(1);
    if(vst[n] == 0){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    parent[1] = -1;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i] == 0)q.push(i);
    }
    vector<int> dist(n+1, -1);
    dist[1] =0 ;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto ele:graph[node]){
            if(dist[node] != -1 && dist[ele] < dist[node] + 1){
                dist[ele] = dist[node] + 1;
                parent[ele] = node;
            }
            in[ele]--;
            if(in[ele] == 0)q.push(ele);
        }
    }
    vector<int> ans;
    int node = n;
    while(node!= -1){
        ans.push_back(node);
        node = parent[node];
    }
    cout<<dist[n] + 1<<endl;
    for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
   
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}