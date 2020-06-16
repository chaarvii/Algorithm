// BFS using STL
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph                                                  // Graph using vector 
{
    vector <vector<int>> Adj_list;                           // Ajacency list representation
    int nvertices;                                           // number of vertices 
    public:
        Graph(int V): nvertices(V)                           // constructor 
        {
            Adj_list.assign(nvertices,vector<int>());       // assigns n=nvertices elements of type vector <int> to each element in Adj_list
        };
        void insert (int a,int b)                           // initialises graph
        {
            Adj_list[a].push_back(b);
            Adj_list[b].push_back(a);                       // comment this line for directed graphs 
        }
        void print_graph()                                  // prints graph
        {
            for(auto i=0;i<nvertices;i++)
            {
                cout << i+1 << " --> "; 
                for(auto j = Adj_list[i].begin();j!=Adj_list[i].end();j++)
                {
                    cout << *j;
                    if(j+1!=Adj_list[i].end())                              // for better visual representation
                        cout << " --> ";                                   // adds a arrow only if one more element is present
                }
                cout << endl;
            }
        }
        void BFS(int vertex)                                  // performs Breadth First Search
        {
            vector <bool> v;                                 // if vertex undiscovered then false else true

            v.assign(nvertices,false);
            v[vertex] = true;
            queue <int> q;                                  // queue for storing vertices as they get discovered
            q.push(vertex);
            while(!q.empty())
            {
                int w = q.front();
                cout << w << " ";                          // prints current vertex
                q.pop();
                for(auto i=Adj_list[w].begin();i!=Adj_list[w].end();i++)
                {
                    if(!v[*i])                             // if not discovered, adds element to queue
                    {
                        q.push(*i);
                        v[*i] = true;
                    }
                }
            }

        }
};

// Driver program 
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
    } 
    g.print_graph();
    g.BFS(1);
    return 0; 
} 
