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
const ll NINF = -1*(INF);
int X[] = {-1,1,0,0};
int Y[] = {0,0,1,-1};

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<pii>> graph(n+1);
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        graph[a].p_b(M_K(b,-1*c));
    }
    if(n == 1){
        // cout<<graph[1][0].S<<endl;
        if(-1*graph[1][0].S <= 0){
            cout<<-1*graph[1][0].S<<endl;
        }else{
            cout<<-1<<endl;
        }
        return;

    }
    ll dist[n+1];
    for(int i=0;i<=n;i++){
        dist[i] = INF;
    }
    dist[1] = 0;
    int count = n-1;
    while(count--){
        for(int i=1;i<=n;i++){
            for(auto ele:graph[i]){

                if(dist[i] != INF && dist[ele.F] > dist[i] + ele.S){
                    dist[ele.F] = dist[i] + ele.S;
                }
            }
        }
    }
    // cout<<dist[4]<<endl;
    int check = 0;
    for(int i=1;i<=n;i++){
        for(auto ele:graph[i]){
            if( dist[ele.F] != NINF && dist[i] != INF && dist[ele.F] > dist[i] + ele.S){
                dist[ele.F] = NINF;
                check = 1;
            }
        }
    }
    if(check == 0){
        cout<<-1*dist[n]<<endl;
        return ;
    }
    count = n-2;
    while(count--){
        for(int i=1;i<=n;i++){
            for(auto ele:graph[i]){
                if(dist[ele.F] != NINF && dist[i] != INF && dist[ele.F] > dist[i] + ele.S ){
                    dist[ele.F] = NINF;
                }
            }
        }
    }
    if(dist[n] == NINF){
        cout<<-1<<endl;
    }else{
        cout<<-1*dist[n]<<endl;
    }

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}