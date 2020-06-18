//shortest path algorithm using vectors
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
        Graph(int V): nvertices(V)                                   // constructor           
        {
            Adj_list.assign(nvertices,vector<int>());       
        };
        void insert (int a,int b);                                  // initializing 
        void print_path(int star,int end);                          // prints the shortest distance and the path        
        bool BFS(int start,int end,vector <int>&pred,vector<int>&dist);  // calculates shortest distance from src to dest
};

void Graph::insert(int a,int b)
{
            this->Adj_list[a].push_back(b);
            this->Adj_list[b].push_back(a);                       // comment this line for directed graphs 
}

bool Graph::BFS(int start,int end,vector<int>&pred,vector<int> &dist)
{
    queue <int> q;                                                // keeps track of vertices
    vector <bool> v;                                              // keeps track of vertices that have been discovered 

    pred.assign(this->nvertices,-1);                              // predecessor of a given vertex
    dist.assign(this->nvertices,INT_MAX);                         // stores distance of a given vertext from src
    v.assign(this->nvertices,false);

    v[start] = true;                                              // src is first to be visited 
    dist[start] = 0;                                              // distance from src to src should be zero
    q.push(start); 
 
    while(!q.empty())                                             // standard BFS algorithm
    { 
        int w = q.front();
        q.pop();
        for(auto i=this->Adj_list[w].begin();i!=this->Adj_list[w].end();i++)
        {
            if(!v[*i])
            {
                pred[*i] = w;
                dist[*i] = dist[w] +1;
                v[*i] = true; 
                q.push(*i);
            
                 if (*i == end)                                    // stop BFS if destination is found
                    return true; 
            }
        }
    }
    return false;
}

void Graph::print_path(int start, int end)
{
    vector <int> pred;
    vector <int> dist;
    
    if(this->BFS(start,end,pred,dist)==false)
    {
        cout << "No path from " << start << " to " << end << endl;
        return; 
    }
    vector <int> path;                                             // stores the shortest path
    int first = end;
    path.push_back(first);
    while(pred[first]!=-1)
    {
        path.push_back(pred[first]);
        first = pred[first];
    }

    cout << "Source is " << start << "destination is " << end << endl; 

    cout << "Shortest path length is: "                               // distance from source is in distance array 
         << dist[end]; 
  
    cout << "\nPath is::\n";                                          // printing path from source to destination  
    for (int i = path.size() - 1; i >= 0; i--) 
        cout << path[i] << " ";

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
    cout << "Enter source and destination: ";
    int start,end;
    cin >> start >> end;
    cin.ignore();
    g.print_path(start,end);
    return 0;; 
} 
