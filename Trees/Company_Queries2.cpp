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
    for(auto ele: tree[node] ){
        if(ele != par){
            level_find(ele,node,curr_level + 1);
        }
    }
}



void solve(){
    cin>>n>>q;
    memset(dp,-1,sizeof(dp));
    int boss;
    for(int i=2;i<=n;i++){
        cin>>boss;
        tree[boss].p_b(i);
        tree[i].p_b(boss);
        dp[i][0] = boss;
    }
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
    level_find(1,-1,0);
    while(q--){
        int a,b;
        cin>>a>>b;
        if(level[a] < level[b])swap(a,b);
        int diff = level[a] - level[b];
        a = level_up(a,diff);
        if(a==b){
            cout<<a<<endl;
            continue;
        }
        for(int i=19;i>=0;i--){
            if(dp[a][i] != dp[b][i]){
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        int ans = level_up(a,1);
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