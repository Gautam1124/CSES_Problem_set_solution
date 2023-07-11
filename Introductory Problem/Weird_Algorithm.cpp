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
    cout<<n<<" ";
    while(n!= 1){
        if(n%2 ==0 ){
            n /= 2;
            cout<<n<<" ";
        }else{
            n *= 3;
            n++;
            cout<<n<<" ";
        }
    }
    cout<<endl;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();

return 0;
}