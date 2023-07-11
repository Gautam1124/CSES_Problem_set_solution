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
    string s;
    cin>>s;
    int n = s.size();
    int presuff[n];
    memset(presuff,0,sizeof(presuff));
    presuff[0] = 0;
    int i = 1;
    int len =0;
    while(i<n){
        if(s[len] == s[i]){
            presuff[i] = ++len;
            i++;
        }else{
            if(len != 0){
                len = presuff[len - 1];
            }else{
                presuff[i] =0 ;
                i++;
            }
        }
    }
    vector<int>ans;
    int start = presuff[n-1];

    while(start != 0 ){
        ans.push_back(start) ;
        start = presuff[start - 1];
    }
    for(int j = ans.size() - 1;j>=0 ;j--){
        cout<<ans[j]<<" ";
    }
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}