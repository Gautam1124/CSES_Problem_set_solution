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
    int n,m;cin>>n>>m;
    bitset<31> b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans = min(ans,__builtin_popcount(b[i].to_ulong() ^ b[j].to_ulong()));
        }
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