#ifndef _NODE_H
#define _NODE_H

class Node{
  private:
    int key;
    Node* lst;
    Node* rst;
  public:
    Node();
    Node(int key, Node* lst, Node* rst);
    int getKey();
    void setKey(int key);

    Node* getLST();
    Node* getRST();
    void setLST(Node* lst);
    void setRST(Node* rst);

    ~Node();
  
};

















#endif 
