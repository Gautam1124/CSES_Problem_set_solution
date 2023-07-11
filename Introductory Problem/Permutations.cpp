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
    int n;
    cin>>n;
    if(n<=3){
        if(n==1){
            cout<<1<<endl;
        }
        else{
        cout<<"NO SOLUTION"<<endl;
        }
        return;
    }
    int arr[n];
    int fs = n/2 + 1;
    int ss = 1;
    for(int i=n-1;i>=0; i-= 2){
        arr[i]= fs++;
    }
    for(int i=n-2;i>=0;i-=2){
        arr[i] = ss++;
    }
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}