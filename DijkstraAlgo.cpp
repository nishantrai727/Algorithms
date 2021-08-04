#include <bits/stdc++.h>

using namespace std;

#define max 9999
#define n 6

int main()
{

    int wt[6][6] = {
        {0, 1, 4, 0, 0, 0},
        {1, 0, 4, 2, 7, 0},
        {4, 4, 0, 3, 5, 0},
        {0, 2, 3, 0, 4, 6},
        {0, 7, 5, 4, 0, 7},
        {0, 0, 0, 6, 7, 0}};

    int parent[6] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1};
    int value[6] = {
        0,
        max,
        max,
        max,
        max,
        max};
    bool processed[6] = {
        false,
        false,
        false,
        false,
        false,
        false};

    vector<int> set;

    
    for(int k=0;k<n-1;k++){

        int min = max;
        int mark=-1;

        //finding the min value node
        for(int i=0;i<n;i++){
            if(value[i]<min && processed[i]==false){
                min = value[i];
                mark=i;
            }
        }
        //processing it
        processed[mark]=true;
        //relaxing adjacent nodes       
        for(int j =0;j<n;j++){
            if( wt[mark][j]!=0 && processed[j]== false && wt[mark][j]+value[mark]< value[j]){
                value[j]= wt[mark][j]+value[mark];
                parent[j]=mark;
            }
        }

    }

    //parent array for the nodes to form graph
     cout<<"\n";
    for(auto q: parent){
        cout<<q<<" ";
    }


    // value of each node if considered in path
    cout<<"\n";
    for(auto q: value){
        cout<<q<<" ";
    }

    cout<<"\n"<<"PATH: ";

    int p=5;
    do{
        cout<< p<<" ";
        p= parent[p];
    }while(p>=0);
    

    return 0;

}
