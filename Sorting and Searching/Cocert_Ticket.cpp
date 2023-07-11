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
    multiset<int>ms;
    int n,m;cin>>n>>m;
    int ele;
    for(int i=0;i<n;i++){
        cin>>ele;
        ms.insert(-1*ele);
    }
    for(int i=0;i<m;i++){
        cin>>ele;
        auto it = ms.lower_bound(-1*ele);
        if(it == ms.end()){
            cout<<-1<<endl;
        }else{
            cout<<(*it)*-1<<endl;
            ms.erase(it);
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