//*********************Gautam Kumar|||||||||||||Hare Krishna****************
// 1 2 2 3 4 4 5 5 3 1
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
vector<int> start(500000);
vector<int> end_node(500000);
vector<ll>trie(2000010);
vector<ll> flat;
int timer = 0;
void dfs(int node,int par){
    start[node] = timer++;
    flat.p_b(values[node]);

    for(auto ele:adj[node]){
        if(ele != par){
            dfs(ele,node);
        }
    }
    end_node[node] = timer++; 
    flat.push_back(-1*values[node]);
}

void built_trie(int index,int l,int r){
    if(l>r)return;
    if(l==r){
        trie[index] = flat[l];
        return ;
    }
    int mid = (l+r)/2;
    built_trie(2*index , l,mid);
    built_trie(2*index + 1,mid + 1,r);
    trie[index] = trie[2*index] + trie[2*index + 1];
}

void update_query(int index,int l,int r,int k,int val){
    if(l>k || k>r)return;
    if(l==r && l==k){
        trie[index] = val;
        return;
    }
    int mid = (l+r)/2;
    update_query(2*index,l,mid,k,val);
    update_query(2*index + 1,mid+1,r,k,val);
    trie[index] = trie[2*index] + trie[2*index + 1];
}

ll search_query(int index,int l,int r,int lf,int rf){
    if(l>rf || lf>r)return 0 ;
    if(lf <= l && r<= rf){
        return trie[index];
    }
    int mid = (l+r)/2;
    ll s1 = search_query(2*index,l,mid,lf,rf);
    ll s2 = search_query(2*index + 1,mid+1,r,lf,rf);
    return s1 + s2;
}



void solve(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>values[i];

    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].p_b(b);
        adj[b].p_b(a);
    }
    dfs(1,-1);
    // for(int i=0;i<=n ;i++)cout<<end_node[i]<<" ";
    built_trie(1,0,2*n - 1);
    while(q--){
        int a,b,c;
        cin>>a;
        if(a==1){
            cin>>b>>c;
            update_query(1,0,2*n-1,start[b],c);
            update_query(1,0,2*n-1,end_node[b],-1*c);
        }else{
            cin>>b;
            ll ans = search_query(1,0,2*n-1,0,start[b]);
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