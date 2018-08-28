#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector <vector <pair<int, int> > > graf(100001);

    for (int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        graf[a].push_back({c,b});
        graf[b].push_back({c,a});
    }

    vector <bool> pick1(n+1,false), pick2(n+1,false);
    priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

    for (int i=0;i<k;i++)
    {
        int a;
        cin>>a;

        pick1[a]=true;
        q.push({0,a});
    }

    while ( !q.empty() )
    {
        pair <int, int> sad = q.top();
        q.pop();

        if ( !pick1[sad.second] ) pick1[sad.second] = true;
        else
        {
            if ( !pick2[sad.second] )
            {
                pick2[sad.second] = true;
                if ( sad.second == 0 ) { cout<<sad.first<<endl; return 0; }

                for (int i=0;i<graf[sad.second].size();i++)
                    if ( !pick2[graf[sad.second][i].second] )
                        q.push({graf[sad.second][i].first + sad.first, graf[sad.second][i].second});
            }
        }
    }
    return 0;
}
