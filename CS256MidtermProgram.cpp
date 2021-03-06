#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Human {
private:
	string name;
	int age;
	char sex;
	Human() {}
protected:
	Human(string name, int age, char sex) {
		this->name = name;
		this->age = age;
		this->sex = sex;
	}
public:
	void setName(string name) { this->name = name; }
	void setAge(int age) { this->age = age; }
	void setSex(char sex) { this->sex = sex; }

	string getName() { return name; }
	int getAge() { return age; }
	char getSex() { return sex; }

	virtual string work(string work) = 0;
};

class Parent : public Human {
private:
	vector<Child> children;
public:
	Parent() : Human ("", 0, '0') {}
	Parent(Parent &parent) : Human(parent.getName(), parent.getAge(), parent.getSex()) {
	}
	Parent(string name, int age, char sex) : Human(name, age, sex) {
		cout << getName() << " has been created!" << endl;
	}

	void setChildren(Child &child) { 
		children.push_back(child);
	}

	Child getChildren() { 
		return children; 
	}

	void setChildName(Child &child, string name) {
		child.setName(name);
	}

	string work(string work) {
		return work;
	}
};

class Child : public Human {
private:
	Parent mom;
	Parent dad;
	Child() : Human ("", 0,'0') {}
public:
	Child(Parent &mom, Parent &dad) : Human("", 0, 'c') {

		this->mom = mom;
		this->dad = dad;
	}

	string work(string work) {
		return work;
	}

	friend Parent;
};

int main()
{
	Parent Homer("Homer", 36, 'M');

	Parent March("March", 34, 'F');

	Child Maggie(March, Homer);
	March.setChildName(Maggie, "Maggie");
	Maggie.setAge(3);
	Maggie.setSex('F');

	Child Lisa(March, Homer);
	Homer.setChildName(Lisa, "Lisa");
	Lisa.setAge(12);
	Lisa.setSex('F');

	Child Bart(March, Homer);
	Homer.setChildName(Bart, "Bart");
	Bart.setAge(10);
	Bart.setSex('M');

	cout << Homer.getName() << endl << "------------" << endl;
	cout << "Age: " << Homer.getAge() << endl;
	cout << "Sex: " << Homer.getSex() << endl;
	cout << "Work: " << Homer.work("Safety Inspector") << endl;

	cout << Lisa.getName() << endl << "------------" << endl;
	cout << "Age: " << Lisa.getAge() << endl;
	cout << "Sex: " << Lisa.getSex() << endl;
	cout << "Work: " << Lisa.work("Student") << endl;

	cout << "Maggie" << endl << "------------" << endl;
	cout << "Age: " << Maggie.getAge() << endl;
	cout << "Sex: " << Maggie.getSex() << endl;
	cout << "Work: " << Maggie.work("Play") << endl;

    return 0;
}

