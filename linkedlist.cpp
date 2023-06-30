/*******************
*coding assignment 06: Linked List
*Name: Adrian Lopez
*Date: 06/19/23
*Status:in progress
*Language: C++
*File: stack.cpp
*******************/
#include "linkedlist.h"

LinkedList::LinkedList() {
    head = nullptr;
    count = 0;
}

LinkedList::~LinkedList() {
    clearList();
}

bool LinkedList::addNode(int id, string* data) {
  bool success = false; // Variable to track the success of adding a node

    if (!exists(id)) { // Check if a node with the same ID already exists
        Node* newNode = createNode(id, data);
        if (newNode != nullptr) { // Check if memory allocation for the new node is successful
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
                newNode->prev = current;
            }

            count++;
            success = true; // Node added successfully
        }
    }

    return success;
}

bool LinkedList::deleteNode(int id) {
    bool success = false; // Initialize the success variable as false

    Node* nodeToDelete = findNode(id);
    if (nodeToDelete != nullptr) {
        if (nodeToDelete == head) {
            head = nodeToDelete->next;
        } else {
            nodeToDelete->prev->next = nodeToDelete->next;
        }

        if (nodeToDelete->next != nullptr) {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }

        destroyNode(nodeToDelete);
        count--;
        success = true; // Node deletion successful
    }

    return success;
}







