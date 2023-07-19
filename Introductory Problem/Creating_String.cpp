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
map<int,int> m;
string str;
string dum;
set<string> sets;
void permute(int ind, int n){
    if(ind == n){
        sets.insert(dum);
        return;
    }
    for(int i=0;i<n;i++){
        if(m[str[i] - 'a']>0){
            dum.push_back(str[i]);
            m[str[i] - 'a']--;
            permute(ind + 1 , n);
            dum.pop_back();
            m[str[i] - 'a']++;
        }
    }
}


void solve(){
    cin>>str;
    int n = str.size();
    for(int i=0;i<n;i++){
        m[str[i] - 'a']++;
    }
    permute(0,n);
    cout<<sets.size()<<endl;
    for(auto it = sets.begin();it != sets.end();it++){
        cout<<*it<<endl;
    }



}



int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}