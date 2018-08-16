#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int n;
long double w;
pair <pair<double, double>, pair<double, double> > k[500001];

int check(pair <pair<double, double>, pair<double, double> > a, pair <pair<double, double>, pair<double, double> > b)
{
    return a.second.first < b.second.first;
}

int main()
{
    cin>>n>>w;

    for (int i=0;i<n;i++)
    {
        scanf("%lf %lf", &k[i].first.first, &k[i].first.second);

        k[i].second.first=k[i].first.first/k[i].first.second;
        k[i].second.second=i+1;
    }

    sort(k,k+n, check);

    priority_queue <double> q;

    double sum = 0.0;

    double manja_cijena = 0.0;
    int poz = 0, vel1 = 0;

    for (int i=0;i<n;i++)
    {
        sum+=k[i].first.second;
        q.push(k[i].first.second);

        while (sum * k[i].second.first > w)
        {
            sum-=q.top();
            q.pop();
        }

        int vel2 = q.size();
        double suma = sum * k[i].second.first;

        if ( vel2 > vel1 || ( vel2 == vel1 && manja_cijena > suma ) ) { vel1 = vel2; poz=i; manja_cijena = suma; }
    }

    priority_queue <pair<double, int> > qq;
    double suma = 0.0;
    for (int i=0;i<=poz;i++)
    {
        suma+=k[i].first.second;

        qq.push({k[i].first.second, k[i].second.second});
    }

    while ( suma * k[poz].second.first > w )
    {
        suma-=qq.top().first;
        qq.pop();
    }

    cout<<qq.size()<<endl;
    while (!qq.empty()) { printf("%d\n",qq.top().second); qq.pop(); }
    return 0;
}
