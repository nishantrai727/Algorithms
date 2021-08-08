#include<bits/stdc++.h>

using namespace std;

string A="bd";
string B="abcd";

char V[3][5];

int LCS(int i, int j)
{

    if(i==0 || j==0){
        V[i][j]=0;
        return 0;
    }else if(A[i]==B[j]){
        V[i][j] = 1+ LCS(i-1,j-1);
        return 1+ LCS(i-1,j-1);
    }else{
        V[i][j]= max(LCS(i-1,j),LCS(i,j-1));
        return max(LCS(i-1,j),LCS(i,j-1));
    }
    
}


int main(){

    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            cout<<LCS(i,j);
        }
    }



    return 1;
}