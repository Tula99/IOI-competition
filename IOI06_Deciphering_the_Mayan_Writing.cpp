#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <bits/stdc++.h>
#include <set>
#include <vector>

using namespace std;

int a,b;
vector <int> A(250,0),B(250,0);
string d;

bool perm_check()
{
    for (char i='A';i<='Z';i++)
        if ( A[i] != B[i] ) return false;
    for (char i='a';i<='z';i++)
        if ( A[i] != B[i] ) return false;
    return true;
}

int main()
{
    cin>>a>>b;

    cin>>d;
    for (int i=0;i<a;i++)
        A[d[i]]++;

    cin>>d;
    for (int i=0;i<a;i++)
        B[d[i]]++;

    int br = 0;
    for (int i=a;i<b;i++)
    {
        if ( perm_check() ) br++;
        B[d[i-a]]--;
        B[d[i]]++;
    }

    if (perm_check()) br++;

    cout<<br<<endl;
    return 0;
}
