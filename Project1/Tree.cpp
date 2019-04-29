#include "Tree.h"

Tree::Tree()
{
	height = 0;
	location = "";
}

Tree::Tree(int h, string l)
{
	height = h;
	location = l;
}

ostream & operator<<(ostream & os, Tree obj)
{
	os << obj.height << " " << obj.location;
	return os;
}