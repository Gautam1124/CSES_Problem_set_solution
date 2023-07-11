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
    int n,x;cin>>n>>x;
    vector<int> price(n);
    vector<int> pages(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    int dp[2][x+1];
    memset(dp,0,sizeof(dp));
    int start = 0;
    for(int i=0;i<=x;i++){
        dp[start][i] = 0;
    }
    start = start^0^1;
    dp[start][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            if(j>= price[i]){
                dp[start][j] = max(dp[start^1][j-price[i]] + pages[i], dp[start^1][j]);
            }else{
                dp[start][j] = dp[start^1][j];
            }
        }
        start = start^1;
    }
    start = start^1;
    int ans = max(dp[start][x] , dp[start^1][x]);
    cout<<ans<<endl;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}