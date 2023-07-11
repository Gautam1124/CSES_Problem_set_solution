//*********************Gautam Kumar|||||||||||||Hare Krishna****************

#include <bits/stdc++.h>
#define F first
#define S second
#define p_b push_back
#define M_K make_pair
#define pii pair<int, int>
#define ll long long
using namespace std;

int X[] = {-1, 1, 0, 0};
int Y[] = {0, 0, 1, -1};

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    vector<int> vec(x + 1, -1);
    vec[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] > i)
                break;
            if (vec[i - coins[j]] != -1 )
            {
                if(vec[i] == -1)vec[i] = vec[i - coins[j]] + 1;
                else if(vec[i - coins[j]] + 1 < vec[i])vec[i] = vec[i - coins[j]] + 1;
            }
        
        }
        // cout<<vec[i]<<" "<<endl;
    }
    cout<<vec[x]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}