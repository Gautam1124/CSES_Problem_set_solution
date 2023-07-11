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
    vector<pii> vec;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vec.p_b(M_K(b,a));
    }
    sort(vec.begin(),vec.end());
    int i=1;
    int count=1;
    int end = vec[0].F;
    while(i<n){
        if(vec[i].S >= end){
            count ++;
            end = vec[i].F;
        }
        i++;
    }
    cout<<count<<endl;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}