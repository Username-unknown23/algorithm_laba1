#pragma once

using namespace std;

template <class ValueType>
class LinkedListNode
{
public:
	LinkedListNode(const ValueType& val) : prev(nullptr), next(nullptr), value(val) {}
	LinkedListNode() : prev(nullptr), next(nullptr), value(0) {}
	LinkedListNode<ValueType>* prev;
	LinkedListNode<ValueType>* next;
	ValueType value;
};


template <class ValueType>
class LinkedList
{
	
public:
	LinkedList() : first(nullptr), last(nullptr), count(0) {}

	~LinkedList() {this->Clear();}

	void Clear()
	{
		auto iter = this->first;
		if (iter != nullptr)
		{
			
			delete this->first;
			iter = iter->next;
		}
		count = 0;
	}

	int Size()
	{
		return count;
	}

	void Print()
	{
		auto iterator = this->first;
		while (iterator != nullptr)
		{
			cout << iterator->value << ' ';
			iterator = iterator->next;
		}
		cout << endl;
	}

	ValueType PopBack()
	{
		if (count == 0)
		{
			throw std::out_of_range("List is empty");
		}
		ValueType retval = last->value;
		if (count == 1)
		{
			
			delete last;
			last = nullptr;
			first = nullptr;
		}
		else
		{
			last = last->prev;
			delete last->next;
			last->next = nullptr;
		}
		return retval;
	}

	ValueType PopFront()
	{
		if (count == 0)
		{
			throw std::out_of_range("List is empty");
		}
		ValueType retval = last->value;
		if (count == 1)
		{

			delete first;
			last = nullptr;
			first = nullptr;
		}
		else
		{
			first = first->next;
			delete first->prev;
			first->prev = nullptr;
		}
		return retval;
	}

	void PushBack(const ValueType& a)
	{
		LinkedListNode<ValueType>* NewLast = new LinkedListNode<ValueType>(a);
		if (count == 0)
		{
			first = NewLast;
			last = NewLast;
		}
		else
		{
			NewLast->prev = last;
			last->next = NewLast;
			last = NewLast;
		}
		count++;
	}

	void PushFront(const ValueType& a)
	{
		LinkedListNode<ValueType>* NewFirst = new LinkedListNode<ValueType>(a);
		if (count == 0)
		{
			first = NewFirst;
			last = NewFirst;
		}
		else
		{
			NewFirst->next = first;
			first->prev = NewFirst;
			first = NewFirst;
		}
		count++;
	}

	void InsertAt(ValueType a, int index)
	{
		auto NewNode = new LinkedListNode<ValueType>(a);
		auto iter = first;
		for (int i = 0; i < index-1; i++)
		{
			iter = iter->next;
		}
		auto NextNode = iter->next;
		NewNode->prev = iter;
		NewNode->next = iter->next;
		NextNode->prev = NewNode;
		iter->next = NewNode;
	}

	ValueType& operator[](int index)
	{
		if (index > count)
		{
			throw std::out_of_range("Index out range");
		}
		LinkedListNode<ValueType>* current = first;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->value;
	}
	
	

protected:
	LinkedListNode<ValueType>* first;
	LinkedListNode<ValueType>* last;
	int count;
};



template <class ValueType>
class Queue
{
public:
	Queue()
	{
		LinkedList<ValueType> list;
	};
	~Queue()
	{
		this->Clear();
	}
	
	void Clear()
	{
		list.Clear();
	}

	int Size()
	{
		return list.count;
	}

	void Print()
	{
		list.Print();
	}

	void Push(const ValueType& val)
	{
		list.PushBack(val);
	}

	ValueType Pop()
	{
		return list.PopFront();
	}

	ValueType& operator[](int index)
	{
		auto retval = list[index];
		return retval;
	}

protected:
	LinkedList<ValueType> list;
};

template <class ValueType>
class Stack
{
public:
	Stack()
	{
		LinkedList<ValueType> list;
	};
	~Stack()
	{
		this->Clear();
	}

	void Clear()
	{
		list.Clear();
	}

	int Size()
	{
		return list.count;
	}

	void Print()
	{
		list.Print();
	}

	void Push(const ValueType& val)
	{
		list.PushBack(val);
	}

	ValueType Pop()
	{
		return list.PopBack();
	}

	ValueType& operator[](int index)
	{
		auto retval = list[index];
		return retval;
	}

protected:
	LinkedList<ValueType> list;
};