//*********************Gautam Kumar|||||||||||||Hare Krishna****************

#include <bits/stdc++.h>
#define F first
#define S second
#define p_b push_back
#define M_K make_pair
#define pii pair<int, int>
#define ll long long
#define vi vector<int>
using namespace std;

int X[] = {-1, 1, 0, 0};
int Y[] = {0, 0, 1, -1};

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    int dist[n + 2][m + 2];

    for (int i = 0; i <= m; i++)
        dist[0][i] = i;

    for (int i = 0; i <= n; i++)
        dist[i][0] = i;

    dist[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dist[i][j] = dist[i - 1][j - 1];
            }
            else
            {
                dist[i][j] = 1 + min(dist[i - 1][j], min(dist[i - 1][j - 1], dist[i][j - 1]));
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout << dist[n][m] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}