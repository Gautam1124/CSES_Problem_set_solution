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
    int t;cin>>t;
    int a,b;
    while(t--){
        cin>>a>>b;
        if(a>b)swap(a,b);
        if((a+b)%3 != 0)cout<<"NO"<<endl;
        else{
            if(b>2*a)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}