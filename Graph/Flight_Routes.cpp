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
const ll INF = 1e17;
int X[] = {-1,1,0,0};
int Y[] = {0,0,1,-1};
vector<vector<pair<ll,ll>>> graph(200010);

void solve(){
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].p_b({b,c});
    }
    vector<vector<ll>> dist(n+1,vector<ll>(k,INF));
    dist[1][0] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int node = pq.top().S;
        ll cost = pq.top().F;
        pq.pop();
        if(cost > dist[node][k-1])continue;
        for(auto ele:graph[node]){
            // cout<<ele.F<<"chign"<<endl;
            if(dist[ele.F][k-1] > cost + ele.S){
                dist[ele.F][k-1] = cost + ele.S;
                pq.push({dist[ele.F][k-1], ele.F});
                sort(dist[ele.F].begin(), dist[ele.F].end());
            }
        }
    }
    for(auto ele: dist[n]){
        cout<<ele<<" ";
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}