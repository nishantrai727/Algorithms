#include <bits/stdc++.h>

using namespace std;

#define n 7 //no of nodes
#define max 9999

int main()
{

    struct Edge
    {
        int u;
        int v;
        int wt;
    };

    int c[n][n] = {
        { max, 6, 5, 5, max, max, max},
        { max, max, max, max, -1, max, max},
        { max, -2, max, max, 1, max, max},
        { max, max, -2, max, max, -1, max},
        { max, max, max, max, max, max, 3},
        { max, max, max, max, max, max, 3},
        { max, max, max, max, max, max, max},
    };

    vector<Edge> edgeList;

    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (c[i][j] != max)
            {
                Edge temp;
                temp.u = i;
                temp.v = j;
                temp.wt = c[i][j];
                edgeList.push_back(temp);
                cout<<"u: "<<i<<" v: "<<j<<" wt: "<<c[i][j];
                cout<<"\n ";
            }

        }
    }

    int cost[n];

    cost[0]=0;

    for(int i=1;i<n;i++){
        cost[i]=max;
    }

    for (int i = 1; i < n; i++)
    {
        for (auto k: edgeList)
        {
            
            if (cost[k.u]+k.wt<cost[k.v])
            {
               cost[k.v]=cost[k.u]+k.wt;       
            }
            cout<<cost[k.v]<<" ";
        }
        cout<<"\n ";
    }

    for(auto p: cost){
        cout<< p<<" ";
    }

    return 1;
}