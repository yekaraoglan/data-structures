//--- 2022-2023 Fall Semester Data Structure Assignment 2 ---//
//--------------------------//
//---Name & Surname: Yunus Emre Karaoglan
//---Student Number: 150220732
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "structs.h"

using namespace std;

//-------------Complete The Functions Below-------------//

//-------------Initialize Priority Queue-------------//
PriorityQueue::PriorityQueue(){
    /*
    * This function initializes the priority queue.
    * It sets the head of the priority queue to NULL since there is no node in the queue.
    */
    this->head = NULL;
};

//-------------Insert New Node To Priority Queue-------------//
void PriorityQueue::enque(Node* newnode){
    /*
    * This function inserts a new node to the priority queue.
    * It checks if the head of the queue is NULL. If it is, it sets the head to the new node.
    * If it is not, it checks if the new node's value is smaller than the head's value.
    * If it is, it sets the new node's next to the head and sets the head to the new node.
    */
    // If the head is NULL, it sets the head to the new node.
    if (this->head == NULL){
        this->head = newnode;
        return;
    }
    // If the new node's value is smaller than the head's value, it sets the new node's next to the head and sets the head to the new node.
    Node* temp = this->head;
    if (temp->token.val > newnode->token.val){
        newnode->next = temp;
        this->head = newnode;
        return;
    }
    // If the new node's value is bigger than the head's value, it finds the node that is bigger than the new node and inserts the new node between them.
    // If the new node's value is equal to a node's value, it inserts the new node after the node.
    while (temp->next != NULL && temp->next->token.val <= newnode->token.val){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
};

//-------------Remove Node From Priority Queue-------------//
Node* PriorityQueue::dequeue(){
    /*
    * This function removes a node from the priority queue.
    * It checks if the head of the queue is NULL. If it is, it returns NULL.
    * If it is not, it sets the head to the next node and returns the old head.
    */
    if (this->head == NULL){
        return NULL;
    }
    Node* temp = this->head;
    this->head = this->head->next;
    return temp;  
};

//-------------Initialize Tree-------------//
Tree::Tree(){
    /*
    * This function initializes the tree.
    * It sets the root of the tree to NULL since there is no node in the tree.
    */
    this->root = NULL;
};

//-------------Delete Tree Nodes From Memory-------------//
Tree::~Tree(){
    /*
    * This function deletes the tree from memory.
    * It deletes the left and right nodes of the root and then deletes the root.
    */
    deleteTree(this->root->left);
    deleteTree(this->root->right);
    delete this->root;
};

//-------------Delete Tree From Memory-------------//
void Tree::deleteTree(Node* node){
    //-------------This Function Is Not Necessary-------------//
    //-----------------Use It At Your Own Will----------------//
    /*
    * This function deletes the tree from memory.
    * It deletes the left and right nodes of the root and then deletes the root, recursively.
    */
    if (node == NULL){
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

//-------------Merges Two Node Into One-------------//
Node* Tree::mergeNodes(Node* temp1, Node* temp2){
    /*
    * This function merges two nodes into one.
    * It creates a new node and sets its value to the sum of the two nodes' values.
    * It sets its symbol to the concatenation of the two nodes' symbols.
    * It sets its left and right nodes to the two nodes.
    */
    Node* temp = new Node;
    temp->token.val = temp1->token.val + temp2->token.val;
    temp->token.symbol = temp2->token.symbol + temp1->token.symbol;
    temp->left = temp2;
    temp->right = temp1;
    return temp;
};

void Tree::printTree(Node* traverse, int level){
    /*
    * This function prints the tree.
    * It prints the level of the node and the node's symbol and value.
    * It prints the left and right nodes of the node, recursively.
    */
    cout << level << "\t";
    for (int i = 0; i < level; i++)
        cout << "\t"; 

    cout << traverse->token.symbol << "(" << traverse->token.val << ")" << endl;

    if(traverse->left)
        printTree(traverse->left, level + 1);  
    if(traverse->right)
        printTree(traverse->right, level + 1);
};