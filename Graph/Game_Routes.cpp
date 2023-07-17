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

const int mod = 1e9 + 7;
vector<vi> graph(100010);
vi in(100010);

void solve(){
    int n,m;cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].p_b(b);
        in[b]++;
    }
    vector<ll> ways(100010,0);
    ways[1] = 1;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i] == 0)q.push(i);
    }
    while(!q.empty()){
        int node = q.front();q.pop();
        for(auto ele:graph[node]){
            if(ways[node] != 0){
                ways[ele] = (ways[ele] +  ways[node])%mod;
            }
            in[ele]--;
            if(in[ele] == 0){
                q.push(ele);
            }
        }
    }
    cout<<ways[n]%mod<<endl;

    
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}