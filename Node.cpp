#include "Node.hpp"

//Constructor
Node::Node(string value, Node* child , string relation)  {  
    Value = value;
    itsChild = child;
    Relation = relation;
    itsMom = itsDad = nullptr;
    Distance=1;
}

//Destructor
Node::~Node() {
    cout << "Node:" << getValue() << " is deleted" << endl;
    itsMom = itsDad = nullptr;
}

//Getters
Node* Node::getChild() {
    return itsChild;
}
Node* Node::getMom() {
    return itsMom;
}
Node* Node::getDad() {
    return itsDad;
}
string Node::getValue() {
    return Value;
}
string Node::getRelation() {
    return Relation;
}

int Node::getDistance(){
    return Distance;
}

//Setters
void Node::setMom(Node* node) {
    itsMom = node;
}
void Node::setDad(Node* node) {
    itsDad = node;
}

void Node::setDistance(Node* node) {
    if (node->itsChild == nullptr) Distance= 1;
    Distance= node->Distance + 1;
}

void Node::setRelation() {
    int RLevel=getDistance();
    string g1="grand";
    string g2="great-";
    string temp;
    if (RLevel == 3)
        Relation = g1 + Relation;
    else if(RLevel>3){
    while (RLevel > 3) {
            temp = g2 + temp;
            RLevel=RLevel-1;
        }
         Relation = temp + g1 + Relation;
    }
}

    


