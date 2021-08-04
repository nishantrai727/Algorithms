#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 8;
    int stages = 4, min;

    int cost[9], d[9];

    int c[9][9] = {

        {0, 0, 2, 1, 3, 0, 0, 0, 0},
        {0, 0, 2, 1, 3, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 3, 0, 0},
        {0, 0, 0, 0, 0, 6, 7, 0, 0},
        {0, 0, 0, 0, 0, 6, 8, 9, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    cost[n] = 0;

    for (int i = n - 1; i >= 1; i--)
    {
        min = 9999;
        for (int j = i + 1; j <= n; j++)
        {
            if (c[i][j] != 0 && c[i][j] + cost[j] < min )
            {
                min = c[i][j] + cost[j];
                d[i] = j;
            }
        }
        cost[i] = min;
    }
    int p[9]={0,0,0,0,0,0,0,0,0};
    p[1] = 1;
    p[stages] = n;

    for (int k = 2; k < stages; k++)
    {
        p[k] = d[p[k - 1]];
    }

    for (auto s : p)
    {

        cout << s <<" ";
    }

    return 0;
}