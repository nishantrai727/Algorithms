#include <bits/stdc++.h>
// #include <iostream>

using namespace std;

struct Node{
    int parent;
    int rank;
};

struct Edge
{
    int S;
    int D;
    int W;
};

vector<Node> nodeList;
vector<Edge> mst;



bool comparator(Edge a, Edge b)
{
    return a.W < b.W;
}

int find(int n){

    if(nodeList[n].parent == -1){
        return n;
    }
    return nodeList[n].parent = find(nodeList[n].parent);

}

void parent_op(int start, int end){

     start = find(start);
     end = find(end);

     if(nodeList[start].rank > nodeList[end].rank){
         nodeList[end].parent =start;
     } else if(nodeList[start].rank< nodeList[end].rank){
         nodeList[start].parent = end;
     }else{
         nodeList[start].parent = end;
         nodeList[start].rank +=1;

     }
}

void Kruskals(vector<Edge> edgeList, int V, int E)
{

    sort(edgeList.begin(), edgeList.end(), comparator);

    int i = 0;
    int j = 0;

    while (i < V && j <= E)
    {

        int start = find(edgeList[j].S);
        int end = find(edgeList[j].D);

        if(start==end){
            j++;
            continue;
        }

        parent_op(start,end);
        mst.push_back(edgeList[j]);

    }

    for(auto p: mst){
        cout<<"src:"<<p.S<< " dst:"<< p.D << " wt: "<<p.W;

    }
}

int main()
{

    int E;
    int V;
    cout << "Enter number of Edges:" << endl;
    cin >> E;
    cout << "Enter number of Vertices:" << endl;
    cin >> V;

    vector<Edge> edgeList;
    Edge temp; 
    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cout<<"src: "<<"\n";
        cin >> s;
        cout<<"dst: "<<"\n";
        cin >> d;
        cout<<"wt: "<<"\n";
        cin >> w;
        temp.S = s;
        temp.D = d;
        temp.W = w;
        edgeList.push_back(temp);
    }

    Kruskals(edgeList, V, E);
}