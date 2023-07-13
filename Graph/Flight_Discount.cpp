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

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<pii>> graph(n+1);
    vector<vector<pii>> rgraph(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].p_b(M_K(b,c));
        rgraph[b].p_b(M_K(a,c));
    }
    vector<ll> dist(n+1,-1);
    vector<int> vst(n+1,0);
    dist[1] = 0;
    priority_queue<pair<long long,long long>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int node = pq.top().S;
        ll dis = pq.top().F;
        pq.pop();

        if(vst[node])continue;
        vst[node] = 1;
        for(auto ele: graph[node]){
            if(dist[ele.F] == -1 || dist[ele.F] > (ll)dist[node] + (ll)ele.S ){
                dist[ele.F] = (ll)(dist[node] + (ll)ele.S);
                pq.push({-1* dist[ele.F],ele.F});
            }
        }

    }

    vector<ll> rdist(n+1,-1);
    vector<int> rvst(n+1,0);
    priority_queue<pair<long long,long long>> rpq;
    rdist[n] = 0;
    rpq.push({0,n});
    while(!rpq.empty()){
        int node = rpq.top().S;
        int dis = rpq.top().F;
        rpq.pop();
        if(rvst[node])continue;
        rvst[node] = 1;
        for(auto ele:rgraph[node]){
           
            if(rdist[ele.F] == -1 || rdist[ele.F] > (ll)((ll)rdist[node] + (ll)ele.S)){
                rdist[ele.F] = (ll)(rdist[node] + (ll)ele.S);
                rpq.push({-1*rdist[ele.F], ele.F});
            }
        }
    }
    
    ll ans = LONG_LONG_MAX;
    for(int i=1;i<=n;i++){
        for(auto ele: graph[i]){
            int f = i, s = ele.F , val = ele.S;
            if(dist[f] == -1 || rdist[s] == -1)continue;
            ans = min(ans, val/2 + dist[f] + rdist[s]);
        }
    }
    cout<<ans<<endl;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}