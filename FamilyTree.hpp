#ifndef _FamilyTree_H
#define _FamilyTree_H

#include <iostream>

#include "Node.hpp"

namespace family {
class Tree {
   private:
    Node* itsRoot;

    //Addons methods
    void destroyTreeNode(Node*);
    Node* getNodeValue(Node*, string);
    Node* getNodeRelation(Node*, string);
    bool isEqual(string, string);
    void disconnectParent(Node*);
    void printFamilyTree(Node*, int);

   public:
    //Constructor
    Tree(string name);

    //Destructor
    ~Tree();

    //Exercise methods
    string find(string);
    string relation(string);
    Tree& addFather(string, string);
    Tree& addMother(string, string);
    void display();
    void remove(string);  
    
}; //end of class
}  // namespace family
#endif