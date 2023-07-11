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
vector<string>graph(1010);
int infected[1010][1010];
map<pii,pii>parent;
pii start;
int n,m;
bool is_valid(int p,int q,int timer){
    if(p>=0 && p<n && q>=0 && q<m && graph[p][q] == '.'){
        if(infected[p][q]  > timer)return true;
    }
    return false;
}



void solve(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            infected[i][j] = 1e6;
        }
    }
    queue<pair<pii,int>>monster_move;
    queue<pair<pii,int>>A_move;
    for(int i=0;i<n;i++){
        cin>>graph[i];
        for(int j=0;j<m;j++){
            if(graph[i][j] == 'M'){infected[i][j] = 0;monster_move.push({{i,j},0});}
            if(graph[i][j] == 'A')start = M_K(i,j);      
        }
    }
    int timer =0;

    while(!monster_move.empty()){
        int x = monster_move.front().F.F;
        int y = monster_move.front().F.S;
        int time = monster_move.front().S;
        if(infected[x][y] < time)continue;
        monster_move.pop();
        for(int k=0;k<4;k++){
            int x_c = x + X[k];
            int y_c = y + Y[k];
            if(x_c >=0 && x_c < n && y_c >=0 && y_c < m && graph[x_c][y_c]=='.'){
                if(infected[x_c][y_c] > time + 1){
                    infected[x_c][y_c] = time + 1;
                    monster_move.push(M_K(M_K(x_c,y_c),time + 1));
                }
            }
        }
    }
    parent[start] = {start};
    int sx = start.F;
    int sy = start.S;
    if(sx == 0 || sx == n-1 || sy==0 || sy==m-1){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return;
    }
    A_move.push({start,0});
    while(!A_move.empty()){
        int x = A_move.front().F.F;
        int y = A_move.front().F.S;
        int time = A_move.front().S;
        A_move.pop();
        for(int k=0;k<4;k++){
            int x_c = x + X[k];
            int y_c = y + Y[k];
            if(M_K(x_c,y_c) == parent[{x,y}])continue;
            if(is_valid(x_c,y_c,time + 1)){
                parent[M_K(x_c,y_c)]= M_K(x,y);
                infected[x_c][y_c] = time + 1;
                A_move.push(M_K(M_K(x_c,y_c),time + 1));
                
                if(x_c == 0 || x_c == n-1 || y_c == 0 || y_c == m-1){
                    vector<char> ans;
                    int xc= x_c,yc=y_c;
                    int xcp = x, ycp = y;
                    while(xc != xcp || yc != ycp){
                        int bal = 2*(xc - xcp) + (yc - ycp);
                        char val = bal==2 ? 'D' : bal== -2 ? 'U' : bal == 1 ? 'R' : 'L' ; 
                        ans.push_back(val);
                        xc = xcp;
                        yc = ycp;
                        xcp = parent[{xc,yc}].F;
                        ycp = parent[{xc,yc}].S;
                    }
                    cout<<"YES"<<endl;
                    cout<<ans.size()<<endl;
                    for(int i=ans.size()-1;i>=0;i--){
                        cout<<ans[i];
                    }
                    return;

                }
            }
        }

    }
    cout<<"NO"<<endl;


}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}