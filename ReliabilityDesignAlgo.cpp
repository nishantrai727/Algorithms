#include <bits/stdc++.h>

using namespace std;

#define n 3

float getRelaibility(float r, int power)
{

    double q = 1 - r;
    for (int i = 1; i < power; i++)
    {
        q *= q;
    }
    return 1 - q;
}

int main()
{

    int maxCost = 105; //given

    float r[3] = {0.9, 0.8, 0.5}; //given
    int c[3] = {30, 15, 20};      //given
    int u[3];

    int totCost = 0;

    for (auto p : c)
    {
        totCost += p;
    }

    for (int i = 0; i < n; i++)
    {
        u[i] = ((maxCost - totCost) / c[i]) + 1;
    }

    struct dev
    {
        float r;
        int c;
    };

    vector<dev> S;

    dev d;
    d.r = 1.0;
    d.c = 0;

    S.push_back(d);

    for (int i = 0; i < n; i++)
    {

        vector<dev> q;

        for (int j = 1; j <= u[i]; j++)
        {

            dev temp;
            temp.r = getRelaibility(r[i], j);
            // cout<<getRelaibility(r[i], j)<<"--------"<<"\n";
            temp.c = c[i] * j;
            // cout << "r:" << temp.r << " c:" << temp.c <<"temp<<" "\n";

            for (int k = 0; k < S.size(); k++)
            {

                dev t;
                t.c = temp.c + S[k].c;
                t.r = temp.r * S[k].r;

                if (t.c <= maxCost && temp.c - c[i] < maxCost - totCost)
                {
                    q.push_back(t);
                }
            }
        }
        S = {};
        for (auto k : q)
        {
            S.push_back(k);
        }
    }

    for (auto k : S)
    {
        cout << "r:" << k.r << " c:" << k.c << "\n";
    }
    


    return 1;
}