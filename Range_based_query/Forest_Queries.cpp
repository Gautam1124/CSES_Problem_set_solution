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
int trie[1010][1010];
vector<string>forest(1010);


// can't use trie because the number of queries is 1e5 and to pass we need O(1) and search operation is never a O(1), by the way i am getting tle in one of the 3 test cases. Uses the prefix sum approach.
// void built_trie(int index,int x1,int y1,int x2,int y2){
//     if(x1 >x2 || y1 > y2)return;
//     if(x1==x2 && y1==y2){
//         if(forest[x1][y1] == '*'){
//             trie[index] = 1;
//         }else{
//             trie[index] = 0;
//         }
//         return;
//     }

//     int midx = (x1 + x2)/2;
//     int midy = (y1 + y2)/2;

//     built_trie(4*index,x1,y1,midx,midy);
//     built_trie(4*index + 1,midx+1,y1,x2,midy);
//     built_trie(4*index + 2,x1,midy+1,midx,y2);
//     built_trie(4*index + 3,midx + 1,midy + 1,x2,y2);
//     for(int i=0;i<4;i++)trie[index] += trie[4*index + i];
//     // cout<<"("<<x1<<","<<y1<<"), "<<"("<<x2<<","<<y2<<")==>"<<trie[index]<<endl;
// }

// int search(int index,int x1,int y1,int x2,int y2, int x1l,int y1l,int x2l,int y2l){
//     if(x1l > x2 || y1l > y2 || x2l < x1 || y2l < y1)return 0;
//     if(x1 >= x1l && x2<= x2l && y1 >= y1l && y2l >= y2){
//         return trie[index];
//     }
//     int midx = (x1 + x2)/2;
//     int midy = (y1 + y2)/2;

//     int s1 = search(4*index,x1,y1,midx,midy,x1l,y1l,x2l,y2l);
//     int s2 = search(4*index + 1,midx+1,y1,x2,midy,x1l,y1l,x2l,y2l);
//     int s3 = search(4*index + 2,x1,midy+1,midx,y2,x1l,y1l,x2l,y2l);
//     int s4 = search(4*index + 3,midx + 1,midy + 1,x2,y2,x1l,y1l,x2l,y2l);
//     return s1 + s2 + s3 + s4;
    
// }

// void solve(){
//     int n,q;cin>>n>>q;
//     for(int i=0;i<n;i++){
//         cin>>forest[i];
//     }
//     built_trie(1,0,0,n-1,n-1);
//     while(q--){
//         int a,b,c,d;
//         cin>>a>>b>>c>>d;
//         int ans = search(1,0,0,n-1,n-1,a-1,b-1,c-1,d-1);
//         cout<<ans<<endl;
//     }

// }


void solve(){
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>forest[i];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            trie[i][j] = forest[i-1][j-1] == '*' ? 1 : 0;
            trie[i][j] += trie[i][j-1];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)trie[i][j] += trie[i-1][j];
    }

    // for(int i =0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<trie[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int ans = trie[c][d] - trie[a-1][d] - trie[c][b-1] + trie[a-1][b-1];
        cout<<ans<<endl;
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}