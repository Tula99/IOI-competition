#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector <pair<bool, int> > rate(n);
    for (int i=0;i<n;i++)
    {
        rate[i].first=false;
        cin>>rate[i].second;
    }

    int niz[m];
    for (int i=0;i<m;i++) cin>>niz[i];
    int t[n];
    int koliko = 0;

    queue <int> q;
    for (int k=0,a;k<2*m;k++)
    {
        cin>>a;

        if ( a < 0 )
        {
            a*=(-1);
            for (int i=0;i<n;i++)
                if ( t[i] == a ) rate[i].first=false;
        }
        else q.push(a);
        
        while ( q.empty() == false )
        {
            int sad = q.front();
            bool flag = true;
            for (int i=0;i<n;i++)
            {
                if ( rate[i].first == false )
                {
                    koliko+=rate[i].second*niz[sad-1];
                    t[i]=sad;
                    rate[i].first=true;
                    flag=false;
                    break;
                }
            }
            if ( flag ) break;
            else q.pop();
        }
    }

    cout<<koliko<<endl;
    return 0;
}
