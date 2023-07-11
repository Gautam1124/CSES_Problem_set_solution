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

// The equation for the number of places in  which we can't place knight is 4*(n-1)(n-4) + 8(n-1) the equation came be divding the square into 6 parts the first part have dimension (n-2)*2 and second has (n-2)*(n-4) the first and third are same while fourth have the dimension of (2)*(2) ans the fifth have the dimension of 2*(n-4) the sixth is same as fourth.


void solve(){
    int n;cin>>n;
    for(int i =1;i<=n;i++){
        ll ans = (ll)4*(i-4)*(i-1) + (ll)8*(i-1);
        ans = ((ll)(i*i)*(i*i-1))/2 - ans;
        cout<<ans<<endl;
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}