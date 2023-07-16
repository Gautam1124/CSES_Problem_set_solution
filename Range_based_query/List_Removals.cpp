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
vector<pii> trie(1000010);
vector<int> ans;
void built(int index,int l,int r){
    if(l>r)return;
    if(l==r){
        trie[index] = {1,arr[l]};
        return;
    }
    int mid = (l+r)/2;
    built(2*index,l,mid);
    built(2*index + 1,mid+1,r);
    trie[index] = {trie[2*index].F + trie[2*index+1].F, -1};
}

void find_update(int index,int l,int r,int ct){
    if(l>r)return;
    if(l==r){
        ans.push_back(arr[l]);
        trie[index].F--;
        return;
    }
    trie[index].F--;
    int ct1 = trie[2*index].F;
    int ct2 = trie[2*index + 1].F;
    if(ct1 >= ct){
        find_update(2*index,l,(l+r)/2,ct);
    }else{
        find_update(2*index+1,((l+r)/2) + 1,r,ct - ct1);
    }
}


void solve(){
int n;cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];

    built(1,0,n-1);
    for(int i=0;i<n;i++){
        int ct;cin>>ct;
        find_update(1,0,n-1,ct);
    }
    for(auto ele:ans)cout<<ele<<" ";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}