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
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    multiset<int> ms;
    ms.insert(arr[0]);
    for(int i=1;i<n;i++){
        auto it = ms.upper_bound(arr[i]);
        if(it == ms.end()){
            ms.insert(arr[i]);
        }else{
            ms.erase(it);
            ms.insert(arr[i]);
        }
    }
    cout<<ms.size()<<endl;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}