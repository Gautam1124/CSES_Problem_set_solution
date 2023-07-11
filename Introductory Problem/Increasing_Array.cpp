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
    int n;cin>>n;
    ll prev,adv;
    cin>>prev;
    ll ans =0;
    for(int i=1;i<n;i++){
        cin>>adv;
        ans += adv - prev < 0 ? prev - adv : 0 ;
        prev = adv > prev ? adv : prev;
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