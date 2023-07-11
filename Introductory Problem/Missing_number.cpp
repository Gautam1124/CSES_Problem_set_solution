//*********************Gautam Kumar|||||||||||||Hare Krishna****************

#include <bits/stdc++.h>
#define F first
#define S second
#define p_b push_back
#define M_K make_pair
#define pii pair<int,int>
#define ll long long
using namespace std;
 
int X[] = {-1,1,0,0};
int Y[] = {0,0,1,-1};

void solve(){
    ll n;
    cin>>n;
    ll xr = 0;
    for(int i=1;i<=n;i++){
        xr ^= i;
    }
    ll ele;
    for(int i=0;i<n-1;i++){
        cin>>ele;
        xr ^= ele;
    }
    cout<<xr<<endl;;

}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}