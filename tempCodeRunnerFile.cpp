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


int getMinLength(vector<int> arr, int k){
    int ans1 = INT_MAX;
    long long mult = arr[0];
    int count1 =1;
    int n = arr.size();
    for(int i=1;i<n;i++){
        if(mult * arr[i] <= k){
            mult *= arr[i];
        }else{
            count1++;
            mult = arr[i];
        }
    }
    int count2 = 1;
    mult = arr[arr.size() - 1];
    for(int i=arr.size() - 2;i>=0;i--){
        if(mult*arr[i] <= k ){
            mult *= arr[i];
        }else{
            count2 ++;
            mult = arr[i];
        }
    }
    ans1 = min(count1,count2);
    cout<< ans1;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;cin>>n;
vector<int> in(n);
for(int i=0;i<n;i++)cin>>in[i];

int k;cin>>k;

getMinLength(in,k);

 
return 0;
}