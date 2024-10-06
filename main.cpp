#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v; // cities
    int cost; // cost to either build or destroy road
    bool existing; // true if it's an existing road, false if it needs to be built
};

// Function to convert a character to the corresponding cost
int charToCost(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';     // A-Z -> 0-25
    if ('a' <= c && c <= 'z') return c - 'a' + 26; // a-z -> 26-51
    return -1; // Invalid character
}

// Disjoint-set / Union-Find data structure for Kruskal's algorithm
struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true; // they were in different sets
        }
        return false; // they were already connected
    }
};

int main() {
    // Input format: 3 strings representing country, build, and destroy arrays
    string countryStr, buildStr, destroyStr;
    cin >> countryStr >> buildStr >> destroyStr;

    // First, we need to parse the input strings into proper 2D arrays
    vector<vector<int>> country, build, destroy;
    int n = 0;

    // Split the strings by commas to get each row for country, build, and destroy
    vector<string> countryRows, buildRows, destroyRows;

    string part;
    for (unsigned int i = 0; i < countryStr.length(); ++i) {
        if (countryStr[i] == ',') {
            countryRows.push_back(part);
            part = "";
        } else {
            part += countryStr[i];
        }
    }
    countryRows.push_back(part); // last part

    part = "";
    for (unsigned int i = 0; i < buildStr.length(); ++i) {
        if (buildStr[i] == ',') {
            buildRows.push_back(part);
            part = "";
        } else {
            part += buildStr[i];
        }
    }
    buildRows.push_back(part); // last part

    part = "";
    for (unsigned int i = 0; i < destroyStr.length(); ++i) {
        if (destroyStr[i] == ',') {
            destroyRows.push_back(part);
            part = "";
        } else {
            part += destroyStr[i];
        }
    }
    destroyRows.push_back(part); // last part

    n = countryRows.size(); // number of cities

    country.resize(n, vector<int>(n));
    build.resize(n, vector<int>(n));
    destroy.resize(n, vector<int>(n));

    // Convert country, build, and destroy strings into 2D arrays
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            country[i][j] = countryRows[i][j] - '0';
            build[i][j] = charToCost(buildRows[i][j]);
            destroy[i][j] = charToCost(destroyRows[i][j]);
        }
    }

    // Step 2: Create the list of edges (roads)
    vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) { // only consider upper triangular part (undirected)
            if (country[i][j] == 1) { // Existing road
                int costToDestroy = destroy[i][j];
                edges.push_back({i, j, costToDestroy, true});
            }
            int costToBuild = build[i][j];
            edges.push_back({i, j, costToBuild, false});
        }
    }

    // Step 3: Sort edges by cost
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.cost < b.cost;
    });

    // Step 4: Kruskal's algorithm to find the MST
    UnionFind uf(n);
    int totalCost = 0;
    int edgeCount = 0;

    for (const auto& edge : edges) {
        if (uf.unite(edge.u, edge.v)) { // If this edge connects two different components
            totalCost += edge.cost;
            edgeCount++;
            if (edgeCount == n - 1) break; // MST is complete
        }
    }

    // Output the minimal cost
    cout << totalCost << endl;

    return 0;
}
