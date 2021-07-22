#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define MAX 999
#define n 6

int minVertex(vector<int>& value, vector<bool>& isMst)
{

    int vertex;
    int min = MAX;
    for (int i = 0; i < n; i++)
    {

        if (value[i] < min && isMst[i] == false)
        {
            vertex = i;
            min = value[i];
        }
    }
    return vertex;
}

void primsMst(int c[n][n])
{

    int parent[n];
    vector<int> value(n, MAX);
    vector<bool> isMst(n, false);

    parent[0] = -1;
    isMst[0] = true;

    for (int i = 0; i < n - 1; i++)
    {

        int point = minVertex(value, isMst);
        isMst[point] = true;

        for (int k = 0; k < n; k++)
        {

            if (c[point][k] != 0 && isMst[k] == false && c[point][k] < value[k])
            {
                value[k] = c[point][k];
                parent[k] = point;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<parent[i];
    }
}

int main()
{

    int graph[n][n] = {
        {0, 4, 6, 0, 0, 0},
        {4, 0, 6, 3, 4, 0},
        {6, 6, 0, 1, 0, 0},
        {0, 3, 1, 0, 2, 3},
        {0, 4, 0, 2, 0, 7},
        {0, 0, 0, 3, 7, 0}};

    primsMst(graph);

    return 0;
}