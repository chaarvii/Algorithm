//finding the number connected components in an undirected graph
// BFS used only for undirected graphs
#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
class Graph                                                  
{   
    vector <vector<int>> Adj_list;                           
    int nvertices; 
    vector <bool> v;                                                // value=true if vertex has been discovered                        
    public:
        Graph(int V): nvertices(V)                                  // constructor           
        {
            Adj_list.assign(nvertices,vector<int>());  
            v.assign(nvertices,false);     
        };
        void insert (int a,int b);                                 // adds an edge
        int  connected_comp();                                     // returns the number of connected components 
        void BFS(int v);                                           
};

void Graph::insert(int a,int b)
{
    this->Adj_list[a].push_back(b);
    this->Adj_list[b].push_back(a);    
}                   

void Graph::BFS(int vertex)
{
    queue <int> q;                                                // keeps track of vertices
    
    this->v[vertex] = true;                                             
    q.push(vertex); 
 
    while(!q.empty())                                             // standard BFS algorithm
    { 
        int w = q.front();
        q.pop();
        for(auto i=this->Adj_list[w].begin();i!=this->Adj_list[w].end();i++)
        {
            if(!this->v[*i])
            {
                this->v[*i] = true; 
                q.push(*i); 
            }
        }
    }
}

int Graph::connected_comp()
{
    int count =0;
    for(int i=0;i<this->nvertices;i++)
    {
        if(!this->v[i])                                           // if not discovered, continue
        { 
            this->BFS(i);
            count++;
        }
    }
    return count;
}
// Driver program 
int main() 
{ 
    cout << " Enter the number of vertices and edges: ";
    int nodes, edges; 
    cin >> nodes >> edges; 
    cin.ignore();
    Graph g(nodes);
    int a, b; 
    for (int i = 0; i < edges; i++) 
    { 
        cout << "Enter the vertices in edge (x,y):  ";
        cin >> a >> b; 
        g.insert(a, b); 
        cin.ignore();
    }  
    cout << "Number of connected components in this undirected graph are: " << g.connected_comp();
} 
