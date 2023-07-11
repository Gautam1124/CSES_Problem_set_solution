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
    int A[2], B[2];
    for(int i=0; i<n;i++){
        cin>>room[i];
        for(int j=0;j<m;j++){
            if(room[i][j]=='A')A[0] = i , A[1] = j;
            if(room[i][j]=='B')B[0] = i , B[1] = j;
        }
    }

    char vst[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)vst[i][j] = '0';
    }
    queue<pii> qc;
    qc.push(M_K(A[0],A[1]));
    vst[A[0]][A[1]] = 'S';
    while(!qc.empty()){
        int x = qc.front().F;
        int y = qc.front().S;
        qc.pop();
        for(int k=0;k<4;k++){
            int x_new = x + X[k];
            int y_new = y + Y[k];
            if(x_new >=0 && x_new < n && y_new >=0 && y_new < m && vst[x_new][y_new]=='0' && (room[x_new][y_new]== '.' || room[x_new][y_new]=='B')){
                vst[x_new][y_new] = k==0 ? 'U' : k==1 ? 'D' : k==2 ? 'R' : 'L';
                qc.push(M_K(x_new,y_new));
                if(x_new==B[0] && y_new==B[1]){
                    char st = vst[x_new][y_new];
                    int xc = x_new, yc = y_new;
                    vector<char> a;
                    while(st!= 'S'){
                        a.push_back(st);
                        if(st == 'L'){
                            yc++;
                        }else if(st == 'R'){
                            yc--;
                        }else if(st=='U'){
                            xc++;
                        }else{
                            xc--;
                        }
                        st = vst[xc][yc];

                    }

                    int n = a.size();
                    cout<<"YES"<<endl;
                    cout<<n<<endl;
                    for(int i=n-1;i>=0;i--)cout<<a[i];

                    cout<<endl;
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