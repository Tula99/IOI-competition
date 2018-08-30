#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <map>

using namespace std;

string g[25001];
int n;
vector <char> niz;

int common(string a, string b)
{
    int br = 0;
    for (int i=0;i<min(a.size(), b.size());i++)
        if ( a[i] == b[i] ) br++;
        else break;
    return br;
}

bool poredi_na_osnovu_prvog( string a, string b ) { int br1 = common(g[0],a), br2 = common(g[0], b); if ( br1 == br2 ) return a < b; else return br1 > br2; }
bool veci_manji(string a, string b) { return a.size() < b.size(); }

void rijesi_prvi()
{
    swap(g[0], g[n-1]);
    sort(g+1,g+n, poredi_na_osnovu_prvog);
    reverse(g, g+n);

    for (int i=0;i<g[0].size();i++) niz.push_back(g[0][i]);
    niz.push_back('P');
}

void rijesi_ostale()
{
    for (int i=1;i<n;i++)
    {
        int br = common(g[i-1], g[i]);
        for (int j=br;j<g[i-1].size();j++) niz.push_back('-');
        for (int j=br;j<g[i].size();j++) niz.push_back(g[i][j]);
        niz.push_back('P');
    }
}

int main()
{
    cin>>n;
    for (int i=0;i<n;i++) cin>>g[i];

    sort(g,g+n, veci_manji);
    rijesi_prvi();
    rijesi_ostale();

    cout<<niz.size()<<endl;
    for (int i=0;i<niz.size();i++) printf("%c\n",niz[i]);
    return 0;
}
