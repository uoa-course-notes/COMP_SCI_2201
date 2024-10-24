#include <iostream>
#include <list>
#include <queue>
#include <map>
#include <forward_list>


// // Stores adjacency list items
// struct AdjNode{
//     int val, cost;
//     AdjNode* next;
// };


// // Structure to store edges
// struct graphEdge{
//     int start_vert, end_vert, weight;
// };

// class DiGraph{
//     private:
//         AdjNode** head;
//         int N; // number of vertices in the graph
//     public:
//         // insrrt new nodes into the adjacency list from the given graph
//         AdjNode* getAdjListNodes(int value, int weight, AdjNode* head){
//             AdjNode* newNode = new AdjNode();
//             newNode -> val = value;
//             newNode -> cost = weight;
//             newNode -> next = head; // point new node to the current head 
//             return newNode;
//         }

//         // Allocate new node 
//         DiGraph(graphEdge edges[], int n, int N){
//             // Allocate new node
//             head = new AdjNode*[N];
//             this -> N = N;

//             // Initialize head pointer for all vertices 
//             for (int i=0; i<N; i++) head[i] = nullptr;

//             // Construct directed graph by adding edges to it
//             for (unsigned int i=0; i<N; i++){
//                 int start_vert = edges[i].start_vert;
//                 int end_vert = edges[i].end_vert;
//                 int weight = edges[i].weight;

//                 // Insert in the beginning 
//                 AdjNode* newNode = getAdjListNodes(end_vert, weight,head[start_vert]);

//                 // Point head pointer to new node
//                 head[start_vert] = newNode;
//             }
//         }


//         // Destructor
//         ~DiGraph(){
//             for (int i=0; i<N; i++){
//                 delete[] head[i];
//                 delete[] head;
//             }
//         }
// };

//         // Print all adjacent vertices of a given vertex
//         void display_AdjList(AdjNode* ptr, int i){
//             while (ptr != nullptr) {
//                 std::cout << "(" << i << ", " << ptr->val
//                     << ", " << ptr->cost << ") ";
//                 ptr = ptr->next;
//             }
//             std::cout << std::endl;
//         }

struct Vertex{
    int key;
};

struct Edge{
    int x;
    int y;
};


class Graph{
    private:
        int V; // number of vertices
        std::map<Vertex, std::forward_list<int>> AdjList;
        // void DFSUtil(int V, bool visited[]);
    public:
        Graph(std::vector<Vertex> vertices, std::vector<Edge> edges){
            // Create a graph using the adjacency list representation 
            V = vertices.size();
            for(auto vertex : vertices){
                // Initialize the adjacency list with the given vertices.
                AdjList[vertex];
                
            }
            
        }
        Graph(): Graph({}, {}){// creating an empty graph}
        // void addEdge(int v, int w);
        // void DFS(int v);
        // void BFS(int s);
        }

       
};



int main(int argc, char* argv[]){
   


    return 0;
}