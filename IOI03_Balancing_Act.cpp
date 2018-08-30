#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n;
vector <vector <int> > graf(20001);
vector <int> put(20001,0);
vector <vector <int> > dist(20001);

int dfs(int cvor, int pre)
{
    for (int i=0;i<graf[cvor].size();i++)
        if ( graf[cvor][i] != pre )
        {
            int uda = dfs(graf[cvor][i], cvor);
            put[cvor]+=uda;
            dist[cvor].push_back(uda);
        }

    return put[cvor] + 1;
}

int main()
{
    cin>>n;
    for (int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;

        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    dfs(1,-1);

    for (int i=1;i<=n;i++)
        dist[i].push_back(n-put[i]-1);

    vector <pair<int, int> > rez;
    for (int i=1;i<=n;i++)
    {
        int bal = -1;
        for (int j=0;j<dist[i].size();j++) bal=max(bal, dist[i][j]);

        rez.push_back({bal,i});
    }

    sort(rez.begin(),rez.end());
    cout<<rez[0].second<<" "<<rez[0].first<<endl;
    return 0;
}
