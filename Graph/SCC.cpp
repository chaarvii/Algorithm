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
        void DFS(int s,vector<bool>&v);                      // standard DFS algorithm
        void finishingTime(int s, vector<bool>&v,stack<int>&stk);  // calculates the finishing time of each vertex
        Graph getTranspose();                                // reverses all the edges in the graph
        void printSCC();                                     // prints the strongly connected components of the graph
};

void Graph::insert (int a,int b)
{
    this->Adj_list[a].push_back(b);
}

void Graph::DFS(int s,vector<bool>&v)
{
    v[s] = true;
    cout << s << " ";
    for(auto i=this->Adj_list[s].begin();i!=this->Adj_list[s].end();i++)
    {
        if(!v[*i])
            this->DFS(*i,v);
    }                                           
}
void Graph::finishingTime(int s, vector<bool>&v,stack<int>&stk)
{
    v[s] = true;
    for(auto i=this->Adj_list[s].begin();i!=this->Adj_list[s].end();i++)
    {
        if(!v[*i])
            this->finishingTime(*i,v,stk);
    }
    stk.push(s);                                                        // for storing vertices in the order of their finishing time                                         
}

Graph Graph::getTranspose(){
    Graph gr(this->nvertices);
    for(int j=0;j<this->nvertices;j++)
        for(auto i=this->Adj_list[j].begin();i!=this->Adj_list[j].end();i++)
            gr.Adj_list[*i].push_back(j);
    return gr;
}

void Graph::printSCC()
{
    vector <bool> v;
    v.assign(this->nvertices,false);
    stack <int> stk;

    for(auto i = 0;i<this->nvertices;i++)                           // Step 1: compute finishing time
        if(!v[i])
            this->finishingTime(i,v,stk);

    Graph gr = this->getTranspose();                                // Step 2: Reverse all the edges 

    v.assign(this->nvertices,false);
    while(!stk.empty())
        {
            int k = stk.top();                     
            stk.pop();
            if(!v[k])
            {   
                gr.DFS(k,v);                                       // Step 3: perform DFS on all vertices in the order of their finishing times
                cout<< ";";
            }
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
    cout << "Following are strongly connected components in "
            "given graph \n"; 
    g.printSCC();
}
