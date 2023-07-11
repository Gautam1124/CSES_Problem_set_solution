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
    int n,x;
    cin>>n>>x;
    vector<int> v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    sort(v1.begin(),v1.end());
    int s=0,e = n-1,count =0;
    while( s<e){
        if(v1[s] + v1[e] <= x){
            count ++;
            s++;
            e--;
        }else{
            count++;
            e--;
        }
    }
    if(s== e)count++;
    cout<<count<<endl;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
solve();

return 0;
}