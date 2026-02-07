#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include<stack>
using namespace std;
class Graph{
    int V;
    vector<vector<int>>adj;
    public: 
    Graph(int V){
        this->V=V;
        adj.resize(V);
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void DFSTraverse(int node){
        vector<bool>visited(V, false);
        cout<<node<<" ";
        stack<int>stk;
        stk.push(node);
        while(!stk.empty()){
            int node=stk.top();
            stk.pop();
                cout<<node<<endl;
                for(int adj:adj[node]){
                    if(!visited[adj]){
                        stk.push(adj);
                        visited[adj]=true;
                }
            }
        }
    }
};
int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "DFS: ";
    g.DFSTraverse(0);



    return 0;
}
