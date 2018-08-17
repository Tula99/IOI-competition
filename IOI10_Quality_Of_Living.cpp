#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int r,c,h,w;
int Q[3001][3001];

bool check(int mid)
{
    vector <int> puniti(c+1,0);
    vector <vector<int> > vise(r+1,puniti);
    vector <vector<int> > manje(r+1,puniti);

    for (int i=1;i<=r;i++)
        for (int j=1;j<=c;j++)
        {
            if ( mid > Q[i-1][j-1] ) manje[i][j]++;
            else if ( mid < Q[i-1][j-1] ) vise[i][j]++;

            manje[i][j]+= manje[i][j-1] + manje[i-1][j] - manje[i-1][j-1];
            vise[i][j]+= vise[i][j-1] + vise[i-1][j] - vise[i-1][j-1];
        }

    for (int i=1;i<=r-h+1;i++)
        for (int j=1;j<=c-w+1;j++)
        {
            int suma1 = manje[i+h-1][j+w-1] - manje[i-1][j+w-1] - manje[i+h-1][j-1] + manje[i-1][j-1];
            int suma2 = vise[i+h-1][j+w-1] - vise[i-1][j+w-1] - vise[i+h-1][j-1] + vise[i-1][j-1];

            if ( suma1 >= suma2 ) return true;
        }

    return false;
}

int binarna_pretraga(int left, int right)
{
    while (left != right)
    {
        int mid = left + (right - left)/2;

        if ( check(mid) ) right=mid;
        else left = mid+1;
    }

    return left;
}

int main()
{
    cin>>r>>c>>h>>w;

    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            cin>>Q[i][j];

    cout<<binarna_pretraga(1,r*c)<<endl;
    return 0;
}
