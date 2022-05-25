#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int vertices;
        map<int, vector<int>> edgeList;

        explicit Graph(int ver){
            vertices = ver;
        }

        void addEdge(int x, int y){
            edgeList[x].push_back(y);
            edgeList[y].push_back(x);
        }

        vector<int>& getChildren(int vertex){
            return edgeList[vertex];
        }
};

void DFS(Graph* graph, int start, set<int>& visited){

    visited.insert(start);
    cout<<start<<" ";
    for(int child : graph->getChildren(start)){
        if(visited.count(child) == 0){
            DFS(graph, child, visited);
        }
    }
}

void BFS(Graph* graph, int start){
    
    queue<int> Q;
    set<int> visited;
    Q.push(start);
    while(!Q.empty()){
        int x = Q.front();
        cout<<x<<" ";
        Q.pop();
        visited.insert(x);
        
        for(int i : graph->getChildren(x)){
            if (visited.count(i) == 0){
                BFS(graph, i);
            }
        }
    }
}

int main() {
    int vertices;

    cin>>vertices;

    int edges;
    cin>>edges;

    Graph* g = new Graph(vertices);

    for(int i = 0; i<edges; i++){
        int x, y;
        cin>>x>>y;
        g->addEdge(x, y);
    }

    int start;
    cin>> start;
    set<int> visited;
    DFS(g, start, visited);
    BFS(g, start);


}


