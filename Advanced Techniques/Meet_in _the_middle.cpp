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
ll arr[50];
vector<int> vec[2];
void subset(int i,int n,int sum,int val){
    if(i>=n)vec[val].push_back(sum);
    subset(i + 1, n, sum + arr[i],val);
    subset(i + 1, n, sum,val);
}

void solve(){
    int n,x;cin>>x;
    for(int i=0;i<n;i++)cin>>arr[i];
    
    subset(0,n/2 + 1, 0,0);
    subset(n/2 + 1,n,0,1);
    int count = 0;
    for(auto ele1 : vec[0]){
        for(auto ele2 : vec[1]){
            if(ele1 + ele2 == x)count++;
        }
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