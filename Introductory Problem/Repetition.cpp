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
    string dna;
    cin>>dna;
    int n = dna.size();
    char prev;
    int mx =0;
    int count =0;

    prev=dna[0], count =1;
    for(int i=1;i<n;i++){
        if(dna[i]==prev)count++;
        else{
            mx = max(mx,count);
            count=1;
            prev=dna[i];
        }
    }
    mx = max(mx,count);
    cout<<mx<<endl;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}