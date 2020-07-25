#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph                                                            // Graph using vector 
{
    vector <vector<pair<int,int>>> Adj_list;                           // Ajacency list representation
    int nvertices;                                                     // number of vertices 
    public:
        Graph(int V): nvertices(V)                                     // constructor 
        {
            Adj_list.assign(nvertices,vector<pair<int,int>>());        // assigns n=nvertices elements of type vector <int> to each element in Adj_list
        };
        void insert (int a,int b,int w);                               // initialises graph
        void primalgo(int src);
};

void Graph::insert (int a,int b, int w)
{
    this->Adj_list[a].push_back(make_pair(b,w));
    this->Adj_list[b].push_back(make_pair(a,w));
}

void Graph::primalgo(int src)
{
    vector <int> key(nvertices,INT16_MAX);                          // keeping a track of weights
    vector <bool> isMST(nvertices,false);                           // keeps a track of vertices that are in MST
    vector <int> parent(nvertices,-1);                              // stores MST

    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;  // Speeds up the process
                                                                                        // Min MST

    key[src] = 0;                                                   
    isMST[src] = true;                                          // include source is MST

    pq.push(make_pair(key[src],src));

    while(!pq.empty())                                          // Continue till queue is not empty
    {
        int v = pq.top().second;
        pq.pop();

        isMST[v] = true;                                        // Add in MST

        for(auto i: Adj_list[v])                                // Iterate over all directly connected vertices
        {
            int w = i.first;        
            int weight = i.second;

            if(isMST[w]==false && key[w]>weight)                // if vertex not in MST and if weight is less than previously recorded weight
            {
                key[w] = weight;                                // update weight  
                parent[w] = v;                                  // update parent
                pq.push(make_pair(key[w],w));                   // add to min heap
            }
        }
    }

    for(int i=0;i<nvertices;i++)                               // print vertices that are a part of MST
    {
        if(parent[i]==-1)
            continue; 
        else
        {
            cout << i << "-->" << parent[i] << endl;
        }
    }

}

int main()                                                   // Driver function 
{ 

    int nodes, edges; 
    cin >> nodes >> edges; 
    Graph g(nodes);
    int a, b,w; 
    for (int i = 0; i < edges; i++) 
    { 
        cin >> a >> b>> w; 
        g.insert(a, b,w);
        cin.ignore(); 
    }

    g.primalgo(0);
} 
