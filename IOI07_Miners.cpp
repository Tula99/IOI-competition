#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

string g;
int n;

int dp[2][5][5][5][5];
int diff[100001];

int how_much(int a, int b, int c)
{
    if ( a == b && b == c ) return 1;
    else if ( a != 3 && b != 3 && c != 3 )
    {
        if ( a != b && a != c && b != c ) return 3;
        else if ( a == b && a != c ) return 2;
        else if ( c == b && a != c ) return 2;
        else if ( a == c && a != b ) return 2;
        else return 1;
    }
    else if ( a == 3 && b == 3 && c != 3 ) return 1;
    else if ( a == 3 && c == 3 && b != 3 ) return 1;
    else if ( c == 3 && b == 3 && a != 3 ) return 1;
    else if ( a == 3 )
        if ( b == c ) return 1;
        else return 2;
    else if ( b == 3 )
        if ( a == c ) return 1;
        else return 2;
    else if ( c == 3 )
        if ( a == b ) return 1;
        else return 2;
}

int main()
{
    cin>>n;
    cin>>g;

    for (int i=0;i<n;i++)
        if ( g[i] == 'M' ) diff[i]=0;
        else if ( g[i] == 'F' ) diff[i]=1;
        else diff[i]=2;

    for (int i=n-1;i>=0;i--)
        for (int j=0;j<4;j++)
            for (int k=0;k<4;k++)
                for (int l=0;l<4;l++)
                    for (int m=0;m<4;m++)
                        dp[i%2][j][k][l][m]=max( dp[(i+1)%2][k][diff[i]][l][m] + how_much(j,k,diff[i]), dp[(i+1)%2][j][k][m][diff[i]] + how_much(l,m,diff[i]) );

    cout<<max(dp[0][3][3][3][3],dp[1][3][3][3][3])<<endl;
    return 0;
}
