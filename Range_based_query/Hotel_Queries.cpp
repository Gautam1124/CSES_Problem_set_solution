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
vector<int>trie(1000010);
vector<int>arr(200010);

void built(int index,int l,int r){
    if(l>r)return;
    if(l==r){
        trie[index] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    built(2*index,l,mid);
    built(2*index + 1,mid+1,r);
    trie[index] = max(trie[2*index], trie[2*index + 1]);
}
int search(int index,int l,int r,int k){
    int trie_index = -1;
    if(l>r)return -1;
    if(l==r){
        trie[index] = trie[index] - k;
        return l;
    }
    int mid = (l+r)/2;
    if(trie[2*index] >= k)trie_index = search(2*index,l,mid,k);
    else if(trie[2*index + 1] >= k)trie_index = search(2*index + 1,mid+1,r,k);
    else return -1;
    trie[index] = max(trie[2*index], trie[2*index + 1]);
    return trie_index;
}

void solve(){
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    built(1,0,n-1);
    while(q--){
        int a;
        cin>>a;
        if(a>trie[1]){
            cout<<0<<endl;
        }else{

            int index = search(1,0,n-1,a);
            cout<<index+1<<endl;
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