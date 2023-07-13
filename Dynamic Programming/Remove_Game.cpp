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
ll dp[2][5010][5010];
bool vst[2][5010][5010];
ll arr[5010];

ll find_mx(int s,int e);

ll find_mi(int s,int e){
        // cout<<s<<" "<<e<<endl;
    if(e-s == 1){
        return min(arr[s],arr[e]);
    }
    if(s>=e)return 0;
    if(vst[1][s][e] == true)return dp[1][s][e];
    ll ans = min( find_mx(s+1,e), find_mx(s,e-1));
    vst[1][s][e] = true;
    return dp[1][s][e] = ans;
}

ll find_mx(int s,int e){
    // cout<<s<<" "<<e<<endl;
    if(e-s == 1){
        return max(arr[s],arr[e]);
    }
    if(s>e)return 0;
    if(s==e)return arr[s];
    if(vst[0][s][e] == true )return dp[0][s][e];
    ll ans = max(arr[s] + find_mi(s+1,e), arr[e] + find_mi(s,e-1));
    vst[0][s][e] = true;
    return dp[0][s][e] = ans;

}



void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];


    ll ans = find_mx(1,n);
    cout<<ans<<endl;

}





int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}