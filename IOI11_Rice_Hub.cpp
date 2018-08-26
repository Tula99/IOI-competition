#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int r,l;
unsigned long long b;
vector <unsigned long long> trosak(100001,0);
int x[100001];

bool rice_hub(int mid)
{
    unsigned long long potrosio;

    for (int i=1;i<=r-mid+1;i++)
    {
        potrosio = (trosak[i + mid - 1] - trosak[(2*i+mid-1)/2]) - (trosak[(2*i+mid-1)/2 - (mid % 2)] - trosak[i-1]);

        if ( potrosio <= b ) return true;
    }

    return false;
}

int binarna_pretraga(int left, int right)
{
    while (left != right)
    {
        int mid = (right + 1 + left) / 2;

        if ( rice_hub(mid) ) left = mid;
        else right = mid - 1;
    }

    return left;
}

int main()
{
    cin>>r>>l>>b;

    for (int i=0;i<r;i++) cin>>x[i];

    for (int i=1;i<=r;i++) trosak[i] = trosak[i-1] + x[i-1];

    cout<<binarna_pretraga(0,r)<<endl;
    return 0;
}
