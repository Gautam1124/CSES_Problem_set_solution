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
    int n,m,k;
    cin>>n>>m>>k;
    vector<ll> v1;
    vector<ll> v2;
    ll ele;
    for(int i=0;i<n;i++){
        cin>>ele;
        v1.p_b(ele);
    }
    for(int i=0;i<m;i++){
        cin>>ele;
        v2.p_b(ele);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int count=0;
        vector<ll>::iterator sai = v1.begin();
        vector<ll>::iterator sbi = v2.begin();
    while(sai != v1.end() && sbi != v2.end()){
        if(*sai <= *sbi + k  && *sai >= *sbi - k){
            count++;
            sai++;
            sbi++;
        }else if(*sai > *sbi + k  ){
            sbi++;
        }else{
            sai++;
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