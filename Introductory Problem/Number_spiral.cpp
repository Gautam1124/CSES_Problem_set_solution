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
    ll x,y;
    ll mx;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        mx = max(x,y);
        if(mx==1){
            cout<<1<<endl;
            continue;
        }
        ll mid = (mx-1)*(mx-1) + mx;
        ll sub;
        if(mx%2 == 0){
            sub = -1*(mid - x) + (mid - y);
        }else{
            sub = (mid - x) + -1*(mid - y);
        }
        cout<<mid + sub<<endl;
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}