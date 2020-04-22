#ifndef _NODE_H
#define _NODE_H

#include <iostream>

using namespace std;

class Node {
   private:
    string Value, Relation;
    Node *itsChild, *itsMom, *itsDad;
    int Distance;

   public:
    //Constructor
    Node(string, Node*, string);  //Initial constructor: value, parent node and its relation

    //Destructor
    ~Node();

    //Getters
    string getValue();       //Return node's value (its name)
    string getRelation();    //Return node's relation
    Node* getChild();        //Return child node
    Node* getMom();          //Return mom node
    Node* getDad();          //Return dad node
    int getDistance();       //Return node's distance from root

    //Setters
    void setMom(Node*);        //Set mom node
    void setDad(Node*);        //Set dad node
    void setRelation();        //Set node's relation
    void setDistance(Node*);   //Set node's distance 
};

#endif