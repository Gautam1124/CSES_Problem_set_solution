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
    int n;cin>>n;
    ll arr[n];
    ll dp[n];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>arr[i];

    dp[0] = arr[0];
    for(int i=1;i<n;i++){
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
    }
    ll ans =LONG_LONG_MIN ;
    for(int i=0;i<n;i++){
        ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;

}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}