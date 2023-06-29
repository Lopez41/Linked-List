/*******************
*coding assignment 06: Linked List
*Name: Adrian Lopez
*Date: 06/28/23
*Status:in progress
*Language: C++
*File: linkedlist.h
*******************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "data.h"
#include <iostream>

class LinkedList
{
public:
    //constructor
    LinkedList();
    //deconstructor
    ~LinkedList();
     
    //methods
    bool addNode(int,string*);
    bool deleteNode(int);
    bool getNode(int,Data*);
    void printList(bool = false);
    int getCount();
    void clearList();
    bool exists(int);

private:
    Node* head;
    int count;
    //private methods
    Node* createNode(int, string*);
    void destroyNode(Node*);
    Node* findNode(int);
};


#endif