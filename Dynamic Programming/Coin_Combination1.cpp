//*********************Gautam Kumar|||||||||||||Hare Krishna****************

#include <bits/stdc++.h>
#define F first
#define S second
#define p_b push_back
#define M_K make_pair
#define pii pair<int,int>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
 
int X[] = {-1,1,0,0};
int Y[] = {0,0,1,-1};

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    sort(coins.begin(),coins.end());
    vector<ll> vec(x+1,0);
    vec[0] = 1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(coins[j] > i)break;
            if(vec[i - coins[j]] >0)vec[i] = (vec[i] +  vec[i - coins[j]])%mod ;
        }
    }
    cout<<vec[x]<<endl;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}