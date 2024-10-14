#include <iostream>
#include <vector>



class Graph_Matrix{
    private:
        int num_V; // number of vertices in the graph
        std::vector<std::vector<int>> adjMatrix;
    public:
        // Default constructor
        Graph_Matrix(){

        };

        // Constructor 
        Graph_Matrix(int v){
            // Initialize the matrix with 0s edges 
            adjMatrix.resize(v, std::vector<int>(v, 0));
        }

        // Add edge to the graph 
        void addEdge(int u, int v){
            // For an undirected graph. add both edges 
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }

        // Display the adjacency matrix 
        void displayMatrix(){
            for(int i = 0; i < num_V; i++){
                for(int j = 0; j < num_V; j++){
                    std::cout << adjMatrix[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
};



int main(int argc, char* argv[]){
    int V = 4;
    Graph_Matrix g(V);
    g.addEdge(0, 1);
    g.addEdge(0,2);
    g.addEdge(1, 2);
    g.addEdge(2,3);

    std::cout << "Adjacency Matrix:" << std::endl;
    g.displayMatrix();

    return 0;

}