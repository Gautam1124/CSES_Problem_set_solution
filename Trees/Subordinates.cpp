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

void solve(){
    int n;cin>>n;
    vector<vector<int>> tree(n+1);
    int node;
    for(int i=2;i<=n;i++){
        cin>>node;
        tree[node].push_back(i);
    }
    vector<int> ans(n+1,0);
    stack<int>forw ;
    stack<int>bac ;
    forw.push(1);
    while(!forw.empty()){
        int no = forw.top();
        forw.pop();
        bac.push(no);
        for(auto ele : tree[no]){
            forw.push(ele);
        }
    }
    while(!bac.empty()){
        int no = bac.top();
        bac.pop();
        for(auto ele : tree[no]){
            ans[no] += ans[ele] + 1;
        }

    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" "; 
    }
    cout<<endl;
}



int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}