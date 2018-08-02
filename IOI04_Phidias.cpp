#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int r,c,n;
pair <int, bool> dp[601][601];

void vertical(int x, int y)
{
    for (int i=1;i<y;i++)
        dp[x][y].first=min(dp[x][y].first,dp[x][i].first+dp[x][y-i].first);
}

void horizontal(int x, int y)
{
    for (int i=1;i<x;i++)
        dp[x][y].first=min(dp[x][y].first,dp[i][y].first+dp[x-i][y].first);
}

int main()
{
    cin>>r>>c>>n;

    for (int i=0;i<=r;i++)
        for (int j=0;j<=c;j++)
            { dp[i][j].first=0; dp[i][j].second=true; }

    for (int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        dp[a][b].second=false;
    }

    for (int i=1;i<=r;i++)
        for (int j=1;j<=c;j++)
            if ( dp[i][j].second )
            {
                dp[i][j].first=i*j;

                horizontal(i,j);
                vertical(i,j);
            }

    cout<<dp[r][c].first<<endl;
    return 0;
}
