#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

vector <int> find_subset(int n, int l, int u, int w[])
{
    vector <pair<int, int> > poz;
    for (int i=0;i<n;i++) poz.push_back({w[i],i});

    sort(poz.begin(),poz.end());

    long long suma = 0;
    vector <int> p;
    int q = n-1;

    for (int i=n-1;i>=0;i--)
    {
        suma+=poz[i].first;

        if ( suma >= l && suma <= u ) {for (int j=q;j>=i;j--) p.push_back(poz[j].second); return p; }
        else if ( suma > u )
        {
            while ( suma > u )
            {
                suma-=poz[q].first;
                q--;
            }
        }
        if ( suma >= l && suma <= u ) {for (int j=q;j>=i;j--) p.push_back(poz[j].second); return p; }
    }

    return p;
}

int main()
{
    int n,l,u;
    cin>>n>>l>>u;

    int w[n];
    for (int i=0;i<n;i++) cin>>w[i];

    vector <int> d = find_subset(n,l,u,w);

    cout<<d.size()<<endl;
    for (int i=0;i<d.size();i++) cout<<d[i]<<" ";
    return 0;
}
