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
    ll mult = 1;
    int ans = 0;
    int final = 0;
    while(n>=5){
        if(n>= 5*mult){
            mult *= 5;
            ans *= 5;
            ans += 1;
        }else{
            // cout<<mult<<" "<<ans<<" "<<n<<endl;
            int m = n/mult;
            
            final += ans*m;
            n -= mult*m;
            ans -= 1 ;
            ans /= 5;
            mult /= 5;

            
        }
    }
    cout<<final<<endl;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}