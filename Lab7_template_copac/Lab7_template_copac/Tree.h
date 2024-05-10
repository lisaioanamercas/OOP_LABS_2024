#pragma once

template <class T>

class Tree
{
private:
	Node<T>* radacina;
public:
	Tree(Node<T>* rad);
	void add_node(Node<T>* arg, T val);
	Node<T>* get_node(Node<T>* arg);
	void delete_node(Node<T>* arg);
	Node<T>* find(T arg, int(*compT)(T, T));
	void insert(int index, Node<T> *arg, T val);
	void sort(Node<T> arg, int (*fn) (Node<T>*, Node<T>*));
	int count(Node<T> *arg);
};



template<class T>
inline Tree<T>::Tree(Node<T> *rad)
{
	this->radacina = rad;
}

template<class T>
inline void Tree<T>::add_node(Node<T>* arg, T val)
{
	if (arg == nullptr)
	{
		Node<T> *temp = this->radacina;
		this->radacina = new Node <T> (val,arg);
		this->radacina->add_node(temp);
	}
	else
	{
		arg->add_node(new Node <T> (val,arg));//aici apelam constructorul pentru a adauga un nod
	}
}

template<class T>
inline Node<T>* Tree<T>::get_node(Node<T>* arg)
{
	if (arg == nullptr)
		return this->radacina;
	return arg->c[arg->nr_copii-1];
	//arg=parintele, noi trebuie sa gasim un copil random (?) sa il returneze
	//luam ultimul copil
}

template<class T>
inline void Tree<T>::delete_node(Node<T> *arg)//apelam din parintele nodului pe care vrem sa il stergem
{
	Node<T>* parent = arg->parent;

	for (int i = 0; i < parent->nr_copii; i++)
	{
		//cautam sa vedem unde se afla copilul in vectorul parintelui
		if(parent->c[i] == arg)
		{
			for (int j = i; j < parent->nr_copii - 1; j++)
				parent->c[j] = parent->c[j + 1];
			break;
		}
	}
	parent->nr_copii--;
	delete arg;
}

template<class T>//NU MERGE
inline Node<T>* Tree<T>::find(T arg, int(*compT)(T, T))
{
	Node<T>* cautat = nullptr;

	this->radacina->search(cautat, compT, arg);
	return cautat;
}

template<class T>
inline void Tree<T>::insert(int index, Node<T> *arg, T val)
{
	if (index >= arg->nr_copii)//adauga la dreapta capat
	{
		arg->add_node(new Node <T>(val, arg));
	}
	else
	{
		for (int i = arg->nr_copii; i > index; i--)
		{
			arg->c[i] = arg->c[i - 1];
		}
		arg->c[index] = new Node <T> (val, arg);
		arg->nr_copii++;
	}
}

template<class T>
inline void Tree<T>::sort(Node<T> arg, int(*fn)(Node<T>*, Node<T>*))
{
	for (int i = 0; i < arg->nr_copii; i++)
	{
		for (int j = i + 1; j < arg->nr_copii; j++)
		{
			if (fn(arg->c[i], arg->c[j]) < 0)
				std::swap(arg->c[i], arg->c[j]);
		}
	}
}

template<class T>
inline int Tree<T>::count(Node<T> *arg)
{
	if (arg == nullptr)
		return this->radacina->TotalChildren();
	return arg->TotalChildren();
}
