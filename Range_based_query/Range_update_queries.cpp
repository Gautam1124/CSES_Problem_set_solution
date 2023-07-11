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
ll arr[200010];
ll trie[1000010];

void update(int index,int l,int r,int lf,int rf,ll update_value){
    // cout<<l<<" "<<r<<endl;
    if(l>r || l>rf || r< lf)return;
    if(l>=lf && r<=rf){
        trie[index] += update_value;
        return;
    }
    int mid = (l+r)/2;
    update(2*index,l,mid,lf,rf,update_value);
    update(2*index + 1,mid+1,r,lf,rf,update_value);
}
ll search(int index,int l,int r,int k){
    // cout<<l<<" "<<r<<endl;
    if(l>r || l>k || k>r)return 0;
    if(l==r)return trie[index];
    int mid = (l+r)/2;
    ll s1 = search(2*index,l,mid,k);
    ll s2 = search(2*index + 1,mid+1,r,k);
    return s1 + s2 + trie[index];
}


void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){cin>>arr[i];}
    int task,a,b,c,k;
    while(q--){
        cin>>task;
        if(task==1){
            cin>>a>>b>>c;
            update(1,0,n-1,a-1,b-1,c);
        }else{
            cin>>k;
            ll add_val = search(1,0,n-1,k-1);
            cout<<arr[k-1] + add_val<<endl;

        }
    }


}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}