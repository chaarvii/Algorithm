//finding if the graph is bipartite
#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
class Graph                                                  
{   
    vector <vector<int>> Adj_list;                           
    int nvertices;                                                                        
    public:                                                      
        Graph(int V): nvertices(V)                                // constructor           
        {
            Adj_list.assign(nvertices,vector<int>());     
        };
        void insert (int a,int b);                                // reading/initializing the graph
        bool TwoColor(int v);                                           
};

void Graph::insert(int a,int b)
{
    this->Adj_list[a].push_back(b);
    this->Adj_list[b].push_back(a);    
}                   

bool Graph::TwoColor(int vertex)
{
    vector <int> color;                                         // stores color/label assigned to the vertex
    vector <bool> v;                                            // false if vertex has not been discovered yet
    queue <int> q; 
    
    color.assign(nvertices,-1); 
    v.assign(nvertices,false);

    q.push(vertex);
    v[vertex] = true; 
    color[vertex] = 1;
 
    while(!q.empty())                                             
    { 
        int w = q.front();
        q.pop();
        for(auto i=this->Adj_list[w].begin();i!=this->Adj_list[w].end();i++)
        {
            if(*i==w)                                        // check if self loop exists
                return false;
            
            else if(color[*i]==-1&&!v[*i])                   // edge from w to i exists but i not colored 
            {
                color[*i] = 1 -color[w];                     // assign alernate color 
                v[*i] = true; 
                q.push(*i); 
            }

            else if(color[*i]==color[w]&&v[*i])              // edge from w to i exists but color of both vertices is same 
                return false;                                // graph can not be bipartite 
        }
    }
    return true;
}
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
    g.TwoColor(0) ? cout << "Yes" : cout << "No"; 
} 
