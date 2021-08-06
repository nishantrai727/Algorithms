#include <bits/stdc++.h>

using namespace std;

int main()
{

    int m = 8; //max wt allowed
    int n = 4;

    int p[5] = {0,1, 2, 5, 6}; //profit
    int w[5] = {0,2, 3, 4, 5}; //weight

    int v[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {

        for (int j = 0; j <= m; j++)
        {

            if (i == 0 || j == 0)
            {
                v[i][j] = 0;
            }
            else if (w[i] <= j)
            {
                v[i][j] = (v[i - 1][j]) > (v[i - 1][j - w[i]] + p[i]) ? (v[i - 1][j]) : (v[i - 1][j - w[i]] + p[i]);
            }
            else
            {

                v[i][j] = v[i - 1][j];
            }
            cout<< v[i][j]<< " ";
        }
        cout<<"\n";
    }
    cout<<v[n][m];
    return 1;
}