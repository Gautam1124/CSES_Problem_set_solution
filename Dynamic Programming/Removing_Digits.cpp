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
    int x;
    cin>>x;
    if(x<10){cout<< 1<<endl; return;}
    vector<ll> vec(x+1,-1);
    int rem,ele;
    for(int i=1;i<10;i++)vec[i] =1 ;
    vec[0] = 0;
    for(int j = 10;j<=x;j++){
        ele = j;
        while(ele != 0){
            rem = ele%10;
            ele /= 10;
            if(rem !=0 && rem <= j){
                if(vec[j] == -1){
                    vec[j] = vec[j - rem] + 1;
                }else{
                    if(vec[j] > vec[j-rem] + 1)vec[j] = vec[j-rem] + 1;
                }
            }
        }
    }
    cout<<vec[x]<<endl;
    

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}