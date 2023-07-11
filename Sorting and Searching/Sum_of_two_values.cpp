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
    int n,m;cin>>n>>m;
    int arr[n];
    map<int,int> ma;
    int check =0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(ma.find(m - arr[i]) != ma.end() && check==0){
            cout<<ma[m-arr[i]]+1<<" "<<i+1<<endl;
            check=1;
        }
        ma[arr[i]] = i;
    }
    if(check == 0){
        cout<<"IMPOSSIBLE"<<endl;
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}