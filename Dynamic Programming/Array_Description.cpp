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
const int mod = 1e9 + 7;
 
int X[] = {-1,1,0,0};
int Y[] = {0,0,1,-1};

void solve(){
    int n,m;cin>>n>>m;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int dp[n+1][m+2];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
        dp[i][m+1] = 0;
    }
    for(int i=1;i<=m;i++){dp[1][i] = arr[1]==0 ? 1 : i==arr[1] ? 1 : 0;}

    for(int i=2;i<=n;i++){
        // cout<<"ching1";
        for(int j=1;j<=m;j++){
            // cout<<arr[i]<<endl;
            if(arr[i] != 0){
                if(arr[i]== j){
                    dp[i][j] = ((ll)dp[i-1][j] + (dp[i-1][j-1] + dp[i-1][j+1])%mod)%mod;
                }else{
                    dp[i][j] = 0;
                }
            }else{
                // cout<<"ching"<<endl;
                dp[i][j] = ((ll)dp[i-1][j] + (dp[i-1][j-1] + dp[i-1][j+1])%mod)%mod;
            }
        }
    }
    int ans =0;

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m+1;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=1;i<=m;i++)ans = (ans +  dp[n][i])%mod;
    
    cout<<ans<<endl;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}