#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <list>
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
    void BFSTraverse(int start){
        //push start node in the queue mark visited
        //while queue is not empty
        // pop and visit neighbors and push 
        vector<bool>visited(V, false);
        queue<int>Q;
        visited[start]=true;
        Q.push(start);
        while(!Q.empty()){
            int node=Q.front();
            Q.pop();
            cout<<node<<" ";
            for(int neighbor: adj[node]){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    Q.push(neighbor);
                }
            }
        }cout<<endl;
    }
};
int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "BFS: ";
    g.BFSTraverse(0);


    return 0;
}