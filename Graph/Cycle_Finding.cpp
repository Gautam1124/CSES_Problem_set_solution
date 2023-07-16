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
vector<vector<pii>> graph(2600);
ll dist[2600];
vector<int> parent(2600);


void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].p_b({b,c});
    }

   
    int count = n;
    int x;
    while(count--){
        x = -1;
        for(int i=1;i<=n;i++){
            for(auto ele:graph[i]){
                if( dist[ele.F] > dist[i] + ele.S){
                    dist[ele.F] = dist[i] + ele.S;
                    parent[ele.F] = i;
                    x = ele.F;
                }
            }
        }
    }

    if(x==-1){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=1;i<n;i++){
        x = parent[x];
    }
    int tar = x;
    vector<int>ans;
    ans.push_back(x);
    x = parent[x];
    while(x!= tar){
        ans.push_back(x);
        x = parent[x];
    }
    ans.push_back(tar);
    cout<<"YES"<<endl;
    for(int i=ans.size() - 1;i>=0;i--)cout<<ans[i]<<" ";


}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}