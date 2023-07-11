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

void min_rotation(string s, string pat,int n,int m){
    int arr[n];

    int i=0,j=0;
    while(n>i){
        if(s[i] == pat[j]){
            j++;
            arr[i] = j;
            i++;
        }
        if(j==m){
            j = prearr[j-1];
        }
        else if(i<n && s[i] != pat[j] ){
            if(j!= 0){
                j = prearr[j-1];
            }else{
                arr[i] = 0;
                i++;

            }
        }
    }
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}


void solve(){
    string s;cin>>s;
    string ss = s;
    sort(ss.begin(),ss.end());
    int n = s.size();
    int m = ss.size();
    calc_prearr(ss,m);
    // cout<<"ching";
    min_rotation(s,ss,n,m);

}






int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}