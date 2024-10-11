#include <iostream>
// #include <list> doubly linked list
#include <forward_list>
#include <vector>

// Create a graph from adjacency list 




int main(int argc, char* argv[]){
    std::forward_list<int> list;
    std::vector<std::forward_list<int>> Adj;

    // Add edges to the graph
    std::vector<int> data{1,2,3,4,5,6};
    for(int i = 0; i < data.size()-1; i++){
        Adj[data[i]-1].push_front(data[i+1]);
        // Adj[data[i+1]-1].push_front(data[i]);
    }


    return 0;
}