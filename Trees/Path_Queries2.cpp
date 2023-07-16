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
vector<int> values(200010);
vector<vector<int>> graph(200010);
vector<int>level(200010);
vector<int>trie(1000010);
vector<int>start(200010);
vector<int>end_eul(200010);
vector<int>flat;
int timer =0;
int dp[200010][40];
void level_func(int node,int par,int cur_lvl){
    flat.p_b(node);
    level[node] = cur_lvl;
    start[node]=timer++;
    for(auto ele:graph[node]){
        if(ele!= par){
            dp[ele][0] = node;
            level_func(ele,node,cur_lvl + 1);
        }
    }
    flat.p_b(-1*node);
    end_eul[node] = timer++;
    return ;
}
void binary_lift(int n){
    dp[1][0] = -1;
    for(int i=1;i<40;i++){
        for(int j=1;j<=n;j++){
           if(dp[j][i-1] != -1) dp[j][i] = dp[dp[j][i-1]][i-1];
           else dp[j][i] = -1;
        }
    }
}

int level_up(int node,int level){
    // cout<<node<<"chims2"<<level<<endl;
    int ct = 0;
    while(level > 0){
        if(level & 1){
            node = dp[node][ct];
            // cout<<node<<"chims::"<<endl;
        }
        level = level>>1;
        if(node == -1)return -1;
        ct++;
    }
    return node;
}

int find_lca(int a,int b){
    int la = level[a];
    int lb = level[b];
    // cout<<la<<"chims "<<lb<<endl;
    if(la <lb)swap(a,b);
    int diff = abs(la- lb);
    a = level_up(a,diff);
    int l = 0;
    if(a==b)return a;
    for(int i=19;i>=0;i--){
        if(dp[a][i] != dp[b][i]){
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    int lca = level_up(a,1);

    return lca;

}

void built(int index,int l,int r){
    if(l>r)return;
    if(l==r){
        int mult = 1;
        if(flat[l]<0)mult = -1;
        trie[index] = mult*values[mult*flat[l]];
        return;
    }
    int mid = (l+r)/2;
    built(2*index,l,mid);
    built(2*index + 1,mid+1,r);
    trie[index] = max(trie[2*index], trie[2*index + 1]);
}
int search(int index,int l,int r,int lf,int rf){
    if(l>r || lf>r || rf<l){
        return 0;
    }
    if(l>=lf && r<=rf){
        return trie[index];}
    int mid = (l+r)/2;
    int m1 = search(2*index,l,mid,lf,rf);
    int m2 = search(2*index + 1,mid + 1,r,lf,rf);
    return max(m1,m2);
}
void update(int index,int l,int r,int k,int val){
    if(l>k || k>r)return;
    if(l==r && l==k){
        trie[index] = val;
        return;
    }
    int mid = (l+r)/2;
    update(2*index,l,mid,k,val);
    update(2*index + 1,mid+1,r,k,val);
    trie[index] = max( trie[2*index] , trie[2*index + 1]);
}

void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)cin>>values[i];

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        graph[a].p_b(b);
        graph[b].p_b(a);
    }
    level_func(1,-1,0);
    binary_lift(n);
    cout<<endl;
    built(1,0,2*n - 1);

    while(m--){
        int a,b,c;
        cin>>a;
        if(a==2){
            cin>>b>>c;
            int lca = find_lca(b,c);

            int ans = max(search(1,0,2*n - 1,start[lca], start[a]), search(1,0,2*n-1,start[lca],start[b]));
            cout<<ans<<endl;
        }else{
            cin>>b>>c;
            update(1,0,2*n - 1, start[b], c);
            update(1,0,2*n - 1, end_eul[b], -1*c);

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