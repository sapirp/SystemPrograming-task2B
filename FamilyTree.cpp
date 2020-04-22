#include "FamilyTree.hpp"

#include <iomanip>


//Constructor
family::Tree::Tree(string name) {
    itsRoot = new Node(name, nullptr, "me");
}
//Destructor
family::Tree::~Tree() {
    destroyTreeNode(itsRoot);
}
void family::Tree::destroyTreeNode(Node* n) {
    if (n != nullptr) {
        destroyTreeNode(n->getMom());
        destroyTreeNode(n->getDad());
        delete n;
    }
}

//return the node by given value(name)
Node* family::Tree::getNodeValue(Node* node, string currentValue) {
    if (node != nullptr) {
        if (isEqual(node->getValue(), currentValue))
            return node;
        else {
            Node* n = getNodeValue(node->getMom(), currentValue);
            if (n == nullptr)
                n = getNodeValue(node->getDad(), currentValue);
            return n;
        }
    } else
        return nullptr;
}

family::Tree& family::Tree::addMother(string childNode, string momNode) {
    Node* node = getNodeValue(itsRoot, childNode);
    if (node == nullptr)
        throw std::exception();   //"Error, was not found in the tree");
    else if (node->getMom() != nullptr)
        throw std::exception();   //"Error, already has a mother");
    else {
        Node* n = new Node(momNode, node, "mother");
        n->setDistance(node);
        n->setRelation();
        node->setMom(n);
    }
    return *this;
}

family::Tree& family::Tree::addFather(string childNode, string fatherNode) {
    Node* node = getNodeValue(itsRoot, childNode);
    if (node == nullptr)
        throw std::exception();   //"Error, was not found in the tree");
    else if (node->getDad() != nullptr)
        throw std::exception();   //"Error, already has a father");
    else {
        Node* n = new Node(fatherNode, node, "father");
        n->setDistance(node);
        n->setRelation();
        node->setDad(n);
    }
    return *this;
}

//return the node by given relationship
Node* family::Tree::getNodeRelation(Node* node, string currentValue) {
    if (node != nullptr) {
        if (isEqual(node->getRelation(), currentValue))
            return node;
        else {
            Node* n = getNodeRelation(node->getMom(), currentValue);
            if (n == nullptr)
                  n = getNodeRelation(node->getDad(), currentValue);
            return n;
        }
    } else
        return nullptr;
}

string family::Tree::find(string Relationship) {
    Node* n = getNodeRelation(itsRoot, Relationship);
    if (n != nullptr) return n->getValue();
    else throw std::exception();  //"The tree cannot handle the  relation");
}

string family::Tree::relation(string Name) {
    Node* n = getNodeValue(itsRoot, Name);
    if (n != nullptr) return n->getRelation();
    return "unrelated";
}

bool family::Tree::isEqual(string str1, string str2) {
    if (str1.compare(str2) == 0) return true;
    return false;
}

void family::Tree::disconnectParent(Node* n) {
    Node* mom = n->getChild()->getMom();
    Node* dad = n->getChild()->getDad();
    if (mom == n) n->getChild()->setMom(nullptr);
    if (dad == n) n->getChild()->setDad(nullptr);
}

void family::Tree::remove(string givenName) {
    Node* n = getNodeValue(itsRoot, givenName);
    if (n == nullptr)
        throw std::exception();   //"Error, was not found in the tree");
    else if (n == itsRoot)
        throw std::exception();   //"Error, tree root cannot be deleted");
    else {
        disconnectParent(n);
        destroyTreeNode(n);
    }
}

void family::Tree::display() {
    printFamilyTree(itsRoot, 0);
}
void family::Tree::printFamilyTree(Node* n, int index = 0) {
    if (n != nullptr) {
        if (n->getDad()) printFamilyTree(n->getDad(), index + 4);
        if (index) cout << setw(index) << ' ';
        if (n->getDad()) cout << " /\n"
                                << setw(index) << ' ';
        cout<<n->getValue() << "[" + n->getRelation() << "]"<< endl;
        if (n->getMom()) {
            cout << setw(index) << ' ' << " \\\n";
            printFamilyTree(n->getMom(), index + 4);
        }
    }
}
