//--- 2022-2023 Fall Semester Data Structure Assignment 2 ---//
//--------------------------//
//---Name & Surname: Yunus Emre Karaoglan
//---Student Number: 150220732
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h>

#include "huffman.h"
#include "structs.h"

using namespace std;

//-------------Complete The Functions Below-------------//

//-----------------------------------------------------//
//-----------Reads the key from text file--------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::readKey(const char* argv){
    /*
    * This function reads the key from the text file
    * and stores it in the key variable.
    */
    ifstream readKeyFile;
    readKeyFile.open(argv);

    if(readKeyFile.is_open()){
        while(!readKeyFile.eof()){
            readKeyFile >> key;
        }
    }
    readKeyFile.close();
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//---------Sorts the key in an alpabetic order---------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::sortKey(){
    /*
    * This function sorts the key in an alpabetic order and stores it in the sortedKey variable.
    */
    sortedKey = key;
    sort(sortedKey.begin(), sortedKey.end());
};
//-----------------------------------------------------//


//-----------------------------------------------------//
//-------Finds the frequency of the characters---------//
//-----------------------------------------------------//
void Huffman::findFrequency(){
    /*
    * This function finds the frequency of the characters in the key and stores them in the priority queue.
    * It first sorts the key in an alpabetic order. Then, it counts the frequency of each character.
    * It creates a new node for each character and stores the character and its frequency in the node.
    */

    //DO NOT CHANGE THIS
    sortKey(); // Its purpose is to sort the key in an alpabetic order.
    //DO NOT CHANGE THIS
    for(unsigned int i = 0; i < sortedKey.length(); i++){ // It counts the frequency of each character.
        int count = 0;
        for(unsigned int j = i+1; j < sortedKey.length(); j++){ // It checks if there is another character that is equal to the current character.
            if(sortedKey[i] == sortedKey[j]){
                count++;
                sortedKey.erase(j, 1); // It deletes the character from the string if it is equal to the current character. So, it does not count it again.
                j--;
            }
        }
        // It creates a new node for each character and stores the character and its frequency in the node.
        Node* newNode = new Node;
        newNode->token.symbol = sortedKey[i];
        newNode->token.val = count + 1;
        newNode->left = NULL;
        newNode->right = NULL;
        queue.enque(newNode);
    }
};
//-----------------------------------------------------//


//-----------------------------------------------------//
//----------------Creates Huffman Tree-----------------//
//-----------------------------------------------------//
void Huffman::createHuffmanTree(){
    /*
    * This function creates the Huffman Tree. It first finds the frequency of the characters.
    * Then, it merges the nodes in the priority queue until there is only one node left.
    * The last node in the priority queue is the root of the Huffman Tree.
    */
    this->findFrequency();
    while (queue.head->next != NULL){ // It merges the nodes in the priority queue until there is only one node left.
        Node* newNode = huffmanTree.mergeNodes(queue.dequeue(), queue.dequeue()); // It merges the first two nodes in the priority queue.
        queue.enque(newNode);
        Node* temp = queue.head;
        while (temp != NULL){ // It sorts the priority queue after merging the nodes.
            temp = temp->next;
        }
    }
    huffmanTree.root = queue.dequeue(); // The last node in the priority queue is the root of the Huffman Tree.
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//---------------Prints the Huffman Tree---------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::printHuffmanTree(){
    /*
    * This function prints the Huffman Tree.
    */
    huffmanTree.printTree(huffmanTree.root, 0);
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//-------------Finds and returns the binary------------//
//----------------value to given character-------------//
//-----------------------------------------------------//
string Huffman::getTokenBinary(char tokenChar, Node* traverse, string tokenBinary){
    /*
    * This function finds and returns the binary value to given character.
    * It traverses the Huffman Tree and returns the binary value when it finds the character.
    * It returns an empty string if it cannot find the character.
    * It adds 0 to the binary value if it goes left and 1 if it goes right.
    * It uses recursion to traverse the Huffman Tree.
    */
    if (traverse == NULL){
        return "";
    }
    if (traverse->token.symbol == string(1,tokenChar)){
        return tokenBinary;
    }
    string left = getTokenBinary(tokenChar, traverse->left, tokenBinary + "0");
    if (left != ""){
        return left;
    }
    string right = getTokenBinary(tokenChar, traverse->right, tokenBinary + "1");
    if (right != ""){
        return right;
    }
    return "";
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//--------------Encodes the given password-------------//
//-----------------------------------------------------//
void Huffman::encodePassword(string password){
    /*
    * This function encodes the given password.
    * It gets the binary value of each character in the password and stores it in the encodedBinaryPassword variable.
    * It gets the length of each binary value and stores it in the encodedValPassword variable.
    */
    for (unsigned int i = 0; i < password.length(); i++){
        encodedBinaryPassword += getTokenBinary(password[i], huffmanTree.root, "");
        encodedValPassword += to_string(getTokenBinary(password[i], huffmanTree.root, "").length());
    }
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//-------------Prints the encoded password-------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::printEncodedPassword(){
    /*
    * This function prints the encoded password. It prints the binary value of the password and the length of each binary value.
    */
    cout << "Encoded Password Binary: " << encodedBinaryPassword << endl;
    cout << "Encoded Password Value: " << encodedValPassword << endl;
};

//-----------------------------------------------------//
//--------------Decodes the given password-------------//
//-----------------------------------------------------//
void Huffman::decodePassword(string encodedBinaryPassword, string encodedValPassword){
    /*
    * This function decodes the given password. It gets the binary value of each character in the password and stores it in the decodedPassword variable.
    * It uses the encodedValPassword variable to get the length of each binary value. It uses the length of each binary value to get the binary value of each character.
    */
    int index = 0;
    for (unsigned int i = 0; i < encodedValPassword.length(); i++){
        string token = encodedBinaryPassword.substr(index, stoi(string(1,encodedValPassword[i])));
        decodeToken(token);
        index += stoi(string(1,encodedValPassword[i])); // It gets the length of each binary value.
    }
};

//-----------------------------------------------------//

//-----------------------------------------------------//
//---------------Decodes the given binary--------------//
//-----------------------------------------------------//
void Huffman::decodeToken(string encodedToken){
    /*
    * This function decodes the given binary. It traverses the Huffman Tree and gets the character of the binary.
    * It adds the character to the decodedPassword variable.
    */
    Node* traverse = huffmanTree.root;
    for (unsigned int i = 0; i < encodedToken.length(); i++){
        if (encodedToken[i] == '0'){
            traverse = traverse->left;
        }
        else{
            traverse = traverse->right;
        }
    }
    decodedPassword += traverse->token.symbol;
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//-------------Prints the decoded password-------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::printDecodedPassword(){
    cout << "Decoded Password: " << decodedPassword << endl;
};