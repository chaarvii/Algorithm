#include<iostream>
#include<vector>
#include<stack>
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
        void topological_sort();
        void DFS(int s, vector<bool>&v,stack<int>&stk);
};

void Graph::insert (int a,int b)
{
    this->Adj_list[a].push_back(b);
}

void Graph::DFS(int s,vector<bool>&v,stack<int>&stk)
{
    v[s] = true;
    for(auto i=this->Adj_list[s].begin();i!=this->Adj_list[s].end();i++)
    {
        if(!v[*i])
            this->DFS(*i,v,stk);
    }
    stk.push(s);                                            // LIFO, for storing the order of vertices 
                                                            // first vertex to be pushed is the one that has zero out degree 
}

void Graph::topological_sort()
{
    vector <bool> v;
    v.assign(this->nvertices,false);
    stack <int> stk;

    for(auto i = 0;i<this->nvertices;i++)
        if(!v[i])
            this->DFS(i,v,stk);

    while(!stk.empty())
        {
            cout << stk.top() << " ";                      // first vertex in topological sort is the one with zero in degree
            stk.pop();
        }
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
    cout << "topological sort of the graph is: ";
    g.topological_sort();
}
