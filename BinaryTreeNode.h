#ifndef _BinaryTreeNode_
#define _BinaryTreeNode_
#include <iostream>
#include <cstdlib>
#include "Employee.h"

using namespace std;

class BinaryTreeNode{
protected:
    Employee person;
    BinaryTreeNode * parent;
    BinaryTreeNode * left;
    BinaryTreeNode * right;
public:
    BinaryTreeNode(Employee &newEmployee, BinaryTreeNode * parentptr = NULL, BinaryTreeNode * rightptr = NULL, BinaryTreeNode *leftptr = NULL){
        person=newEmployee;
        parent=parentptr;
        right=rightptr;
        left=leftptr;
    };
    ~BinaryTreeNode();
    friend class BinarySearchTree;
};

#endif
