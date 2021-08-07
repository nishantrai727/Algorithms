#include <bits/stdc++.h>

using namespace std;

#define n 4

int count = 4;

vector<int> path;

int c[4][4] = {
    {0, 10, 15, 20},
    {5, 0, 9, 10},
    {6, 13, 0, 12},
    {8, 8, 9, 0}};

int p = 0;

int travel(int k, int arr[n])
{
    int min = 999;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
        {        
            arr[i] = -1;
            int temp = c[k][i] + travel(i, arr);
            if (temp < min)
            {
                min = temp;
            }
            arr[i]=i;
        }       
    }
    if (min == 999)
    {
        cout << c[k][0] << " ";
        return c[k][0];
    }
    cout << min << " ";
    return min;
}

int main()
{

    int arr[n] = {0, 1, 2, 3};

    int cost = travel(0, arr);
    cout << cost;

    return 1;
}
