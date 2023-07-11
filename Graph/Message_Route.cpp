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
int vst[100010];

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>> graph(n+1);
    int n1,n2;
    int path[100010];
    for(int i=0;i<m;i++){
        cin>>n1>>n2;
        graph[n1].p_b(n2);
        graph[n2].p_b(n1);
    }
    queue<int> q;
    q.push(1);
    path[1] = -1;
    vst[1] = 1;
    vector<int> ans;
    while(!q.empty()){
        
        int index = q.front();
        q.pop();
        // cout<<index<<endl;
        for(auto ele: graph[index]){
            if(vst[ele]==0){
                q.push(ele);
                path[ele] = index;
                vst[ele] = 1;
                if(ele == n){
                    int ind=n;
                    while(ind != -1){
                        ans.push_back(ind);
                        ind = path[ind];
                    }
                    cout<<ans.size()<<endl;
                    for(int i=ans.size() - 1;i>=0;i--){
                        cout<<ans[i]<<" ";
                    }
                    return;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}