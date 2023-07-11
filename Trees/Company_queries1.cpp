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

void solve(){
    int n,q;cin>>n>>q;
    int dp[n+10][41];
    memset(dp,-1,sizeof(dp));
    int boss;
    for(int i=2;i<=n;i++){
        cin>>boss;
        dp[i][0] = boss;
    }
    for(int i=1;i<=40;i++){
        for(int j=1;j<=n;j++){
            if(dp[j][i-1] != -1)dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b;
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
        cout<<par<<endl;
    }
}



int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}