#ifndef _Employee_
#define _Employee_

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
class Employee{
public:
	Employee();
	Employee(int IdNum, std::string last, std::string first);
	Employee(const Employee &person);
	~Employee();
	void setFirstName(string first);
	void setLastName(string last);
	void setID(int IdNum);
	int getID() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	friend std::ostream& operator<<(std::ostream &outs, Employee &person);
	friend std::istream& operator>>(std::istream &ins, Employee &person);
private:
	int ID;
	std::string lastname;
	std::string firstname;
};


#endif