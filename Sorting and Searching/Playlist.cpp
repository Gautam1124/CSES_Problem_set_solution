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

    map<int,int> m;
    int count = 0,mxcount = 0,indstr = 0;
    for(int i=0;i<n;i++){
        if(m.find(arr[i]) == m.end()){
            m[arr[i]] = i;
        }else{
            if(m[arr[i]] >= indstr ){
                mxcount = max(mxcount,i - indstr );
                indstr = m[arr[i]] + 1;
                m[arr[i]] = i;
            }else{
                m[arr[i]] = i;
            }
        }
    }
    mxcount = max(mxcount,n - indstr);
    cout<<mxcount<<endl;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}