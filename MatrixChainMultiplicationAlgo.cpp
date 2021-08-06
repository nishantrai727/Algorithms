#include <bits/stdc++.h>

using namespace std;

#define n 5

int main()
{

    //A : 5x4
    //B : 4x6
    //C : 6x2
    //D : 2x7

    int p[n] = {5, 4, 6, 2, 7};

    int m[n][n] = {0};
    int s[n][n] = {0}; //parenthisation

    int j, min, q;

    for (int d = 1; d < n - 1; d++)
    {

        for (int i = 1; i < n-d; i++)
        {

            j = d + i;
            min = 9999;

            for (int k = i; k <=j - 1; k++)
            {

                q = m[i][k] + m[k + 1][j] + (p[i -1] * p[k] * p[j]);

                if (q < min)
                {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
            cout<< min <<" ";
        }
        cout<<"\n";
    }

    for(int i =1;i<n;i++){
        for(int k=1;k<n;k++){
            cout<<m[i][k]<< " ";
        }
        cout<<"\n";
    }



    cout<<m[1][n-1];

    return 1;
}