#include <bits/stdc++.h>

using namespace std;

string A = "bd";
string B = "abcd";

char V[3][5];

int LCS(int i, int j)
{

    if (A[i] == (char)'\0' || B[j] == (char)'\0')
    {

        return 0;
    }
    else if (A[i] == B[j])
    {
        return 1 + LCS(i + 1, j + 1);
    }
    else
    {
        return max(LCS(i + 1, j), LCS(i, j + 1));
    }
}

int main()
{

    cout << LCS(0, 0);

    return 1;
}
