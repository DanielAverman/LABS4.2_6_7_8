#pragma once
template <class T>
class List
{
	struct Element
	{
		T data;
		Element *next;
		Element *prev;
	};
private:
	Element *Head;
	Element *Curr;
public:
	int length;

	List();
	List(T x);
	List(const List<T> &C);
	~List();
	void  init();
	void  push(T data);
	T  pop();
	void  delFromData(T adr);
	void  loop();
	void  clear();
	void  next();
	void  prev();
	int  isNoEmpty();
	T  lp();
	void  operator +(T v);
};


template <class T> List<T>::List()
{
	Head = NULL;
	Curr = NULL;
	length = 0;
}
template <class T> List<T>::List(T x)
{
	Head = NULL;
	Curr = NULL;
	length = 0;
	push(x);
}
template <class T> List<T>::List(const List<T> &C)
{
	this->Head = NULL;
	this->Curr = NULL;
	this->length = 0;
	Element *p = C.Curr;

	for (int i = 0; i < C.length; i++)
	{
		push(p->data);
		p = p->next;
	}
}
template <class T> List<T>::~List()
{
	clear();
}
template <class T> void List<T>::init()
{
	Curr = Head;
}
template <class T> void List<T>::delFromData(T adr)
{
	if (isNoEmpty())
	{
		Element *tmp = Curr;
		for (int i = 0; i < length; i++)
		{
			if (Curr->data == adr)
			{
				if (Curr == tmp)
					tmp = tmp->next;
				pop();
			}
			next();
		}
		Curr = tmp;
	}
}
template <class T> void List<T>::next()
{
	if (isNoEmpty())
		Curr = Curr->next;
}
template <class T> void List<T>::prev()
{
	if (this->isEmpty())
		Curr = Curr->prev;
}
template <class T> int List<T>::isNoEmpty()
{
	if (Curr == NULL)
		return 0;
	else
		return 1;
}
template <class T> T List<T>::lp()
{
	if (isNoEmpty())
		return Curr->data;
	else
		return 0;
}
template <class T> void List<T>::push(T data)
{
	Element *inserted;
	inserted = new Element;
	inserted->data = data;
	if (!isNoEmpty())
	{
		Head = inserted;
		Curr = inserted;
		Curr->next = inserted;
		Curr->prev = inserted;
	}
	else
	{
		inserted->next = Curr->next;
		inserted->next->prev = inserted;
		Curr->next = inserted;
		inserted->prev = Curr;
	}
	length++;
	Curr = inserted;
}
template <class T> T List<T>::pop()
{
	T tag;
	if (!isNoEmpty()) return 0;
	Element *temp = Curr;
	tag = temp->data;
	if (length == 1)
	{
		Head = NULL;
		Curr = NULL;
	}
	else
	{
		Curr->next->prev = Curr->prev;
		Curr->prev->next = Curr->next;
		Curr = Curr->next;
	}
	if (temp == Head)
		Head = Head->next;
	length--;
	delete temp;
	return tag;
}
template <class T> void List<T>::loop()
{
	if (isNoEmpty())
	{
		Element *tempCar = Head;
		for (int i = 0; i < length; i++)
		{
			std::cout << tempCar->data << " ";
			tempCar = tempCar->next;
		}
		std::cout << "\n";
	}
	else
		std::cout << "List is empty\n";
}
template <class T> void List<T>::clear()
{
	for (int i = 0; i < length;)
		pop();
}
template <class T> void List<T>::operator + (T v)
{
	push(v);
}
