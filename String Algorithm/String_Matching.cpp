//*********************Gautam Kumar|||||||||||||Hare Krishna****************

#include <bits/stdc++.h>
#define F first
#define S second
#define p_b push_back
#define M_K make_pair
#define pii pair<int,int>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
 
int X[] = {-1,1,0,0};
int Y[] = {0,0,1,-1};
int prearr[1000005];
void calc_prearr(string pat,int m){
    prearr[0] = 0;
    int i= 1;
    int j = 10;
    int index = 0;
    int count =0;
    while(i<m){
        // cout<<pat[index]<<" "<<pat[i]<<" "<<i<<" ->";
        if(pat[index] == pat[i]){
            index++;
            prearr[i] = index;
            i++;
        }else{
            if(index == 0){
                // cout<<"ching"<<endl;
                prearr[i] = 0;
                i++;
            }else{
                index = prearr[index-1];
            }
        }
        // cout<<prearr[i-1]<<" "<<" "<<index<<endl;
        // count++;
        // cout<<i<<" "<<index<<endl;
    }
    
}

void KMP(string s, string pat,int n,int m){
    int i=0,j=0,count=0;
    while(n-i >= m-j){
        if(s[i] == pat[j]){
            i++;
            j++;
        }
        if(j==m){
            count = (count%mod + 1)%mod;
            j = prearr[j-1];
        }
        else if(i<n && s[i] != pat[j] ){
            if(j!= 0){
                j = prearr[j-1];
            }else{
                i++;
            }
        }
    }
    cout<<count<<endl;
}


void solve(){
    string s;cin>>s;
    string ss;cin>>ss;
    int n = s.size();
    int m = ss.size();
    calc_prearr(ss,m);
    // cout<<"ching";
    KMP(s,ss,n,m);

}






int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}