#pragma once
#include<iostream>
template <class T>

class Node
{
public:
	Node<T>* parent;

	T val;//valoare din noduri
	int nr_copii=0;
	Node<T>* c[100];///am pus pointer pentru ca noduri POT AVEA 100 de copii (little john's wife ACCIDENTALY..)
	void add_node(Node<T> *copil);
	void search(Node<T>* arg, int(*compT)(T, T), T val);//arg o sa fie nodul gasit
	int TotalChildren();
	Node(T valoare, Node<T>* parent);
	~Node();
};

template<class T>
inline void Node<T>::add_node(Node<T> *copil)
{
	c[nr_copii] = copil;
	this->nr_copii++;
}///functie sexy pentru adaugarea unui nod si modificarea numarului de copii a radacinii

template<class T>
inline Node<T>::Node(T valoare, Node<T>* parent)
{
	this->parent = parent;
	this->val = valoare;
}//constructorul pentru un nou nod

template<class T>
inline Node<T>::~Node()
{
	for (int i = 0; i < this->nr_copii; i++)
	{
		delete this->c[i];
	}
}

template<class T>
inline void Node<T>::search(Node<T>* arg, int(*compT)(T, T), T val)
{
	if (arg != nullptr)
	{
		//std::cout << "found!";//NU INTRA AICI NICIOADATA !
		return;
	}
	if (compT(this->val, val) == 0)
	{	
		//std::cout << "z"<<std::endl;//debug:)
		arg = this;//might be wrong
		return;
	}
	for (int i = 0; i < this->nr_copii; i++)
	{
		this->c[i]->search(arg, compT, val);
	}
}

template<class T>
inline int Node<T>::TotalChildren()
{
	int sum = this->nr_copii;
	for (int i = 0; i < this->nr_copii; i++) {
		sum += this->c[i]->TotalChildren();
	}
	return sum;
}