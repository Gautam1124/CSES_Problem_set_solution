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
    int n;cin>>n;
    int s,e;
    vector<int> entry(n);
    vector<int> ext(n);
    for(int i=0;i<n;i++){
        cin>>entry[i]>>ext[i];
    }
    sort(entry.begin(),entry.end());
    sort(ext.begin(),ext.end());
    int count =0;
    int i=0,j=0;
    int ans =0 ;
    while(i<n && j<n){
        if(entry[i] < ext[j]){
            count++;
            i++;
        }else if(entry[i] > ext[j]){
            count--;
            j++;
        }else{
            i++;
            j++;
        }
        ans = max(ans,count);
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