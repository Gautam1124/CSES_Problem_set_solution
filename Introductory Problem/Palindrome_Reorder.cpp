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

void solve(){
    string str;
    cin>>str;
    map<int,int> m;
    int n = str.size();
    for(int i=0;i<n;i++){
        m[str[i] - 'A']++;
    }
    int count = 0,ind = -1;
    for(int i=0;i<26;i++){
        if(m[i]%2){count++;ind = i;}
    }
    if(count > 1){
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    int index = 0;
    for(int i=0;i<26;i++){
        if(i == ind)continue;
        int val = m[i];
        val /= 2;
        while(val > 0){
            str[index] = char(i + 'A');
            str[n-1-index] = char(i + 'A');
            index++;
            val--;
        }
    }
    if(ind != -1){
        int val = m[ind];
        val /= 2;
         while(val > 0){
            str[index] = char(ind + 'A');
            str[n-1-index] = char(ind + 'A');
            index++;
            val--;
        }
        str[index] = char(ind + 'A');
    }
    cout<<str<<endl;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
return 0;
}