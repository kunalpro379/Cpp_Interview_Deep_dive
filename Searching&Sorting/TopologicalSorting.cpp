#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> TopoSort(int V, vector<vector<int>>&adj){
    ///store the indegrees
    vector<int>indeg(V,0);
    for(int u=0;u<V;u++)for(int v:adj[u])indeg[v]++;
    queue<int>Q;
    //push nodes with indeg 0
    //matlab nodes jinpe koi dependency nahi hain
    for(int i=0;i<V;i++){
        if(indeg[i]==0)Q.push(i);
    }
    //Start the BFS process
    vector<int>Topu;
    while(!Q.empty()){
        int node=Q.front();
        Q.pop();
        Topu.push_back(node);
        for(int N:adj[node]){
            indeg[N]--;
            if(indeg[N]==0)Q.push(N);
        }

    }
    return Topu;

}
int main(){
    int V=10;
    vector<vector<int>>adj(V);
    adj[5].push_back(2);
    adj[5].push_back(0);
        adj[4].push_back(0);
    adj[4].push_back(1);
        adj[2].push_back(3);
    adj[3].push_back(1);
    vector<int>topu=TopoSort(V, adj);
    for(auto &it: topu){
        cout<<it<<endl;
    }

    return 0;
    
}