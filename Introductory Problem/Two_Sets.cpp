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
    vector<int>ans;
    if(n%4==1 || n%4==2){cout<<"NO"<<endl; return;}
    else if(n%4==3){
        for(int i=1;i<=(n+1)/4;i++)ans.push_back(i);
        ans.push_back((n+1)/2);
        for(int i=n-((n+1)/4 - 1) + 1;i<=n;i++)ans.push_back(i);
    }else{
        for(int i=1;i<=(n)/4;i++)ans.push_back(i);
        for(int i=n- n/4 + 1;i<=n;i++)ans.push_back(i);
    }
    cout<<"YES"<<endl;
    int sz = ans.size();
    cout<<sz<<endl;;
    for(int i=0;i<sz;i++)cout<<ans[i]<<" ";
    cout<<endl<<n-sz<<endl;
    int pt=0;
    for(int i=1;i<=n;i++){
        if(ans[pt] != i){
            cout<<i<<" ";
        }else{
            pt++;
        }
    }

}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}