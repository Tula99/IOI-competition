#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int q,m,k;
int polja[150001];
int traka[150001];
int br = 0;

int main()
{
    cin>>q>>m>>k;

    for (int i=0;i<m;i++)
    {
        cin>>polja[i];

        br+=polja[i];
    }

    for (int i=0;i<k;i++) cin>>traka[i];

    if ( br == q ) cout<<br<<endl;
    else if ( br < q )
    {
        sort(traka,traka+k);

        int poz = 0;
        for (int i=k-1;i>=0;i--)
            if ( br < q ) br+=traka[i], poz++;
            else break;

        if ( br < q ) cout<<br<<endl;
        else cout<<q-poz<<endl;
    }
    else
    {
        vector <bool> dp(150001,false);
        dp[0]=true;
        sort(polja,polja+m);
        int suma = 0;
        for (int i=suma;i<m;i++)
        {
            if ( dp[q] ) break;

            for (int j=suma;j>=0;j--)
                if ( dp[j] ) dp[j+polja[i]] = true;

            if ( suma < q ) suma+=polja[i];
        }

        br=q;
        if ( !dp[q] ) br--;

        cout<<br<<endl;
    }
    return 0;
}
