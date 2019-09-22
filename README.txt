
prerequisites for execution:

Make sure all these files exist before running the program.

1.lab3.cpp,Employee.cpp,Employee.h,BinnaryTreeNode.h,BinarysearchTree.cpp,BinarysearchTree.h
(Note:header files are modified.
BinarysearchTree.h:Added a member function to save the tree in preorder traversal.

2.Employee-Database.txt(to create the Binary Search Tree).

3.inorder.txt to save the elements of the tree to the file in inorder traversal.

4.preorder.txt to save the elements of the tree to the file in preorder traversal.


Process for execution:

Enter the number of records to be inserted in the tree from the Employee-Database file.
When the screen prompts for the Menu,selects the operation which you need to perform on the stack.

(I):Insert:Select 'I' for Inserting a new Employee record into the tree.If you select I,screen prompts to enter the id,firstname and lastname you want to insert into the tree.Enter the values.
       checks if the EmployeeID already exists and inserts if not exist.prints the message that the record is successfully inserted
	   if the specified EmployeeID is already present,record is not inserted.
(D):Delete: Select 'D' for Deleting a record.If you select D,asks the user to enter the EmployeeID to be deleted.
       If the EmployeeID given by the user is present in the tree,the corresponding Employee record is deleted(based on the specified Employee node is a leaf node or having one child or two children) and
	   prints the message "Record deleted Succesfully".
	   Otherwise prints the message "Record is not deleted".
(E):Employee ID Search: Select 'E' for Employee ID Search.This prompts the user for the EmployeeID to be serached.If the record is present in the tree,
	prints the number of records searched for finding the 	specified Employee and also prints the Employee Record.
	If the record is not present in the tree,prints the message that the recordis not found
(S):Save database to a file:Select 'S' for saving the records to a file.Select the option to save whether preorder or inorder.
	If you select '1',the tree is saved in inorder traversal to a file (inorder.txt)
	If you select '2',the tree is saved in preorder traversal to a file (preorder.txt)
(Q):Quit: Select 'Q' for Quit.The tree is deleted to avoid memory leakage and exits from the execution.


