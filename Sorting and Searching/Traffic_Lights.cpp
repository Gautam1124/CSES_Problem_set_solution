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
    int x,n;cin>>x>>n;
    multiset<int> ms;
    ms.insert(0);
    ms.insert(x);
    vector<int> vec;
    vector<int> element;
    for(int i=0;i<n;i++){
        int ele;cin>>ele;
        ms.insert(ele);
        vec.p_b(ele);
        element.p_b(ele);
    }
    vec.p_b(0);
    vec.p_b(x);
    sort(vec.begin(),vec.end());
    int mxdist = 0;
    int sz = vec.size();
    for(int i=0;i<sz - 1;i++){
        mxdist = max(mxdist, vec[i+1] - vec[i]);
    }
    vector<int> ans;
    ans.push_back(mxdist);
    for(int i=n-1;i>=0;i--){
        auto it1 = ms.lower_bound(element[i]);
        auto it2 = ms.upper_bound(element[i]);
        auto it3 = it1;
        it1--;
        mxdist = max(mxdist, *it2 - *it1);
        ms.erase(it3);
        ans.p_b(mxdist);
    }
    for(int i=n-1;i>=0;i--)cout<<ans[i]<<" ";
    
    
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}