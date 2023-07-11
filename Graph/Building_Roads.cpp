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
    // cout<<"ching"<<endl;
    for(int i=0;i<m;i++){
        cin>>n1>>n2;
        graph[n1].p_b(n2);
        graph[n2].p_b(n1);
    }
    vector<int>ans;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(vst[i]==0){
            ans.p_b(i);
            q.push(i);
            vst[i] = 1;
            while(!q.empty()){
                int ind = q.front();
                // cout<<ind<<endl;
                q.pop();
                for(auto ele:graph[ind]){
                    if(vst[ele]==0 && ele != ind){
                        vst[ele] = 1;
                        q.push(ele);
                    }
                }
            }
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=1;i<ans.size();i++){
        cout<<ans[i-1]<<" "<<ans[i]<<endl;
    }
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}