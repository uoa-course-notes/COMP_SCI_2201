#include <iostream>
#include <vector>
#include <string>


//By default, PRE_ORDER is 0, IN_ORDER is 1, POST_ORDER is 2



/****************************
 * In this assignment, I have chosen C++ for my implementation.
 * The implementations include BST's different traversal orders and
 * AVL tree, its more balanced cousin. (: 
 *
 *
*******************************/

// Utility functions
template<typename T>
void print_inputs(std::vector<T> array){
  int n = array.size();
  std::cout << "<";
  for (int i=0; i<n; i++){
    if (i == n-1) std::cout << array[i];
    else std::cout << array[i] << ",";
  }
  std::cout << ">\n";
}


class Node{
  private:
    Node* leftChild;
    Node* rightChild;
    int data;
};

class BST{

};



class AVL_Tree{
  private:
    AVL_Tree* root;
  public:
    AVL_Tree(std::vector<std::string> nodes){
      // Creating a vector of nodes. 
      int num_nodes = nodes.size();
      int i = 0;
      // while(num_nodes--){
        
      //   // root -> insert();
      // }
    }
    // Insertion (trivial)
    void insert(Node* node){

      return;
    }

    // Deletion of children (more complicated)
    void deletion(int data){
      // if tree is empty, then print out empty 
      if (isEmpty()) std::cout << "EMPTY" << std::endl;      
    }


    bool isEmpty(){
      AVL_Tree* tree = getRoot();
      if (tree == NULL) return true;
      else return false;
    }

    AVL_Tree* getRoot(){
        return 0;
    }


    // Order traversals - naïve (with no testing procedures)
    // void pre_order(AVL_Tree* tree){
    //   // Base case - when ``tree` is a leaf node, just return without further processing
    //   if (tree == nullptr) return;

    //   //Recursive
    //   std::cout << tree->data << " ";
    //   pre_order(tree -> leftChild);
    //   pre_order(tree -> rightChild);
    // }
    // void in_order(AVL_Tree *tree){
    //   if (tree == nullptr) return;
    //   pre_order(tree -> leftChild);
    //   std::cout << tree -> data << " ";
    //   pre_order(tree -> rightChild);

    // }
    // void post_order(AVL_Tree *tree){
    //   if (tree == nullptr) return;
    //   pre_order(tree -> leftChild);
    //   pre_order(tree -> rightChild);
    //   std::cout << tree -> data << " ";
    // }
  

};




int main(int argc, char** argv){
  std::string s;
  std::vector<std::string> INPUT;
  while(std::getline(std::cin,s)){
     if (s.empty()) break; // user gave empty string as input.
     INPUT.push_back(s);
  }
  // print_inputs(INPUT); 


  // Expected: this program takes n modification moves, each separated by spaces and 
  // there could be anywhere from 1 to 100 such moves. 
  // The input is then followed by exactly! one finishing move 
  int inputSize = INPUT.size();

  std::string finishingMove = INPUT[inputSize - 1];
  // Instead of creating a whole new array and copying the INPUT array
  // into the new one we can: 
  INPUT.pop_back(); // remove the last-inserted element (the finishing move)
if (finishingMove == "PRE") {
  
} 
else if (finishingMove == "IN"){

}
else if (finishingMove == "POST"){

}
else std::cout << "Invalid input. Valid choices: PRE, IN, and POST." << std::endl;


  // AVL_Tree avl;
  // avl.insert(10);


  return 0;
}
