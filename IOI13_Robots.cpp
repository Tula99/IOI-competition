#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int A, B, T;
int X[50001], Y[50001];
pair <int, int> robot[1000001];

bool probaj(int mid)
{
    priority_queue <int> q;

    int br = 0;
    for (int i=0;i<A;i++)
    {
        while (br < T && robot[br].first < X[i]) q.push(robot[br].second), br++;

        int brr = 0;
        while ( !q.empty() && brr < mid ) q.pop(),brr++;
    }

    for (int i=br;i<T;i++) q.push(robot[i].second);

    for (int i=B-1;i>=0;i--)
    {
        int brr = 0;
        while ( !q.empty() && brr < mid && q.top() < Y[i] ) q.pop(),brr++;
    }

    if ( q.empty() ) return true;
    return false;
}

int binarna_pretraga(int left, int right)
{
    while ( left != right )
    {
        int mid = left + ( right - left ) / 2;

        if ( probaj(mid) ) right = mid;
        else left = mid + 1;
    }

    return left;
}

bool da_li_je_moguce()
{
    int a = X[A-1], b = Y[B-1];
    for (int i=0;i<T;i++)
        if ( robot[i].first >= a && robot[i].second >= b ) return false;
    return true;
}

int main()
{
    scanf("%d %d %d",&A,&B,&T);

    for (int i=0;i<A;i++) scanf("%d",&X[i]);
    for (int i=0;i<B;i++) scanf("%d",&Y[i]);
    for (int i=0;i<T;i++) scanf("%d %d",&robot[i].first,&robot[i].second);

    sort(X,X+A);
    sort(Y,Y+B);
    sort(robot,robot+T);

    if ( da_li_je_moguce() ) cout<<binarna_pretraga(1,T)<<endl;
    else cout<<-1<<endl;
    return 0;
}
