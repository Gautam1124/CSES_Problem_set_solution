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
    vector<int> vec(n+1);
    for(int i=1;i<=n;i++){
        cin>>vec[i];
    }
    vector<int> mount(n+1);
    for(int i=1;i<=n;i++){
        mount[vec[i]] = i;
    }
    int count = 1;
    int prev = mount[1];
    for(int i=2;i<=n;i++){
        if(mount[i] > prev){
            prev = mount[i];
        }else{
            count++;
            prev = mount[i];
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