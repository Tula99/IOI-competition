#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int a[10001], b[10001];
vector <pair <int, int> > ko(10001, {1,1});
int x[10001], y[10001];
int n;

void solve_sum_problem()
{
    int n1 = 0, n2 = 0, m1 = n-1, m2 = n-1;

    for (int i=n-1;i>0;i--)
    {
        if ( ko[i].first == ko[i-1].first ) x[i] = a[n1], n1++;
        else x[i] = a[m1],m1--;
        if ( ko[i].second == ko[i-1].second ) y[i] = b[n2], n2++;
        else y[i] = b[m2], m2--;
    }

    x[0] = a[n1];
    y[0] = b[n2];
}

int main()
{
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) cin>>b[i];
    for (int i=0;i<n;i++)
    {
        int q;
        cin>>q;

        if ( q == 2 || q == 3 ) ko[i].first*=-1;
        if ( q == 3 || q == 4 ) ko[i].second*=-1;
    }

    sort(a,a+n);
    sort(b,b+n);

    if ( ko[n-1].first == -1 ) a[n-1]*=-1;
    if ( ko[n-1].second == -1 ) b[n-1]*=-1;
    for (int i=n-2;i>=0;i--)
    {
        if ( a[i+1] > 0 ) a[i]*=-1;
        if ( b[i+1] > 0 ) b[i]*=-1;
    }

    solve_sum_problem();

    for (int i=0;i<n;i++)
        if ( x[i] > 0 && y[i] > 0 ) cout<<"+"<<x[i]<<" +"<<y[i]<<endl;
        else if ( x[i] < 0 && y[i] > 0 ) cout<<x[i]<<" +"<<y[i]<<endl;
        else if ( x[i] > 0 && y[i] < 0 ) cout<<"+"<<x[i]<<" "<<y[i]<<endl;
        else cout<<x[i]<<" "<<y[i]<<endl;
    return 0;
}
