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
    int a,b;cin>>a>>b;
    int dp[a+1][b+1];
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j)dp[i][j] = 0;
            else{
                int mi = INT_MAX;
               for(int k=1;k<=i/2;k++){
                mi = min(mi,dp[k][j] + dp[i-k][j]);
               }
               for(int k=1;k<=j/2;k++){
                mi = min(mi,dp[i][k]+ dp[i][j-k]);
               }
               dp[i][j] = 1 + mi;
            }
        }
    }
    cout<<dp[a][b]<<endl;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}