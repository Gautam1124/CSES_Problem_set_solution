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
int vst[100010];

void solve(){
    int n,m;cin>>n>>m;
    vector<vi> graph(n+1);
    int n1,n2;
    int team[n+1];
    for(int i=0;i<m;i++){
        cin>>n1>>n2;
        graph[n1].p_b(n2);
        graph[n2].p_b(n1);
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(vst[i]== 0){
            team[i] = 1;
            q.push(i);
            vst[i] = 1;
            while(!q.empty()){
                int index = q.front();
                q.pop();
                for(auto ele: graph[index]){
                    if(vst[ele] == 0){
                        q.push(ele);
                        vst[ele] = 1;
                        team[ele] = team[index]^1^2;
                    }else{
                        if(team[ele] == team[index]){
                            cout<<"IMPOSSIBLE"<<endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<team[i]<<" ";

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}