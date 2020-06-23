#include<iostream>
#include<vector>
using namespace std;

class Graph                                                  // Graph using vector 
{
    vector <vector<int>> Adj_list;                           // Ajacency list representation
    int nvertices;                                           // number of vertices 
    public:
        Graph(int V): nvertices(V)                           // constructor 
        {
            Adj_list.assign(nvertices,vector<int>());        // assigns n=nvertices elements of type vector <int> to each element in Adj_list
        };
        void insert (int a,int b);                           // initialises graph
        void DFS(int s);
        void DFS_util(int s, vector<bool>&v);
};

void Graph::insert (int a,int b)
{
    this->Adj_list[a].push_back(b);
}

void Graph::DFS_util(int s,vector<bool>&v)                  // Standard DFS algorithm
{
    v[s] = true;
    cout << s << " ";

    for(auto i=this->Adj_list[s].begin();i!=this->Adj_list[s].end();i++)
    {
        if(!v[*i])
            this->DFS_util(*i,v);
    }

}

void Graph::DFS(int s)
{
    vector <bool> v;                                      // true if vertex has been discovered 
    v.assign(this->nvertices,false);                      // initially all undiscovered 

    this->DFS_util(s,v);
}

//Drvier program 
int main() 
{ 

    int nodes, edges; 
    cin >> nodes >> edges; 
    Graph g(nodes);
    int a, b; 
    for (int i = 0; i < edges; i++) 
    { 
        cin >> a >> b; 
        g.insert(a, b);
        cin.ignore(); 
    } 
    int v=0; 
    cin >> v;
    cout << "DFS starting from " << v << "is: ";
    g.DFS(v);
}
