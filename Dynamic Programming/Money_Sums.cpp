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
int dp[100001];

void solve(){
    int n;cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=100001 - vec[i];j>= 0;j--){
           if(dp[j])dp[j + vec[i]] = 1;
        }
    }
    vector<int> ans;
    for(int i=1;i<100001;i++){
        if(dp[i])ans.p_b(i);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
} 