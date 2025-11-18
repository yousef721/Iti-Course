#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;


// Each node contains:
    // - id: the node index
    // - color: the color assigned (-1 means uncolored)
struct Node {
    int id;
    int color;
};

/*
===============================================================
                GREEDY GRAPH COLORING FUNCTION
===============================================================
Goal:
-----
Assign colors to all nodes so that:
    - Adjacent nodes never share the same color
    - Use as few colors as possible using a greedy strategy

Method:
-------
For each node:
    1. Look at all neighbors
    2. Mark their colors as "used"
    3. Assign the smallest available color
===============================================================
*/
vector<int> colorGraph(const vector<vector<int>>& adj) {

    int n = adj.size();                  // number of nodes
    vector<int> colors(n, -1);           // initially all nodes are uncolored (-1)

    // STEP 1: Process each node in order 0 → n-1
    for (int u = 0; u < n; u++) {

        // used[color] = true means this color cannot be used
        vector<bool> used(n + 1, false);

        // STEP 2: Check all neighbors and mark their colors
        for (int v : adj[u]) {
            if (colors[v] != -1) {       // neighbor v already has a color
                used[colors[v]] = true;  // mark color as unavailable
            }
        }

        // STEP 3: Find smallest unused color
        int color = 1;
        while (used[color]) {
            color++;
        }

        // STEP 4: Assign the color
        colors[u] = color;
    }

    return colors;   // return final color assignment
}

/*
===============================================================
                            MAIN
===============================================================
Reads:
------
    n → number of nodes
    m → number of edges
    m lines: each contains (u v) meaning an edge between u and v

Builds an adjacency list, colors the graph, prints results.
===============================================================
*/
int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);  // adjacency list

    // Read all edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph → store both ways
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Color the graph
    vector<int> result = colorGraph(adj);

    // Print final colors
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
===============================================================
                PROGRAM EXPLANATION (STEP BY STEP)
===============================================================

1. PROBLEM:
---------------------------------------------------------------
    Color each node in a graph such that:
        - No two adjacent nodes have the same color
        - Colors are represented by numbers: 1, 2, 3, ...
        - Use a greedy method to minimize number of colors

---------------------------------------------------------------
2. HOW REPRESENTATION WORKS:
---------------------------------------------------------------
    We use an adjacency list:
        adj[u] contains all neighbors of node u

---------------------------------------------------------------
3. HOW GREEDY COLORING WORKS:
---------------------------------------------------------------
    For each node u:
        - Look at all neighbors (adj[u])
        - Collect the colors they already use
        - Forbid those colors
        - Choose the smallest available color

---------------------------------------------------------------
4. EXAMPLE:
---------------------------------------------------------------
    Input:
        4 5
        0 1
        0 2
        1 2
        1 3
        2 3

    Graph:
        0 connected to 1,2
        1 connected to 0,2,3
        2 connected to 0,1,3
        3 connected to 1,2

    Possible Output:
        1 2 3 1

    Meaning:
        Node 0 → color 1  
        Node 1 → color 2  
        Node 2 → color 3  
        Node 3 → color 1  

---------------------------------------------------------------
5. COMPLEXITY:
---------------------------------------------------------------
    Time complexity:  O(V + E)
    Space complexity:  O(V)
    
===============================================================
*/
