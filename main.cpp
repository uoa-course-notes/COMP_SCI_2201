#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits> // For INT_MAX
#include <cctype>  // For character checking
#include <tuple>


using namespace std;

class Graph {
public:
    int dimension;
    vector<vector<int>> graph;

    // Constructor to initialize the graph with infinity weights
    Graph(int dimension) : dimension(dimension), graph(dimension, vector<int>(dimension, INT_MAX)) {}

    // Function to convert character to cost
    int char_to_cost(char c) {
        if ('A' <= c && c <= 'Z') {
            return c - 'A'; // A-Z -> 0-25
        } else if ('a' <= c && c <= 'z') {
            return c - 'a' + 26; // a-z -> 26-51
        }
        return 0; // Return 0 for any invalid character
    }

    // Function to set edge weights in the graph based on country, destroy, and build matrices
    void set_edge_weight(const vector<vector<int>>& country, const vector<vector<char>>& destroy, const vector<vector<char>>& build) {
        for (int i = 0; i < dimension; ++i) {
            for (int j = 0; j < dimension; ++j) {
                if (country[i][j] == 1) {
                    graph[i][j] = -char_to_cost(destroy[i][j]); // Use destruction cost as negative
                } else {
                    graph[i][j] = char_to_cost(build[i][j]); // Use build cost
                }
            }
        }
    }

    // Prim's algorithm to find the Minimum Spanning Tree (MST)
    int prim_mst(const vector<vector<int>>& country) {
        int total_cost = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        vector<int> min_cost(dimension, INT_MAX);
        vector<bool> visited(dimension, false);
        min_cost[0] = 0;
        min_heap.push({0, 0}); // (cost, vertex)

        while (!min_heap.empty()) {
            auto [cost, u] = min_heap.top();
            min_heap.pop();

            if (visited[u]) continue;

            visited[u] = true;
            total_cost += cost;

            for (int v = 0; v < dimension; ++v) {
                if (!visited[v] && graph[u][v] < min_cost[v]) {
                    min_cost[v] = graph[u][v];
                    min_heap.push({graph[u][v], v});
                }
            }
        }

        // Calculate total destruction cost for roads that should be destroyed
        int total_destruction_cost = 0;
        for (int i = 0; i < dimension; ++i) {
            for (int j = i + 1; j < dimension; ++j) {
                if (country[i][j] == 1) {
                    total_destruction_cost -= graph[i][j]; // Accumulate destruction costs
                }
            }
        }

        return total_cost + total_destruction_cost;
    }

    // Main function to calculate minimal reconstruction cost
    int minimal_reconstruction(const vector<vector<int>>& country, const vector<vector<char>>& destroy, const vector<vector<char>>& build) {
        set_edge_weight(country, destroy, build);
        return prim_mst(country);
    }
};

// Function to parse input from a string
tuple<vector<vector<int>>, vector<vector<char>>, vector<vector<char>>> parse_input(const string& input_str) {
    string road_str, construc_str, destruct_str;
    size_t space_pos1 = input_str.find(' ');
    size_t space_pos2 = input_str.find(' ', space_pos1 + 1);
    road_str = input_str.substr(0, space_pos1);
    construc_str = input_str.substr(space_pos1 + 1, space_pos2 - space_pos1 - 1);
    destruct_str = input_str.substr(space_pos2 + 1);

    // Helper function to split and parse a matrix string
    auto parse_matrix = [](const string& matrix_str) {
        vector<string> rows;
        string row;
        for (char c : matrix_str) {
            if (c == ',') {
                rows.push_back(row);
                row.clear();
            } else {
                row += c;
            }
        }
        rows.push_back(row); // Add the last row
        return rows;
    };

    vector<vector<int>> country;
    vector<vector<char>> build, destroy;

    auto country_rows = parse_matrix(road_str);
    auto build_rows = parse_matrix(construc_str);
    auto destroy_rows = parse_matrix(destruct_str);

    // Convert to integer/cost matrices
    for (const string& row : country_rows) {
        vector<int> country_row;
        for (char c : row) {
            country_row.push_back(c - '0');
        }
        country.push_back(country_row);
    }

    for (const string& row : build_rows) {
        vector<char> build_row;
        for (char c : row) {
            build_row.push_back(c);
        }
        build.push_back(build_row);
    }

    for (const string& row : destroy_rows) {
        vector<char> destroy_row;
        for (char c : row) {
            destroy_row.push_back(c);
        }
        destroy.push_back(destroy_row);
    }

    return {country, build, destroy};
}

int main() {
    string input_str;
    getline(cin, input_str); // Read the input string
    auto [country, build, destroy] = parse_input(input_str);
    Graph g(country.size());
    int cost = g.minimal_reconstruction(country, destroy, build);
    cout << cost << endl;
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