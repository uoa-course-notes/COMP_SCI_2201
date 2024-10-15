#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype> // for isspace
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, cost;
    Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
};

// Comparison function to sort edges by cost (ascending)
bool compare(const Edge &a, const Edge &b) {
    return a.cost < b.cost;
}

// Union-Find (Disjoint Set) Class
class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find function with path compression
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    // Union function with union by rank
    bool unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
            return true;
        }
        return false;
    }
};

// Convert character to cost
int charToCost(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';       // A-Z -> 0-25
    if ('a' <= c && c <= 'z') return c - 'a' + 26;  // a-z -> 26-51
    return -1;  // Invalid character
}

// Helper function to parse matrix input from a comma-separated string
vector<vector<int>> parseMatrix(const string &matrixStr) {
    vector<vector<int>> matrix;
    vector<int> row;
    for (char c : matrixStr) {
        if (c == ',') {
            matrix.push_back(row);  // Add the completed row
            row.clear();  // Start a new row
        } else {
            row.push_back(c - '0');  // Convert char to integer ('0' -> 0, '1' -> 1, etc.)
        }
    }
    matrix.push_back(row);  // Push the last row
    return matrix;
}

// Helper function to parse cost matrices from a comma-separated string
vector<vector<int>> parseCostMatrix(const string &matrixStr) {
    vector<vector<int>> matrix;
    vector<int> row;
    for (char c : matrixStr) {
        if (c == ',') {
            matrix.push_back(row);
            row.clear();
        } else {
            row.push_back(charToCost(c));  // Convert character to cost
        }
    }
    matrix.push_back(row);
    return matrix;
}

// Trim whitespace from the beginning and end of a string
string trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos) return ""; // no content
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Calculate minimum road reconstruction cost
int calculateMinimumCost(const string &countryStr, const string &buildStr, const string &destroyStr) {
    vector<vector<int>> country = parseMatrix(countryStr);
    vector<vector<int>> build = parseCostMatrix(buildStr);
    vector<vector<int>> destroy = parseCostMatrix(destroyStr);

    int n = country.size();  // Number of cities

    vector<Edge> edges;

    // Build the edge list considering both building and destroying roads
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (country[i][j] == 1) {
                edges.emplace_back(i, j, destroy[i][j]); // Destroy road cost
            } else {
                edges.emplace_back(i, j, build[i][j]); // Build road cost
            }
        }
    }

    sort(edges.begin(), edges.end(), compare);

    UnionFind uf(n);
    int total_cost = 0;

    for (const Edge &edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            total_cost += edge.cost;  // Only add the cost if it connects two unconnected components
        }
    }

    return total_cost;  // Return the total minimum cost
}

int main() {
    // ifstream inputFile("test.txt");  // Open the input file
    // string line;

    // if (!inputFile.is_open()) {
    //     cerr << "Error opening file!" << endl;
    //     return 1;
    // }

    // while (getline(inputFile, line)) {
    //     if (line.empty()) continue;  // Skip empty lines

    //     // Split input and expected output based on whitespace
    //     stringstream ss(line);
    //     string input, expectedOutputStr;
    //     getline(ss, input, '\t');  // Assuming tab separation; use space if needed

    //     // Get expected output
    //     getline(ss, expectedOutputStr);
    //     expectedOutputStr = trim(expectedOutputStr);  // Trim any whitespace
    //     int expectedOutput = 0;

    //     try {
    //         expectedOutput = stoi(expectedOutputStr);  // Convert expected output to integer
    //     } catch (const invalid_argument &e) {
    //         cerr << "Invalid expected output format: " << expectedOutputStr << endl;
    //         continue;
    //     }

    //     // Parse the input string
    //     size_t firstSpace = input.find(" ");
    //     size_t secondSpace = input.find(" ", firstSpace + 1);

    //     string countryStr = input.substr(0, firstSpace);
    //     string buildStr = input.substr(firstSpace + 1, secondSpace - firstSpace - 1);
    //     string destroyStr = input.substr(secondSpace + 1);

    //     // Calculate the minimum cost
    //     int result = calculateMinimumCost(countryStr, buildStr, destroyStr);

    //     // Print the result and compare it with the expected output
    //     cout << "Input: " << line << endl;  // Full input line for debugging
    //     cout << "Computed Output: " << result << ", Expected Output: " << expectedOutput << endl;
    //     cout << (result == expectedOutput ? "Test Passed!" : "Test Failed!") << endl;
    // }

    // inputFile.close();  // Close the file
    
    return 0;
}









/*

000,000,000 ABD,BAC,DCA ABD,BAC,DCA    3
011,101,110 ABD,BAC,DCA ABD,BAC,DCA    1
011000,101000,110000,000011,000101,000110 ABDFFF,BACFFF,DCAFFF,FFFABD,FFFBAC,FFFDCA ABDFFF,BACFFF,DCAFFF,FFFABD,FFFBAC,FFFDCA    7
0 A A    0
0001,0001,0001,1110 AfOj,fAcC,OcAP,jCPA AWFH,WAxU,FxAV,HUVA    0
0000000000,0000000011,0001010000,0010010000,0000001000,0011000000,0000100000,0000000011,0100000101,0100000110 AhPEqkSFMM,hAfKPtsDad,PfAyGQkaqN,EKyAeLpRpm,qPGeASfNwo,ktQLSAnCAK,SskpfnAdJS,FDaRNCdAZz,MaqpwAJZAn,MdNmoKSznA AgTqWWxEYH,gAXPgjzIRA,TXAleTmWvT,qPlAQkwxRO,WgeQAqgbJJ,WjTkqAiTzl,xzmwgiAuHb,EIWxbTuAwk,YRvRJzHwAn,HATOJlbknA    65
0111111,1011111,1101111,1110111,1111011,1111101,1111110 AzvpNrk,zAFfVLm,vFAaDFn,pfaAESX,NVDEAco,rLFScAx,kmnXoxA AzeGcYA,zAgCTsQ,egAPSNK,GCPANfu,cTSNAIz,YsNfIAt,AQKuztA    233
01,10 AB,BA AJ,JA    0
00,00 Ak,kA AS,SA    36

*/