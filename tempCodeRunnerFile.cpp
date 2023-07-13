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
    vector<ll> fir(n);
    vector<ll> sec(n);
    vector<ll> su(n);
    int check = 0;
    for(int i=0;i<n;i++){
        cin>>fir[i];
        if(fir[i]>0)check=1;
    }
    for(int i=0;i<n;i++){
        cin>>sec[i];
        if(sec[i]>0)check = 1;
        su[i] = fir[i] + sec[i];
    }
    if(check == 0){
        cout<<0<<endl;
        return;
    }
    vector<int>start(n);
    vector<ll>subarr(n);
    start[0] = 0;
    subarr[0] = su[0];
    for(int i=1;i<n;i++){
        if(subarr[i-1] > 0){
            subarr[i] = subarr[i-1] + su[i];
            start[i] = start[i-1];
        }else{
            subarr[i] = su[i];
            start[i] = i;
        }
    }
    ll mx= subarr[0];
    ll mxi = 0;
    ll sti = start[0];
    for(int i=1;i<n;i++){
        if(subarr[i] > mx){
            mx = subarr[i];
            mxi = i;
            sti = start[i];
        }
    }
    ll m;
    ll ans = mx;

    if(fir[sti]*sec[sti] < 0 && fir[mxi]*sec[mxi] < 0){
       m = max(min(fir[sti],sec[sti]),min(fir[mxi],sec[mxi]));
       ans -= m;
    }
    // else if(fir[sti]*sec[sti] < 0){
    //     m = max(fir[sti], sec[sti]);
    //     ans -= m;
    // }else if(fir[mxi]*sec[mxi] < 0){
    //     m = max(fir[mxi], sec[mxi]);
    //     ans -= m;
    // }

    
    cout<<ans<<endl;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;cin>>t;
while(t--) solve();
return 0;
}