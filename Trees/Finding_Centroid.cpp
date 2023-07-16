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
vector<vi> graph(200010);
// vector<int> node_num(200010);
vector<vi> node_child_num(200010);
int ans;
int dfs(int node,int par){
    int ans = 0;
    for(auto ele: graph[node]){
        if(ele != par){
            int val = dfs(ele,node);
            node_child_num[node].p_b(val);          
            ans += val;
        }
    }
    return  1 + ans;

}
void find_ans(int node,int par,int par_num,int mx_val){
    if(par_num <= mx_val){
        int check = 1;
        for(auto ele: node_child_num[node]){
            if(ele > mx_val){
                check = 0;
                break;
            }
        }
        if(check == 1){
            ans = node;
            return;
        }
    }

    vector<int> prefix;
    vector<int> suffix;
    for(int ele : node_child_num[node]){
        prefix.p_b(ele);
        suffix.p_b(ele);
    }
    int sz = prefix.size();
    for(int i=1;i<sz;i++){
        prefix[i] += prefix[i-1];
    }
    for(int i=sz - 2;i>=0;i--){
        suffix[i] += suffix[i+1];
    }

    int ct = 0;
    for(auto ele : graph[node]){
        if(ele != par){
            int pre = ct==0 ? 0 : prefix[ct - 1];
            int suf = ct==sz-1 ? 0 : suffix[ct + 1];
            find_ans(ele,node,1 + pre + suf + par_num, mx_val);
            ct++;
        }
        
    }
}


void solve(){
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        graph[a].p_b(b);
        graph[b].p_b(a);
    }
    dfs(1,-1);
    // for(int i=1;i<=n;i++){
    //     for(auto ele:node_child_num[i]){
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }
    find_ans(1,-1,0,n/2);
    cout<<ans<<endl;

}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}