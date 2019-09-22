#include <iostream>
#include <cstdlib>
#include "BinarySearchTree.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
using namespace std;
int main(){
    BinarySearchTree *b=new BinarySearchTree();
    int i=0;
    Employee *e1 = new Employee();
    string str;
    ifstream emp_in;
    emp_in.open("Employee-Database.txt");
    Employee NewEmployee;
    cout<<"Enter number of records to be inserted : "<<endl;
    cin>>i;
    int y=1;
    //inserting employees into the tree such that number of entries is less than or equal to the number
    //entered by user and it is not end of the file
    while (emp_in >> NewEmployee && y<=i)
    {
        b->insert(NewEmployee);
        y++;
    }
    //if y!=i+1 that is, the number user entered is more than the number of records in text file,print the message
    if(y!=i+1){
        cout<<"Successfully inserted "<<y-1<<" records"<<endl;
        cout<<"Cannot insert "<<i<<" records as the text file contains only "<<y-1<<" records"<<endl;
    }
    else{
        cout<<"Successfully inserted "<<y-1<<" records"<<endl;
    }
    string s;
    //menu
    while(1) {
        cout << "MENU" << endl;
        cout << "(I)nsert new record" << endl;
        cout << "(D)elete record" << endl;
        cout << "(E)mployee ID search" << endl;
        cout << "(S)ave database to a file" << endl;
        cout << "(Q)uit" << endl;
        cout<<"Enter your choice from the menu : "<<endl;
        cin>>s;
        if(s=="I"){
            int id=0;
            string fn;
            string ln;
            cout<<"Enter employee id : "<<endl;
            cin>>id;
            cout<<"Enter employee first name : "<<endl;
            cin>>fn;
            cout<<"Enter employee last name : "<<endl;
            cin>>ln;
            e1->setLastName(ln);
            e1->setFirstName(fn);
            e1->setID(id);
            if(b->insert(*e1)){
                cout<<"Record inserted successfully."<<endl;
            }
            else{
                cout<<"Record is not inserted"<<endl;
            }
        }
        else if(s=="D"){
            int id=0;
            cout<<"Enter employee id : "<<endl;
            cin>>id;
            if(b->remove(id)){
                cout<<"Record deleted successfully!"<<endl;
            }
            else{
                cout<<"Record is not deleted!"<<endl;
            }
        }
        else if(s=="E"){
            int id=0;
            cout<<"Enter employee id : "<<endl;
            cin>>id;
            cout<<"Searching..."<<endl;
            Employee *t=b->search(id);
            if(t==NULL){
                cout<<"No record found"<<endl;
            }
            else{
                cout<<""<<endl;
                cout<<"Last: "<<t->getLastName()<<endl;
                cout<<"First: "<<t->getFirstName()<<endl;
                cout<<"EID: "<<t->getID()<<endl;
                cout<<""<<endl;
            }
        }
        else if(s=="S"){
            cout<<"Select 1 or 2 from below"<<endl;
            cout<<"1.save inorder"<<endl;
            cout<<"2.save preorder"<<endl;
            cin>>s;
            if(s=="1"){
                if(b->save()){
                    cout<<"Record saved successfully to inorder.txt."<<endl;
                }
                else{
                    cout<<"Record is not saved."<<endl;
                }
            }
            else if(s=="2"){
                if(b->savepreorder()){
                    cout<<"Record saved successfully to preorder.txt."<<endl;
                }
                else{
                    cout<<"Record is not saved."<<endl;
                }
            }
            else{
                cout<<"Invalid input"<<endl;
            }

        }
        else if(s=="Q"){
            delete e1;
            delete b;
            cout<<"Tree is deleted."<<endl;
            cout<<"EXIT!!"<<endl;
            break;
        }
        else{
            cout<<"Invalid input.Select the option from Menu"<<endl;
        }
        cout<<" "<<endl;

    }

    return 0;
}