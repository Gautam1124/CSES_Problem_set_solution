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
vector<vi> graph(100010);
int vst[100010];
int par[100010];
int start,finish;

void dfs(int node,int parent){
    vst[node] = 1;
    for(auto ele: graph[node]){
        if(ele == parent)continue;
        if(vst[ele]== 0 ){
            par[ele] = node;
            dfs(ele,node);
            if(start)return;
        }else if(vst[ele] == 1){
            start = ele;
            finish = node;
            return;
        }
    }
    vst[node] = 2;
}



void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].p_b(b);
        graph[b].p_b(a);
    }
    for(int i=1;i<=n;i++){
        if(start)break;
        if(vst[i] == 0 ){
            dfs(i,-1);
        }
    }
    if(!start){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<int> ans;
    int node =finish ;
    while(node != start){
        ans.p_b(node);
        node = par[node];
    }
    int ns = ans.size();
    cout<<ns+2<<endl;
    cout<<start<<" ";
    for(int i=ns-1;i>=0 ;i--){
        cout<<ans[i]<<" ";
    }
    cout<<start<<endl;

}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}