#pragma once
#include <string>

using namespace std;


class Tree {
	int height;
	string location;
public:
	Tree();
	Tree(int h, string l);


	friend ostream& operator<<(ostream& os, Tree obj);
};