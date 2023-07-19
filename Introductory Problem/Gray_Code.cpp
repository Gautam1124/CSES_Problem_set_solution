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

void print(int num,int n){
    for(int i=n-1;i>=0;i--){
        int x = num>>i & 1;
        cout<<x;
       
    }
}


void solve(){
    int n;cin>>n;
    int bsz = n;
    vector<int> vec;
    vec.p_b(0);
    vec.p_b(1);
    n--;
    int pos = 1;
    while( n>0){
        int sz = vec.size();
        for(int i= sz - 1;i>=0;i--){
            vec.p_b(vec[i] | 1<<pos);
        }
        pos++;
        n--;
    }
    int sz = vec.size();
    for(int i=0;i<sz;i++){
        print(vec[i], bsz);
        cout<<endl;
    }

}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}