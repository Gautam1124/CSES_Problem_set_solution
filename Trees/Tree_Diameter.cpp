//*********************Gautam Kumar|||||||||||||Hare Krishna****************

#include <bits/stdc++.h>
#define F first
#define S second
#define p_b push_back
#define M_K make_pair
#define pii pair<int,int>
#define ll long long
using namespace std;
 
int X[] = {-1,1,0,0};
int Y[] = {0,0,1,-1};
vector<vector<int>> graph(200100);

int dfs(int node, int par,int &ans){

    priority_queue<int> pq;
    pq.push(0);
    pq.push(0);
    int i=0;
    for(auto ele: graph[node]){
        if(ele != par){
            int dep = dfs(ele,node,ans);
            if(-1* dep < pq.top()){
                pq.pop();
                pq.push(-1*dep);
            }            
        }
    }
    int dep1 = -1*pq.top(); pq.pop();
    int dep2 = -1*pq.top(); pq.pop();
    if(dep1 + dep2  > ans)ans = dep1 + dep2 ;

    return 1 + max(dep1,dep2);
}


void solve(){
    int n;
    cin>>n;
    int n1,n2;
    for(int i =0;i<n-1;i++){
        cin>>n1>>n2;
        graph[n1].p_b(n2);
        graph[n2].p_b(n1);
    }
    int ans =0;
    int ans1 = dfs(1,-1,ans);
    cout<<ans<<endl;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}