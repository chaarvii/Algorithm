#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    int V;                                                  // number of vertices
    vector < pair<int,int> > *Adj_list;                       // stores the graph
    public:
    Graph(int V);                                           // constructor
    void add_edge(int u,int v,int wt);                      // adds an edge to the graph
    void shortest_path(int s);                              // computes the sortest path of all indices from a given index
};

Graph::Graph(int V)
{
    this->V = V;
    Adj_list = new vector<pair<int,int>> [V];
}

void Graph::add_edge(int u,int v,int wt)
{
    Adj_list[u].push_back(make_pair(v,wt));
    Adj_list[v].push_back(make_pair(u,wt));
}

void Graph::shortest_path(int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> >> pq;     // queue for storing index number and weight pair
    vector <int> dist(V,INT_MAX);                                                       // stores shortest distance
    vector <bool> flag(V,false);                                                        // optimization step, keeps a tab of vertices that have been updates
    pq.push(make_pair(s,0));
    dist[s] =0;                                                                         // distance for starting index is zero
    flag[s] = true;
    while(!pq.empty())                                                                  // loop over it till priority_queue not empty
    {
        int w = pq.top().first;
        pq.pop();
        flag[w] = true;
        for(auto i=Adj_list[w].begin();i!=Adj_list[w].end();i++)
        {
            int v = (*i).first;
            int wt = (*i).second;

            if(dist[v]>dist[w] + wt&& flag[v]==false)                                                   // if new distance is smaller than current distance then update
            {
                dist[v] = dist[w]+wt;
                pq.push(make_pair(v,dist[v]));
            }
        }
    }

    printf("Vertex  Distance from vertex\n");                                                           // print shortest distance
    for(int i=0;i<V;i++)
        printf("%d \t\t %d\n",i,dist[i]);
}

// driver index
int main()
{
    Graph g(9);
    int u,v,wt;
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v >> wt;
        g.add_edge(u,v,wt);
        cin.ignore();
    }
    g.shortest_path(0);
}
