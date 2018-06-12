#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <set>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string g;
    cin>>g;

    int dp[2][n+1];
    for (int i=0;i<2;i++)
        for (int j=0;j<=n;j++)
            dp[i][j]=0;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if ( g[i-1] == g[n-j] ) dp[i%2][j]=dp[(i-1)%2][j-1]+1;
            else dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);

    cout<<n-dp[n%2][n]<<endl;
    return 0;
}
