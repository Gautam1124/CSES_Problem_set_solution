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
const ll INF = 1e9*500;
int X[] = {-1,1,0,0};
int Y[] = {0,0,1,-1};

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    ll graph[n+10][n+10];
    for(int i=0;i<n+10;i++){
        for(int j=0;j<n+10;j++){
            graph[i][j] = INF;
        }
    }
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(graph[a][b] > c)graph[a][b] = c;
        if(graph[b][a] > c)graph[b][a] = c;
    }
    for(int i=0;i<=n;i++)graph[i][i] = 0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)graph[i][j] = 0;
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    int d,e;
    while(q--){
        cin>>d>>e;
        if(graph[d][e]==INF)cout<<-1<<endl;
        else cout<<graph[d][e]<<endl;
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}