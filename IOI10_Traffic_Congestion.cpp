#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;
#define maxn 1000001

int n;
vector <vector <int> > graf(maxn);
int cost[maxn];
int naprijed[maxn];

void dfs1(int cvor, int pre)
{
    naprijed[cvor]=cost[cvor];
    for (int i=0;i<graf[cvor].size();i++)
        if ( graf[cvor][i] != pre ) { dfs1(graf[cvor][i],cvor); naprijed[cvor]+=naprijed[graf[cvor][i]]; }
}

vector <pair<int, int> > rez;

void dfs2(int cvor, int pre, int trosak)
{
    int maks = trosak;

    for (int i=0;i<graf[cvor].size();i++)
        if ( graf[cvor][i] != pre )
        {
            dfs2(graf[cvor][i],cvor,trosak+naprijed[cvor]-naprijed[graf[cvor][i]]);
            maks=max(maks,naprijed[graf[cvor][i]]);
        }
    rez.push_back({maks,cvor});
}

int main()
{
    cin>>n;
    for (int i=0;i<n;i++) cin>>cost[i];

    for (int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;

        graf[x].push_back(y);
        graf[y].push_back(x);
    }

    dfs1(0,-1);
    dfs2(0,-1,0);

    sort(rez.begin(),rez.end());
    cout<<rez[0].second<<endl;
    return 0;
}
