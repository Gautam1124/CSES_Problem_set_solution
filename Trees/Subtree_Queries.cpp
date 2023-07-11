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
vector<vector<int>> adj(200010);
vector<ll> values(200010);
vector<int> flat;
vector<int> start(200010);
vector<int> subtree(200010);
vector<ll> trie(1000010);
int timer = 0;
int dfs(int node,int par){
    int ans =0;
    start[node] = timer++;
    flat.push_back(node);
    for(auto ele: adj[node]){
        if(ele != par){
            ans += dfs(ele,node);
        }
    }
    subtree[node] = 1 + ans;
    return subtree[node];
}

void built_trie(int index,int l,int r){
    if(l>r)return;
    if(l==r){
        trie[index] = values[flat[l]];
        return;
    }
    int mid = (l+r)/2;
    built_trie(2*index,l,mid);
    built_trie(2*index + 1,mid + 1,r);
    trie[index] = trie[2*index] + trie[2*index + 1];
    // cout<<l<<" "<<r<<"->>>>>"<<trie[index]<<endl;
}
void update_query(int index,int l,int r,int node,int value){
    if(l>node || r<node)return;
    if(l==r && l==node){
        trie[index] = value;
        return;
    }
    int mid = (l+r)/2;
    update_query(2*index,l,mid,node,value);
    update_query(2*index + 1,mid+1,r,node,value);
    trie[index] = trie[2*index] + trie[2*index + 1];
}

ll search_query(int index,int l,int r,int lf,int rf){
    // cout<<l<<" "<<r<<" "<<lf<<" "<<rf<<endl;
    if(l>rf || r<lf)return 0;
    if(lf<=l && rf>=r)return trie[index];

    int mid = (l+r)/2;
    ll s1 = search_query(2*index,l,mid,lf,rf);
    ll s2 = search_query(2*index + 1,mid + 1,r,lf,rf);
    return s1 + s2;
}


void solve(){
    int n,q;cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>values[i];
    }
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].p_b(b);
        adj[b].p_b(a);
    }
    dfs(1,-1);
    
    built_trie(1,0,n-1);

    while(q--){
        int a,b,c;
        cin>>a;
        if(a==1){
            cin>>b>>c;
            update_query(1,0,n-1,start[b],c);
        }else{
            cin>>b;
            ll ans = search_query(1,0,n-1,start[b] , start[b] + subtree[b] - 1);
            cout<<ans<<endl;
        }
    }

}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}