/*******************
*coding assignment 06: Linked List
*Name: Adrian Lopez
*Date: 06/19/23
*Status:in progress
*Language: C++
*File: stack.cpp
*******************/
#include "linkedlist.h"

LinkedList::LinkedList()
 {
    head = nullptr;
    count = 0;
}

LinkedList::~LinkedList()
{
    clearList();
}

bool LinkedList::addNode(int id, string* data) 
{
  bool success = false; // Variable to track the success of adding a node

    if (!exists(id)) 
    { // Check if a node with the same ID already exists
        Node* newNode = createNode(id, data);
        if (newNode != nullptr) 
        { // Check if memory allocation for the new node is successful
            if (head == nullptr) 
            {
                head = newNode;
            } 
            else 
            {
                Node* current = head;
                while (current->next != nullptr)
                {
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

bool LinkedList::deleteNode(int id) 
{
    bool success = false; // Initialize the success variable as false

    Node* nodeToDelete = findNode(id);
    if (nodeToDelete != nullptr) 
    {
        if (nodeToDelete == head)
        {
            head = nodeToDelete->next;
        } 
        else 
        {
            nodeToDelete->prev->next = nodeToDelete->next;
        }

        if (nodeToDelete->next != nullptr) 
        {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }

        destroyNode(nodeToDelete);
        count--;
        success = true; // Node deletion successful
    }

    return success;
}

bool LinkedList::getNode(int id, Data* returnData) 
{
    bool success = false; 

    Node* node = findNode(id);
    if (node != nullptr) 
    {
        *returnData = node->data;
        success = true; // Node retrieval successful
    }

    return success;
}

bool LinkedList::exists(int id) 
{
    return findNode(id) != nullptr;
}

void LinkedList::clearList() 
{
    Node* current = head;
    while (current != nullptr) 
    {
        Node* next = current->next;
        destroyNode(current);
        current = next;
    }

    head = nullptr;
    count = 0;
}

int LinkedList::getCount() 
{
    return count;
}

void LinkedList::printList(bool reverseOrder) 
{
    Node* current = head;

    if (reverseOrder) 
    {
        while (current != nullptr && current->next != nullptr) 
        {
            current = current->next;
        }
    }
    
    while (current != nullptr) 
    {
        std::cout << "ID: " << current->data.id << ", Data: " << current->data.data << std::endl;
        current = reverseOrder ? current->prev : current->next;
    }
}

Node* LinkedList::createNode(int id, string* data) 
{
    Node* newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}






