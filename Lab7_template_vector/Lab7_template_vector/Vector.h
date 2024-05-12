#pragma once
#include <cstdio>

template <class T>

class Vector
{
private:
	int* elements;
	int lg;
public:
	Vector();//constructor
	Vector(Vector<T>& y);//copy cons
	Vector(Vector<T>&& y);//move cons
	~Vector();//destructor
	void insert(T index, T element);
	void print();
	int operator[](T index);
	//void operator=()
	void remove(T index);
	void sort(int (*compare_ints) (int, int));
	void sort();//overload la sort care foloseste operatorul <
};

template<class T>
inline Vector<T>::Vector()
{
	this->elements = new int[100];
	this->lg = 0;
}

template<class T>
inline Vector<T>::Vector(Vector<T> & y)
{
	this->lg = y.lg;
	delete[] this->elements;
	this->elements = new int[100];
	for (int i = 0; i < y.lg; i++)
		this->elements[i] = y[i];
}//copy constructor

template<class T>
inline Vector<T>::Vector(Vector<T> && y)
{
	this->elements = y.elements;
	y.elements = nullptr;

	this->lg = y.lg;
}//move cons

template<class T>
inline Vector<T>::~Vector()
{
	this->lg = 0;
	delete[] this->elements;
}

template<class T>
inline void Vector<T>::insert(T index, T element)
{
	if (lg == index)
	{
		this->elements[lg] = element;
		this->lg++;
	}
	else {
		for (int i = this->lg; i >index; i--)
		{
			this->elements[i] = this->elements[i - 1];
		}
		this->elements[index] = element;
		this->lg++;
	}
}

template<class T>
inline void Vector<T>::print()
{
	for (int i = 0; i < this->lg; i++)
		printf("%d ", this->elements[i]);
	printf("\n");
}

template<class T>
inline int Vector<T>::operator[](T index)
{
	return this->elements[index];
}

template<class T>
inline void Vector<T>::remove(T index)
{
	for (int i = index; i < this->lg; i++)
	{
		this->elements[i] = this->elements[i + 1];
	}
	this->lg--;
}

template<class T>
inline void Vector<T>::sort(int(*compare_ints)(int, int))
{
	for (int i = 0; i < this->lg; i++)
	{
		for (int j = i + 1; j < this->lg; j++)
		{
			if (compare_ints(this->elements[i], this->elements[j]) == 1)
			{
				int aux;
				aux = this->elements[i];
				this->elements[i] = this->elements[j];
				this->elements[j] = aux;
			}
		}
	}
}

template<class T>
inline void Vector<T>::sort()
{
	for (int i = 0; i < this->lg; i++)
	{
		for (int j = i + 1; j < this->lg; j++)
		{
			if (this->elements[j] < this->elements[i])
			{
				int aux;
				aux = this->elements[i];
				this->elements[i] = this->elements[j];
				this->elements[j] = aux;
			}
		}
	}
}
