
#include <cstdlib>
#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include "BinaryTreeNode.h"
#include "Employee.h"
#include <sstream>
#include <cstring>
#include <fstream>


using namespace std;
//constructor setting root to nullptr and size to zero
BinarySearchTree::BinarySearchTree()
{
    root=nullptr;
    size=0;
}
//destructor
BinarySearchTree::~BinarySearchTree()
{   clear();
    cout<<"Binary search tree destructor called."<<endl;
}
//search function
Employee* BinarySearchTree::search(int id) {
    //if the root is null that is, it is an empty tree, print message and return NULL as there is no need to search
    if(root== nullptr){
        cout<<"Empty tree"<<endl;
        return NULL;
    }
    //create a BinaryTreeNode curr as root
    BinaryTreeNode *curr = root;
    //if the root itself has the required id, print message and return the employee in root
    if(curr->person.getID()==id){
        cout<<"1 Employee searched.Found 1 record"<<endl;
        return &curr->person;
    }
    //i is used to store number of records searched
    int i=0;
    //entering a while loop that exits if curr is nullptr or the id of employee in curr is the one we are searching
    while (curr != nullptr && curr->person.getID() != id) {
        //increment i for every search
        i=i+1;
        //if the required id less than the curr id, make curr equal to its left child
        //otherwise make it right child
        if (id < curr->person.getID()) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    //if curr is nullptr which means the give id is not present in the tree, print message and return null
    if (curr == nullptr)
    {
        cout<<i<<" Employees searched.Found 0 record"<<endl;
        return NULL;
    }
    //if id is found, print message and return the employee in curr
    cout<<i<<" Employees searched.Found 1 record"<<endl;
    return &curr->person;
}
//BSTsize() returns size of the tree
int BinarySearchTree:: BSTsize()
{
    return size;
}
//insert function
bool BinarySearchTree::insert(Employee &emp) {
    //first we check whether the id is already present.This is same as search() algorithm.
    //if id is found, print error message and return false, else continue to insert
    int id=emp.getID();
    if(root!= nullptr){
        BinaryTreeNode *curr = root;
        if(curr->person.getID()==id){
            cout<<"Employees already exists."<<endl;
            return false;
        }
        int i=0;
        while (curr != nullptr && curr->person.getID() != id) {
            i=i+1;
            if (id < curr->person.getID()) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
        if(curr!= nullptr){
            cout<<"Employees already exists."<<endl;
            return false;
        }
    }

//the above code is for search inorder to avoid duplicates, the below is to insert.
//creating a BinaryTreeNode *newnode with the given employee
//creating a BinaryTreeNode *curr as root
//creating a BinaryTreeNode *temp as nullptr
    BinaryTreeNode *newnode = new BinaryTreeNode(emp);
    BinaryTreeNode *current = root;
    BinaryTreeNode *temp = nullptr;
    //if the root itself is null, directly make the root as the newnode we created, increase size by 1, return true
    if (current == nullptr) {
        current = newnode;
        root=current;
        size = size + 1;
        return true;
    }
        //if root is not null
    else {
        //enter a while loop that exits only when current is nullptr
        while (current != nullptr) {
            //if the required id greater than the current id, make temp as current, make curr equal to its right child
            //otherwise make temp as current,make current as its left child
            if (emp.getID() > current->person.getID()) {
                temp =current;
                current = current->right;
            } else {
                temp = current;
                current = current->left;
            }
        }
        //make current equal to its parent
        current = temp;
        //now we set the required node
        //if the required id greater less the current id, make new node its left node and set its parent to current
        //otherwise make new node its right node and set its parent to current
        if (emp.getID() < current->person.getID()) {
            current->left=newnode;
            newnode->parent = current;
        }
        else
        {
            current->right=newnode;
            newnode->parent = current;
        }
    }
    //increase size by 1 and return true
    size = size + 1;
    return true;
}
//clear() function to destroy the tree
bool BinarySearchTree::clear()
{
    //while tree is non empty, it removes the root of the tree and thus
    //by the end of the loop, the whole tree is destroyed and returns true
    while(size!=0){
        remove(root->person.getID());
    }
    return true;
}
//save for inorder traversal
bool BinarySearchTree::save(){
    //creating 2 BinaryTreeNoder temp and pre
    BinaryTreeNode *temp, *pre;
    //creating or using inorder.txt file
    ofstream myfile;
    myfile.open ("inorder.txt");
    //if root is null, return true with an empty inorder.txt file.
    if (root == nullptr) {
        return true;
    }
    //set temp to root
    temp = root;
    //entering while loop that exits only when temp is null
    while (temp != nullptr) {
        //if ther is no node to left of temp, then add the details of temp to inorder.txt
        //set temp to its right child
        if (temp->left == nullptr) {
            myfile<<temp->person.getLastName()<<" "<<temp->person.getFirstName()<<" "<<temp->person.getID()<<"\n";
            temp = temp->right;
        }
            //if ther is a left child
        else {
            //set temp's left child's to pre
            pre = temp->left;
            //set pre to its rightmost child using below loop
            while (pre->right != nullptr && pre->right != temp) {
                pre = pre->right;
            }
            //if there is no right child to pre,set temp as right child of pre
            //make temp as temp's left child
            if (pre->right == nullptr) {
                pre->right = temp;
                temp = temp->left;
            }
                //if there is a right child to pre,set right child of pre to null and add temp's info to inorder.txt
                //make temp as temp's right child
            else {
                pre->right = nullptr;
                myfile<<temp->person.getLastName()<<" "<<temp->person.getFirstName()<<" "<<temp->person.getID()<<"\n";
                temp = temp->right;
            }
        }
    }
    //close myfile and return true
    myfile.close();
    return true;
}
bool BinarySearchTree::savepreorder(){
    //creating or using preorder.txt file
    ofstream myfile2;
    myfile2.open ("preorder.txt");
    //if root is null, return true with an empty preorder.txt file.
    if (root == nullptr) {
        return true;
    }
    //create BinaryTreeNode *te and set it to root
    BinaryTreeNode *te=root;
    //the below loop exits only if te is nullptr
    while (te)
    {
        //if te has no left child, add its info to preorder.txt
        //make te as its right child
        if (te->left == nullptr)
        {
            myfile2<<te->person.getLastName()<<" "<<te->person.getFirstName()<<" "<<te->person.getID()<<"\n";
            te = te->right;
        }
            //if te has a left child
        else
        {
            //curr is used to store the rightmost node of left child of te
            BinaryTreeNode* cur = te->left;
            while (cur->right && cur->right != te){
                cur = cur->right;
            }
            //if right child of curr equal to te, set right child of curr to null and make te as te's right child
            if (cur->right == te)
            {
                cur->right = nullptr;
                te = te->right;
            }
                //else, add te's info to preorder.txt,set right child of cur to te and te to te's left child
            else
            {
                myfile2<<te->person.getLastName()<<" "<<te->person.getFirstName()<<" "<<te->person.getID()<<"\n";
                cur->right = te;
                te = te->left;
            }
        }
    }
    //close myfile2 and return true
    myfile2.close();
    return true;
}
//remove function
bool BinarySearchTree::remove(int k){
    //first we check whether the id is present.This is same as search() algorithm.
    //if id is not found, print error message and return false, else continue to remove
    if(root== nullptr){
        return false;
    }
    BinaryTreeNode *curr = root;
    if(curr->person.getID()!=k){
        int i = 0;
        while (curr != nullptr && curr->person.getID() != k) {
            i = i + 1;
            if (k < curr->person.getID()) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        if (curr == nullptr) {
            return false;
        }
    }
    //the above code is for search , the below is to remove.
    //creating a BinaryTreeNode *t as root
    BinaryTreeNode *t = root;
    //the below loop exits if either t is null or it is equal to the required node
    while (t != nullptr && t->person.getID() != k) {
        if (k < t->person.getID()) {
            t = t->left;
        }
        else {
            t = t->right;
        }
    }
    //so now t has the required node to remove
    //here we have 3 cases which are dealt in below 3 if,else if,else statements
    //case1:if t has no left or right childs means it is a leaf node
    if (t->left == nullptr && t->right == nullptr)
    {
        //if t is not root
        if (t->person.getID() != root->person.getID())
        {
            //if left child of parent of t is null, which means t is a right child, and in that case set its
            //parent's right child to null and thus removing t
            if(t->parent->left==nullptr){
                t->parent->right = nullptr;
            }
                //if right child of parent of t is null, which means t is a left child, and in that case set its
                //parent's left child to null and thus removing t
            else if(t->parent->right== nullptr){
                t->parent->left = nullptr;
            }
                //if t's parent has both left and right nodes
            else{
                //remove whichever node equals to t
                if (t->parent->left->person.getID() == t->person.getID()){
                    t->parent->left = nullptr;
                }
                else{
                    t->parent->right = nullptr;
                }
            }
        }
            //if t is root set root to null
        else{
            root = nullptr;
        }
        //delete t
        free(t);
        //return true;
    }
        //case 2: if t has both left and right nodes
    else if (t->left != nullptr && t->right!= nullptr)
    {
        //the below loop finds the minimum node in right subtree of t which is the one t's value should be replaced
        //with after removing it
        BinaryTreeNode* nex  = t->right;
        while (nex->left != nullptr){
            nex = nex->left;
        }

        //storing the id ,firstname and lastname of the minimum node in right subtree of t in the below variables
        int val = nex->person.getID();
        string fname=nex->person.getFirstName();
        string lname=nex->person.getLastName();
        //increasing the size by 1 as each remove decreases size by 1 and we use 2 removes in this particular case
        size++;
        //removing the minimum node in right subtree of t
        remove(nex->person.getID());

        //copying the previously stored values to t
        t->person.setID(val);
        t->person.setFirstName(fname);
        t->person.setLastName(lname);
    }
        //case 3:if t has either left or right child but not both
    else
    {
        //child variable stores whichever the child (left or right) t has using below conditional operator
        BinaryTreeNode* child = (t->left)? t->left: t->right;
        //if t is not root
        if (t != root)
        {
            //p1 stores the parent of t
            BinaryTreeNode *p1=t->parent;
            //if left child of t's parent is null,
            //set right child of parent of t to child variable defined above and set its parent to p1
            if(t->parent->left==nullptr){
                t->parent->right = child;
                child->parent=p1;
            }
                //if right child of t's parent is null,
                //set left child of parent of t to child variable defined above and set its parent to p1
            else if(t->parent->right== nullptr){
                t->parent->left = child;
                child->parent=p1;
            }
                //if t's parent has left and right nodes
            else {
                //if t is the left child of its parent,
                //set left child of parent of t to child variable defined above and set its parent to p1
                if (t->person.getID() == t->parent->left->person.getID()) {
                    t->parent->left = child;
                    child->parent = p1;
                }
                    //else set right child of parent of t to child variable defined above and set its parent to p1
                else {
                    t->parent->right = child;
                    child->parent = p1;
                }
            }
        }
            //if t is root, set root to child
        else{
            root = child;
        }
        //delete t
        free(t);
    }
    //decrease size by 1 and return true
    size=size-1;
    return true;
}