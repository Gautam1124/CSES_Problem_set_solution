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

void solve(){
    int n,m;cin>>n>>m;
    vector<int> vec(n+1);
    for(int i=1;i<=n;i++){
        cin>>vec[i];
    }
    vector<int> mount(n+2);
    mount[0] = 0;
    mount[n+1] = n+1;
    for(int i=1;i<=n;i++){
        mount[vec[i]] = i;
    }
    int count = 1;
    int prev = mount[1];
    for(int i=2;i<=n;i++){
        if(mount[i] > prev){
            prev = mount[i];
        }else{
            count++;
            prev = mount[i];
        }
    }
    int a,b;
    while(m--){
        cin>>a>>b;
        int f1 = a, f2 = b;
        a = vec[a];
        b = vec[b];
        swap(vec[f1], vec[f2]);
        int init = 0;
        if(mount[a] < mount[a-1])init++;
        if(mount[a] > mount[a+1])init++;
        if(mount[b] < mount[b-1])init++;
        if(mount[b] > mount[b+1])init++;
        if(abs(a-b) == 1){
            int c = a < b ? a : b;
            if(mount[c] > mount[c+1])init--;
        }
        swap(mount[a],mount[b]);
        int ini=0;
        if(mount[a] < mount[a-1])ini++;
        if(mount[a] > mount[a+1])ini++;
        if(mount[b] < mount[b-1])ini++;
        if(mount[b] > mount[b+1])ini++;
        if(abs(a-b) == 1){
            int c = a < b ? a : b;
            if(mount[c] > mount[c+1])ini--;
        }
        count =  count - init + ini;
        cout<<count<<endl;

        

    }    
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}