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
vector<int> arr(200010);
vector<pair<int,pii>> trie(1000010);

void built(int index,int l,int r){
    if(l>r)return;
    if(l==r){
        trie[index] = {1,M_K(arr[l],arr[l])};
        return;
    }
    int mid = (l+r)/2;
    built(2*index,l,mid);
    built(2*index + 1, mid + 1, r);
    trie[index] = {trie[2*index].F + trie[2*index+1].F,{max(trie[2*index].S.F, trie[2*index + 1].S.F), min(trie[2*index].S.S, trie[2*index + 1].S.S)}};
}

void update(int index,int l,int r,int k,int val){
    if(l>r || k>r || k<l)return;
    if(l==r && l==k){
        trie[index] = {1,M_K(val,val)};
        arr[l] = val;
        return;
    }
     int mid = (l+r)/2;
    update(2*index,l,mid,k,val);
    update(2*index + 1, mid + 1, r,k,val);
    trie[index] = {trie[2*index].F + trie[2*index+1].F,{max(trie[2*index].S.F, trie[2*index + 1].S.F), min(trie[2*index].S.S, trie[2*index + 1].S.S)}};
}

int find_freq(int index,int l,int r,int lf,int rf){
    if(l>r || trie[index].S.F < lf || trie[index].S.S > rf)return 0;
    if(lf<=trie[index].S.S && rf>=trie[index].S.F){
        return trie[index].F;
    }
    int mid = (l+r)/2,s1 =0 ,s2=0;
     s1 = find_freq(2*index,l,mid,lf,rf);
     s2 = find_freq(2*index + 1, mid+1,r,lf,rf);
    int ans = s1 + s2;
    return ans;
}

void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)cin>>arr[i];
    built(1,0,n-1);
    while(m--){
        char a;int b;int c;
        cin>>a;
        if(a=='!'){
            cin>>b>>c;
            update(1,0,n-1,b-1,c);
        }else{
            cin>>b>>c;
            int ans = find_freq(1,0,n-1,b,c);
            cout<<ans<<endl;
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