#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];

    int jedan = 0;
    int dva = 0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];

        if ( a[i] == 1 ) jedan++;
        else if ( a[i] == 2 ) dva++;
    }

    vector <pair<int, int> > koraci;

    for (int i=0;i<jedan;i++)
        if ( a[i] != 1 )
        {
            for (int j=jedan;j<jedan+dva;j++)
                if ( a[j] == 1 && a[i] == 2 )
                {
                    a[i]^=a[j];a[j]^=a[i];a[i]^=a[j];

                    koraci.push_back({i+1,j+1});
                    break;
                }
            for (int j=jedan+dva;j<n;j++)
                if ( a[j] == 1 && a[i] == 3 )
                {
                    a[i]^=a[j];a[j]^=a[i];a[i]^=a[j];

                    koraci.push_back({i+1,j+1});
                    break;
                }
            for (int j=jedan;j<n;j++)
                if ( a[j] == 1 && (a[i] == 2 || a[i] == 3) )
                {
                    a[i]^=a[j];a[j]^=a[i];a[i]^=a[j];

                    koraci.push_back({i+1,j+1});
                    break;
                }
        }

    for (int i=jedan;i<jedan+dva;i++)
        if ( a[i] != 2 )
            for (int j=jedan+dva;j<n;j++)
                if (a[j] == 2 )
                {
                    a[i]^=a[j];a[j]^=a[i];a[i]^=a[j];

                    koraci.push_back({i+1,j+1});
                    break;
                }

    cout<<koraci.size()<<endl;
    for (int i=0;i<koraci.size();i++)
        cout<<koraci[i].first<<" "<<koraci[i].second<<endl;
    return 0;
}
