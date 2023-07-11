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

int arr[200000];
vector<ll> st(1000000,0);

void built(int index,int l,int r){
    if(l>r)return;
    if(l==r){st[index] = arr[l]; return;}
    int mid = (l+r)/2;
    built(2*index,l,mid);
    built(2*index + 1,mid+1,r);
    st[index] = st[2*index] + st[2*index + 1];

}
ll find(int index,int l,int r,int lf,int rf){
    if(l> rf || r<lf){
        return 0;
    }else if(l>= lf && r<= rf){
        return st[index];
    }
    int mid = (l+r)/2;
    ll s1 = find(2*index,l,mid,lf,rf);
    ll s2 = find(2*index + 1,mid+1,r,lf,rf);
    return s1 + s2;
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    built(1,0,n-1);
    // cout<<st[0]<<" ching"<<endl;
    for(int i=0;i<q;i++){
        int q1,q2;
        cin>>q1>>q2;
        cout<<find(1,0,n-1,q1-1,q2-1)<<endl;
    }

}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}