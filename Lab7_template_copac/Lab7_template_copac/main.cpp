#include "Node.h"
#include "Tree.h"
#include <iostream>

int compT(int a, int b)
{
	return b - a;//(smart)
}
int fn(Node<int> *a, Node<int>*b)
{
	return b->val - a->val;
}
using namespace std;

int main()
{
	Node<int>* n = new Node<int>(10,nullptr);
	Tree<int> C(n);///copac cu radacina n, nodul creat mai sus
	C.add_node(n, 15);
	C.add_node(n, 20);
	Node<int>* ceva = C.get_node(n);
	C.add_node(ceva, 25);
	C.add_node(ceva, 30);
	cout << ceva->val<<endl;	
	//C.delete_node(ceva);
	Node<int>* cev = C.find(15,compT);
	//cout << cev<<endl;
	//cout << C.get_node(ceva);
	C.insert(2, n, 25);
	Node<int>* altceva = C.get_node(n);
	cout << altceva->val<<endl;
	cout << C.count(nullptr);
	return 0;
}
