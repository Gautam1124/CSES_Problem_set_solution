//*********************Gautam Kumar|||||||||||||Hare Krishna****************

#include <bits/stdc++.h>
#pragma GCC target("popcnt")
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
bitset<3005> bit[3005];

void solve(){
    int n;cin>>n;
    for(int i =0;i<n;i++)cin>>bit[i];

    ll count =0;
    ll ans =0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            count = (bit[i]&bit[j]).count();
            ans += (count*(count - 1));
        }
    }
    
    cout<<(ans>>1)<<endl;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}