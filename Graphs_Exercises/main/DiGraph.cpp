#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

// a directed graph class 
class DiGraph {
    int V; // No. of vertices

    // Pointer to an array containing adjacency lists 
    vector <list<int>> adjList; // array of lists<int>
public:
    DiGraph(int V);  // Constructor 

    // add an edge from vertex v to w
    void addEdge(int v, int w);

    // BFS traversal sequence starting with s ->starting node 
    void BFS(int s);
};

DiGraph::DiGraph(int V) {
    this->V = V;
    auto tmp = vector < list < int >> (V);
    adjList = tmp;
}

void DiGraph::addEdge(int v, int w) {
    adjList.at(v).push_back(w); // Add w to v’s list.
}

void DiGraph::BFS(int s) {
    // initially none of the vertices is visited
    vector<bool> visited(V, false);

    // queue to hold BFS traversal sequence
    queue<int> queue;

    // Mark the current node as visited and enqueue it 
    visited.at(s) = true;
    queue.push(s);

    // iterator 'i' to get all adjacent vertices 
    list<int>::iterator i;

    while (!queue.empty()) {
        // dequeue the vertex 
        s = queue.front();
        cout << s << " ";
        queue.pop();

        // get all adjacent vertices of popped vertex and process
        // each if not already visited 
        for (i = adjList[s].begin(); i != adjList[s].end(); ++i) {
            if (!visited.at(*i)) {
                visited.at(*i) = true;
                queue.push(*i);
            }
        }
    }

}

// main program
int main() {
    // create a graph 
    DiGraph dg(5);
    dg.addEdge(0, 1);
    dg.addEdge(0, 2);
    dg.addEdge(0, 3);
    dg.addEdge(1, 2);
    dg.addEdge(2, 4);
    dg.addEdge(3, 3);
    dg.addEdge(4, 4);

    cout << "Breadth First Traversal for given graph (with 0 as starting node): " << endl;
    dg.BFS(0);

    return 0;
}
