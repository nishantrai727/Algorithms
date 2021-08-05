#include <bits/stdc++.h>

using namespace std;

#define max 9999
#define n 4

int main()
{

    int A[4][4] = {{0, 3, max, 7},
                   {8, 0, 2, max},
                   {5, max, 0, 1},
                   {2, max, max, 0}

    };

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][j] != 0)
                {
                    A[i][j] = (A[i][j]) < A[i][k] + A[k][j] ? A[i][j] : A[i][k] + A[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}