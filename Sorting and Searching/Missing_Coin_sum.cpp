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
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    
    sort(arr,arr + n);
    ll sum =0 ;
    for(int i=0;i<n;i++){
        if(arr[i]>sum + 1){
            cout<<sum+1<<endl;
            return;
        }else{
            sum += arr[i];
        }
    }
    cout<<sum+1<<endl;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}