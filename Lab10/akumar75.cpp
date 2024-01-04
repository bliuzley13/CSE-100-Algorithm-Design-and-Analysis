#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

//Represents Directed Graph
class Graph {
    //Number of Vertices
    int V;
    //Stores adjency list
    vector<vector<int>> adj;

public:
    //Has constructor that initializes number of vertices and adjacency list
    Graph(int vertices) : V(vertices), adj(vertices) {}
    //Method to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    //Depth-First Search function 
    void DFS(int v, vector<bool>& checked, stack<int>& stck) {
        checked[v] = true;
        //Performs depth-first traversal starting from vertex v
        for (int folNeighbor : adj[v]) {
            //Marks current vertex as listed
            if (!checked[folNeighbor]) {
                //Recursively calls DFS for unvisited neighbors
                DFS(folNeighbor, checked, stck);
            }
        }
        //Pushes vertex onto stack to be used later in topological sorting
        stck.push(v);
    }
    //Helper function used to assign SCC indices to vertices
    void DFSHelper(int v, vector<bool>& checked, vector<int>& SCC, int SCCIndex) {
        //Marks current vertex as visited
        checked[v] = true;
        //Assigns SCC Index
        SCC[v] = SCCIndex;

        for (int folNeighbor : adj[v]) {
            if (!checked[folNeighbor]) {
                //Recursively calls for all unvisited neighbors
                DFSHelper(folNeighbor, checked, SCC, SCCIndex);
            }
        }
    }
    //Returns the transpose of the graph
    Graph getTranspose() {
        Graph transpose(V);
        //Reverses direction of all edges
        for (int v = 0; v < V; ++v) {
            for (int neighbor : adj[v]) {
                transpose.addEdge(neighbor, v);
            }
        }

        return transpose;
    }
    //Finds strongly connected components using Kosaraju's algorithm
    vector<int> searchSCC() {
        stack<int> stck;
        vector<bool> checked(V, false);
        //Performs first DFS traversal on original graph
        for (int v = 0; v < V; ++v) {
            if (!checked[v]) {
                //Fills stack with vertices in the order of their finishing times
                DFS(v, checked, stck);
            }
        }
        //Gets transpose of the graph
        Graph transpose = getTranspose();

        fill(checked.begin(), checked.end(), false);

        vector<int> SCC(V, -1);
        int SCCIndex = 0;
        //Second DFS traversal on transpose graph to find SCCs
        while (!stck.empty()) {
            int v = stck.top();
            stck.pop();
            //Performs second DFS traversal on transpose graph
            if (!checked[v]) {
                //Assigns SCC indices to vertices
                transpose.DFSHelper(v, checked, SCC, SCCIndex);
                SCCIndex++;
            }
        }
        //Returns vector SCC where each element is the SCC index of corresponding vertex
        return SCC;
    }
};

int main() {
    int V, E;
    //Reads number of vertices and edges
    cin >> V >> E;
    
    Graph graph(V);

    //Constructs graph with the edges
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }
    //Finds SCCs and assigns new SCC Ids based on smallest index in each SCC
    vector<int> SCC = graph.searchSCC();

    unordered_map<int, int> theMap;
    //Assigns new SCC IDs based on smallest index in each SCC
    for (int i = 0; i < V; ++i) {
        if (theMap.find(SCC[i]) == theMap.end() || theMap[SCC[i]] > i) {
            theMap[SCC[i]] = i;
        }
    }
    //Outputs SCC IDs
    for (int i = 0; i < V; ++i) {
        cout << theMap[SCC[i]] << endl;
    }

    return 0;
}
