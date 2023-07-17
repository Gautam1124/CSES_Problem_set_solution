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
    vector<int> ans;
    multiset<int> ms;
    for(int i=1;i<=n;i++)ms.insert(i);
    auto it = ms.end();
    int check =0;
    while(!ms.empty()){
            it = ms.begin();
        if(check ==0 ){
            it++;
        }
        check = 1;
        for(it;it != ms.end();it++){
            ans.push_back(*it);
            auto it1 = it;
            it++;
            ms.erase(it1);
            if(it == ms.end()){
                check = 0;
                break;
            }

        }
    }
    for(auto ele: ans)cout<<ele<<" ";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}