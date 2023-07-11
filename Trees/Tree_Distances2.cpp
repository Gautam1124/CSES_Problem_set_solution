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
vector<vector<int>> graph(200010);
vector<ll> depth(200010);
vector<vector<ll>> node_num(200010);
ll sum_ans[200010];

pii built_depth(int node,int par,int h){
    depth[node] = h;
    int ans = 0 ;
    int nodes =0;
    for(auto ele:graph[node]){
        if(ele != par){
            pii ret = built_depth(ele,node,h+1);
            node_num[node].p_b(ret.S);
            nodes += ret.S;
        }
    }
    return M_K(1+ ans,1+ nodes);

}

void find_depth(int node,int par,ll par_sum,ll par_nodes){
    ll ans =0;
    if(node == 1){
        ans = par_sum;
    }else{
        ll tot_node =0;
        for(auto ele : node_num[node]){
            tot_node += ele;
        }
        ans = par_sum + par_nodes - tot_node;
    }
    sum_ans[node] = ans;
    vector<ll> prefix;
    vector<ll> suffix;

    for(int i=0;i<node_num[node].size();i++){
        prefix.p_b(node_num[node][i]);
        suffix.p_b(node_num[node][i]);
    }
    for(int i=1;i<prefix.size();i++){
        prefix[i] += prefix[i-1];
    }
    for(int i=suffix.size() - 2 ;i>=0;i--){
        suffix[i] += suffix[i+1];
    }
    int cn =0;
    for(auto ele:graph[node]){
        if(ele != par){
            ll pre = cn==0 ? 0 : prefix[cn - 1];
            ll suf = cn==suffix.size() - 1 ? 0 : suffix[cn + 1];
            ll put = par_nodes;
            if(node != 1)put += 1;
            put += pre + suf;
            find_depth(ele,node,ans,put);
            cn++;
        }
    }
}



void solve(){
    int n;cin>>n;
    int n1,n2;
    for(int i=0;i<n-1;i++){
        cin>>n1>>n2;
        graph[n1].p_b(n2);
        graph[n2].p_b(n1);
    }
    built_depth(1,0,0);
    ll depth_1 = 0;
    for(int i=2;i<=n;i++){
        depth_1 += depth[i];
    }
    // cout<<depth_1<<endl;
    find_depth(1,-1,depth_1,0);
    for(int i=1;i<=n;i++){
        cout<<sum_ans[i]<<" ";
    }
}




int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}