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

vector<pii> ans;
void travel(int stack_num,int stack_des, int n){
    if(n==1){
        ans.push_back(M_K(stack_num, stack_des));
        return;
    }
    int mid = stack_num^stack_des^1^2^3;

    travel(stack_num,mid,n-1);
    ans.push_back(M_K(stack_num, stack_des));
    travel(mid, stack_des, n-1);
}


void solve(){
    int n;cin>>n;
    travel(1,3,n);
    cout<<ans.size()<<endl;
    for(auto ele: ans){
        cout<<ele.F<<" "<<ele.S<<endl;
    }
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}