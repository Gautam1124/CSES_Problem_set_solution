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
const int mod = 1e9 + 7;
 
int X[] = {-1,1,0,0};
int Y[] = {0,0,1,-1};
int num_path[1010][1010];
void solve(){
    int n;cin>>n;
    vector<string> vs(n);
    for(int i=0;i<n;i++){
        cin>>vs[i];
    }
    if(vs[0][0] == '*'){
        cout<<0<<endl;
        return;
    }
    num_path[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vs[i][j] == '*')continue;
            int x[] = {i-1,i};
            int y[] = {j,j-1};
            for(int k=0;k<2;k++){
               if(x[k] >=0 && x[k] < n && y[k]>=0 && y[k]<n) num_path[i][j] = (num_path[i][j] + num_path[x[k]][y[k]]%mod)%mod ;
            }
        }
    }
    cout<<num_path[n-1][n-1]<<endl;
}



int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}