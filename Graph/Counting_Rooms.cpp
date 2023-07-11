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
    int n,m;
    cin>>n>>m;
    vector<string> room(n);
    for(int i=0;i<n;i++){
        cin>>room[i];
    }
    int vst[n+1][m+1];
    int ans =0;
    memset(vst,-1,sizeof(vst));
    queue<pii> qc;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vst[i][j] == -1 && room[i][j]=='.'){
                vst[i][j] = 1;
                qc.push(M_K(i,j));
                ans++;
                while(!qc.empty()){
                    int x = qc.front().F;
                    int y = qc.front().S;
                    qc.pop();
                    for(int k=0;k<4;k++){
                        int x_new = x + X[k];
                        int y_new = y + Y[k];
                        if(x_new >=0 && x_new<n && y_new>=0 && y_new<m && room[x_new][y_new] == '.' && vst[x_new][y_new] == -1) {
                            qc.push(M_K(x_new,y_new));
                            vst[x_new][y_new] = 1;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}