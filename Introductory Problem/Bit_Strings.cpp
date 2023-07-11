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
ll dp[1000010];

ll find_dp(int val,int n){
    if(n==0)return 1;
    if(n==1)return val%mod;
    if(dp[n] != 0)return dp[n]%mod;
    if(n%2==0)return dp[n] = ((find_dp(val,n/2)%mod)*(find_dp(val,n/2)%mod))%mod;
    if(n%2==1)return dp[n] = (2*((find_dp(val,n/2)%mod)*(find_dp(val,n/2)%mod))%mod)%mod;

}


void solve(){
    int n;cin>>n;
    ll ans = find_dp(2,n);
    cout<<ans<<endl;

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}