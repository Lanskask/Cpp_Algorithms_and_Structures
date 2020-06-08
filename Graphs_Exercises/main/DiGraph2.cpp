#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

// header info
class DiGraph {
private:
    int V;
    vector<list<int>> adjList;

public:
    DiGraph(int V);

    void addEdge(int v, int w);
    void BFS(int s);
    void process_edge(int edge);

    ~DiGraph();
};

// constructor, destructor
DiGraph::DiGraph(int V) {
    this->V = V;
    auto tmp = vector<list<int>>(V);
    adjList = tmp;
}

DiGraph::~DiGraph() {}

// Functions
void DiGraph::addEdge(int a, int b) {
    adjList.at(a).push_back(b); // add b edge to the list of connected edges of a
}

void DiGraph::process_edge(int edge) {
    cout << edge << " ";
}

void DiGraph::BFS(int s) {
    vector<bool> visited(V, false);
    queue<int> queue;

    visited[s] = true;
    queue.push(s);

    while(!queue.empty()) {
        s = queue.front();
        DiGraph::process_edge(s);

        queue.pop();

        for(int i : adjList[s]) {
            if(!visited.at(i)) {
                visited.at(i) = true;
                queue.push(i);
            }
        }
    }
}

// Main method
int main() {
    DiGraph dg(5);
    dg.addEdge(0, 1); 
    dg.addEdge(0, 2); 
    dg.addEdge(0, 3);
    dg.addEdge(1, 2); 
    dg.addEdge(2, 4);
    dg.addEdge(3, 3); 
    dg.addEdge(4, 4);
   
    cout << "Breadth First Traversal for given graph (with 0 as starting node): "<<endl;
    dg.BFS(0);
    cout << endl;

    return 0;
}