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
ll st[1000010];
int arr[200010];

void built(int index,int l,int r){
    // cout<<index<<endl;
    if(l>r)return;
    if(l==r){
        st[index] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    built(2*index,l,mid);
    built(2*index + 1,mid+1,r);
    st[index] = st[2*index] ^ st[2*index + 1];
}

ll find(int index,int l,int r,int lf,int rf){
    if(l>r || (l>rf) || r<lf)return 0;
    else if(l>=lf && r<=rf){
        return st[index];
    }
    int mid = (l + r)/2;
    ll s1 = find(2*index,l,mid,lf,rf);
    ll s2 = find(2*index + 1,mid+1,r,lf,rf);
    return s1^s2;
}

void solve(){
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
        // cout<<"ching"<<endl;
    built(1,0,n-1);
    int n1,n2;
    for(int i=0;i<q;i++){
        cin>>n1>>n2;
        int ans = find(1,0,n-1,n1-1,n2-1);
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