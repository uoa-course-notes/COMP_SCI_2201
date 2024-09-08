#include "Node.h"



Node::Node(int key, Node* lst, Node* rst){
    this -> key = key;
    this -> lst = lst;
    this -> rst = rst;
}

Node::Node(): Node(0, nullptr, nullptr){}

int Node::getKey(){return this -> key;}
void Node::setKey(int key){this -> key = key;}
Node* Node::getLST(){return this -> lst;}
Node* Node::getRST(){return this -> rst;}

void Node::setLST(Node* lst){this -> lst = lst;}
void Node::setRST(Node* rst){this -> rst = rst;}


