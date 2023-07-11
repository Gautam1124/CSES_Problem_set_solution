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
int dp[200010][41];
int level[200010];
vector<vi> tree(200010);
int n,q;

void level_find(int node,int par,int curr_level){
    level[node] = curr_level;
    dp[node][0] = par;
    for(auto ele: tree[node] ){
        if(ele != par){
            level_find(ele,node,curr_level + 1);
        }
    }
}



void solve(){
    cin>>n>>q;
    memset(dp,-1,sizeof(dp));
    int n1,n2;
    for(int i=2;i<=n;i++){
        cin>>n1>>n2;
        tree[n1].p_b(n2);
        tree[n2].p_b(n1);
    }
    level_find(1,-1,0);
    for(int i=1;i<=40;i++){
        for(int j=1;j<=n;j++){
            if(dp[j][i-1] != -1)dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }

   
}
int level_up(int a,int b){
        int par = a;
        int ct =0;
        while(b>0){
            if(ct >40)break;
            if(b&1){
                par = dp[par][ct];
            }
            b = b>>1;
            ct++;
            if(par == -1)break;

        }
    return par;
}

void find_ans(){
    solve();
    while(q--){
        int a,b,c;
        cin>>a>>b;
        if(level[a] < level[b])swap(a,b);
        int diff = level[a] - level[b];
        c = a;
        a = level_up(a,diff);
        int lca;
        if(a==b){
            lca = a;
        }else{
            int a1= a,b1 = b;
            for(int i=19;i>=0;i--){
                if(dp[a1][i] != dp[b1][i]){
                    a1 = dp[a1][i];
                    b1= dp[b1][i];
                }
            }
            lca = level_up(a1,1);
        }
        int ans = level[c] + level[b] - 2*level[lca];
        cout<<ans<<endl;

    }


}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 find_ans();
return 0;
}