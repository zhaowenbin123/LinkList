#include<iostream>
using namespace std;

template<class T>
class List;


template<class T>
class LinkNode
{
	friend class List<T>;
public:
	LinkNode(T x)
	{
		_data = x;
		_prev = NULL;
		_next = NULL;
	}
private:
	T _data;
	LinkNode<T> *_prev;
	LinkNode<T> *_next;
};

template<class T>
class List
{
	friend ostream&  operator<<(ostream& out, List<T>& l);
public:
	List()
	{
		_head = NULL;
		_tail = NULL;
	}

	~List()
	{}

	LinkNode<T>* _CreateNode(const T& x);
	void clear(LinkNode<T>* &cur);
	void Print();
	void PushBack(const T& x);		//尾插
	void PopBack();		//尾删

	void PushFront(const T& x);
	void PopFront();

	int Length();		//求表长
	LinkNode<T>* Find(const T& x);

	void Insert_pos(size_t pos, const T& x);
	void Insert_val(const T& n, const T& x);
	LinkNode <T> * Reverse();

	void Delete_pos(size_t pos);
	void Delete_val(const T& x);

private:
	LinkNode<T> * _head;
	LinkNode<T> * _tail;
};

//template<class T>
//ostream&  operator<<(ostream& out,List<T>& l)							// 打印
//{
//	LinkNode<T>  *tmp = l._head;
//	out << "List>>>:" ;
//	while (tmp != NULL)
//	{
//		out << tmp->_data << "<-->";
//		tmp = tmp->_next;
//	}
//	out << "NULL" << endl;
//	return out;
//}


template<class T>
void List<T> ::Print()
{
	LinkNode<T>  *src = _head;
	cout << "List>>>:  " ;
	while (src != NULL)
	{
		cout << src->_data << "<-->";
		src = src->_next;
	}
	cout << "NULL" << endl;
}
template<class T>
LinkNode<T>* List<T> :: _CreateNode(const T& x)			//创建结点
{
	LinkNode<T>* tmp = new LinkNode<T>(x);
	return tmp;
}

template<class T>
void List<T> :: clear(LinkNode<T>* &cur)
{
	cur->_next = NULL;
	delete  cur;
	cur = NULL;
}


template<class T>
int List<T> ::Length()				//求表长
{
	int len = 0;
	if (_head == NULL)
	{
		cout << "The Length of List is:" << "0" << endl;
		return 0;
	}
	else
	{
		LinkNode<T> * begin = _head;
		while (begin != NULL)
		{
			begin = begin->_next;
			len++;
		}
	}
	cout << "The Length of List is >>>:  " << len << endl;
	return len;
}

template <class T>
void List<T> ::PushBack(const T& x)			//尾插
{
	if (_head == NULL)
	{
		_head = _CreateNode(x);
		_tail = _head;
	}
	else
	{
		LinkNode<T> * tmp = _CreateNode(x);
		_tail->_next = tmp;
		tmp->_prev = _tail;
		_tail = tmp;
	}
}

template <class T>
void List<T> ::PopBack()			//尾删
{
	if (_head == NULL)
	{
		cout << "List is empty!!!" << endl;
		return;
	}
	else if (_head->_next == NULL)
	{
		clear(_head);
	}
	else
	{
		LinkNode<T> * tmp = _tail;
		_tail = _tail->_prev;
		clear(tmp);
		_tail->_next = NULL;
	}
}


template <class T>
void List<T> ::PushFront(const T& x)		//头插
{
	if (_head == NULL)
	{
		_head = _CreateNode(x);
	}
	else
	{
		LinkNode<T>  * tmp = _CreateNode(x);
		_head->_prev = tmp;
		tmp->_next = _head;
		_head = _head->_prev;
	}
}

template <class T>
void List<T> ::PopFront()				//头删
{
	if (_head == NULL)
	{
		cout << "List is empty!!!" << endl;
		return;
	}
	else if (_head->_next == NULL)
	{
		clear(_head);
	}
	else
	{
		LinkNode<T> * tmp = _head;
		_head = _head->_next;
		clear(tmp);
		tmp = NULL;
		_head->_prev = NULL;
	}
}

template <class T>
LinkNode<T>* List<T> ::Find(const T& x)			//查找
{
	if (_head == NULL)
	{
		cout << "List is empty,not found!!!" << endl;
		return NULL;
	}
	else
	{
		LinkNode<T> * n = _head;
		while (n->_next != NULL && n->_data != x)
		{
			n = n->_next;
		}
		if (n->_data == x)
		{
			cout << "The data of your find is :" << n->_data << endl;
			return n;
		}
	}
	cout << "There is no this data in the List!!！" << endl;
	return NULL;
}



template <class T>
void List<T> ::Insert_pos(size_t pos, const T& x)		//在第n个后面插入
{
	int len = Length();
	if (pos <= len)
	{
		if (_head == NULL)
		{
			cout << "List is empty!!!" << endl;
			return;
		}
		else
		{
			LinkNode<T> * begin = _head;
			LinkNode<T> * tmp = _CreateNode(x);
			while (--pos)
			{
				if (begin->_next != NULL)
				{
					begin = begin->_next;
				}
			}
			if (begin->_next == NULL)
			{
				PushBack(x);
				return;
			}
			tmp->_next = begin->_next;
			begin->_next->_prev =tmp;
			begin->_next = tmp;
			tmp->_prev = begin;
		}
	}
	else
	{
		cout << "Input Error!!!" << endl;
	}
}



template <class T>
void List<T> ::Insert_val(const T& m, const T& x)			//按值插入
{
	if (_head == NULL)
	{
		cout << "List is empty!!!" << endl;
		return;
	}
	else
	{
		LinkNode<T> * n = Find(m);
		if (n != NULL)
		{
			LinkNode<T> * tmp = _CreateNode(x);
			tmp->_next = n->_next;
			n->_next = tmp;
		}
	}
}



template <class T>
void List<T> ::Delete_pos(size_t pos)		//删除第n个
{
	int len = Length();
	if (pos <= len)
	{
		if (_head == NULL)
		{
			cout << "List is empty!!!" << endl;
			return;
		}
		else if (_head->_next == NULL && pos == 1)
		{
			clear(_head);
		}
		else
		{
			LinkNode<T> * begin = _head->_next;
			LinkNode<T> * tmp = _head;
			if (pos == 1)
			{
				PopFront();
			}
			else
			{
				pos = pos - 1;
				while (--pos)
				{
					if (begin->_next != NULL)
					{
						begin = begin->_next;
						tmp = tmp->_next;
					}
				}
				tmp->_next = begin->_next;
				begin->_next = tmp;
			}
		}
	}
	else
	{
		cout << "Input Error!!!" << endl;
	}
}


template <class T>
void List<T> ::Delete_val(const T& x)			//按值删除
{
	if (_head == NULL)
	{
		cout << "List is empty!!!" << endl;
		return;
	}
	else if (_head->_next == NULL && _head->_data == x)
	{
		clear(_head);
		return;
	}
	else
	{
		if (_head->_data == x)
		{
			PopFront();
			return;
		}
		else
		{
			LinkNode<T> * n = Find(x);
			if (n != NULL)
			{
				if (n->_next == NULL)
				{
					PopBack();
					return;
				}
				if (n->_next != NULL)
				{
					LinkNode<T> * tmp = n;
					n->_prev->_next = n->_next;
					n->_prev = n->_next->_prev;
					clear(n);
					return;
				}
			}
		}
	}
}



template <class T>
LinkNode <T> * List <T> ::Reverse()			// 逆置
{
	if (_head == NULL || _head->_next == NULL)
	{
		return NULL;
	}
	else
	{
		LinkNode<T> * Newhead = _head;
		LinkNode<T> * Newtail = _head;
		LinkNode<T> * begin = _head->_next;
		LinkNode<T> *tmp = NULL;
		_head->_next = NULL;
		while (begin != NULL)
		{
			tmp = begin;
			begin = begin->_next;
			tmp->_next = Newhead;
			Newhead->_prev = tmp;
			Newhead = tmp;
		}
		_head = Newhead;
		_tail = Newtail;
	}
}