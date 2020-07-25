#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Disjoint{                                             //Disjoint set data structure for implementing Union Find algorithm
        vector <int> rank;
        vector <int> parent;
        int vertices;
    public:
        Disjoint(int n);                                   // Constructor 
        int find(int x);
        void union_(int v,int u);
        ~Disjoint() {};                                    // Destructor 
};

Disjoint::Disjoint(int n)
{
    vertices = n;
    rank.assign(vertices,0);
    parent.assign(vertices,0);
    for(int i=0;i<n;i++)
        parent[i] = i;
}

int Disjoint::find(int x)                                  // Union Find using Rank
{                                                          // Smaller depth tree is attached under the root of larger depth tree
    if(parent[x]!=x)                                       // Improves time complexity from O(n) to O(log n)
        parent[x] = find(parent[x]);
    return parent[x];
}

void Disjoint::union_(int v,int u)                          // Merges two sub sets 
{                                                           // Path compression optimiziation improves time complexity from linear to logarithmic 
    int vroot = find(v);
    int uroot = find(u);

    if(rank[vroot]>rank[uroot])
        parent[uroot] = vroot;
    else if(rank[vroot]<rank[uroot])
        parent[vroot] = uroot;
    else
    {
        parent[vroot] = uroot;
        rank[uroot]++;                                      // Rank updated by one if rank of both the subsets is same otherwise
    }                                                       // Rank of the new subset is equal to the larger of the two ranks
}

class Graph{
        int N,E;
        vector <pair<int,pair<int,int>> > Adj_list;         // stores edge as a pair of weight and two end points

    public:
        Graph(int n,int e);
        void insert(int u,int v,int w);                     // initialises the graph
        void kruskals(Disjoint &ds);                        // prints vertices included in MST
        ~Graph(){};
};

Graph::Graph(int n,int e)
{
    N = n;
    E = e;
}

void Graph::insert(int u, int v, int w)
{
    Adj_list.push_back({w,{v,u}});
}

void Graph::kruskals(Disjoint& ds)
{
    sort(Adj_list.begin(),Adj_list.end());                 // sorts edges according to their weights in ascending order

    for(auto i:Adj_list)                                   // iterate through all the edges 
    {
        int x = i.second.first;
        int y = i.second.second;

        int xroot = ds.find(x);
        int yroot = ds.find(y);

        if(xroot!=yroot)                                  // add the edge in MST if it does not form a cycle
        {
            cout<< x << "-->" << y << endl;
            ds.union_(x,y);                               // merge the two subsets                        
        }
    }
}

int main()                                                 // Driver Function
{ 
    int V, E;
    cin >> V >> E; 
    Graph g(V,E); 
    Disjoint ds(V);

    int a, b,w; 
    for (int i = 0; i < E; i++) 
    { 
        cin >> a >> b>> w; 
        g.insert(a, b,w);
        cin.ignore(); 
    }
    

    g.kruskals(ds); 
    return 0; 

}
