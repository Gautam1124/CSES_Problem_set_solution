//*********************Gautam Kumar|||||||||||||Hare Krishna****************

#include <bits/stdc++.h>
#define F first
#define S second
#define p_b push_back
#define M_K make_pair
#define pii pair<int,int>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
int X[] = {-1,1,0,0};
int Y[] = {0,0,1,-1};
int trie[1000005][26];
int endnote[1000005];
int dp[5001];
int current=0;
void insert(string x){
    int n = x.size();
    int curr =0;
    for(int i=0;i<n;i++){
        if(trie[curr][x[i] - 'a'] == 0)trie[curr][x[i] - 'a']= ++current;
        curr = trie[curr][x[i] - 'a'];
        if(i==n-1){
            endnote[curr] = 1;
        }
    }
}

void solve(){
    string s1;
    cin>>s1;
    int m;cin>>m;
    string x;
    for(int i=0;i<m;i++){
        cin>>x;
        insert(x);
    }

    int n= s1.size();
    dp[n] = 1;
    for(int i= n-1;i>=0;i--){
        int curr =0;
        int ans =0;
        for(int j=i;j<n;j++){
            if(trie[curr][s1[j] - 'a'] == 0)break;
            curr = trie[curr][s1[j] - 'a'];
            if(endnote[curr]==1){
                ans = (ans%mod + dp[j+1]%mod)%mod;
            }
        }
        dp[i] = ans%mod;
    }
    cout<<dp[0]<<endl;

}




int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}