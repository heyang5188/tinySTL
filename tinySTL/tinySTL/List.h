#ifndef LIST_H
#define LIST_H
#include <utility>

namespace herb{
template<typename T>
class list
{
	struct Node
	{
		T data;
		Node *prev;
		Node *next;
		Node(const T &t = T(),Node * p = nullptr,Node *n = nullptr)
			:data(t),prev(p),next(n) {}
		Node(const T&& t ,Node* p =nullptr,Node*n = nullptr)
			:data(std::move(t)),prev(p),next(n){}
	};
public:
	class const_iterator
	{
	public:
		const_iterator():current(nullptr){}
		const T & operator*()const
		{
			return retrieve();
		}
		const_iterator & operator++()
		{
			current = current->next;
			return *this;
		}
		const_iterator  operator++(int)
		{
			auto olddata = *this;
			++(*this);
			return olddata;
		}
		bool operator==(const const_iterator &rhs)const
		{
			return current == rhs.current;
		}
		bool operator!=(const const_iterator &rhs)const
		{
			return !(*this == rhs);
		}
	protected:
		Node *current;
		T & retrieve ( )const 
		{
			return current->data;
		}
		const_iterator(Node *p):current(p)sd
		{}
		friend class list<T>;
	};
	class iterator : public const_iterator
	{
	public:
		iterator(){}
		T & operator*()
		{	return const_iterator::retrieve();	}
		const T& operator*()const 
		{ return const_iterator::operator*(); }
		
		iterator& operator++()
		{	
			this->current = this->current->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}
		
	protected:
		iterator(Node *p):const_iterator(p){}
		friend class list<T>;
	};
public:
	list() { init(); }
	list(const list&rhs)
	{
		init();
		for (auto &x : rhs)
			push_back(x);
	}
	~list() { 
		clear(); 
		delete head;
		delete tail;
	}
	list &operator=(const list&rhs)
	{
		list copy = rhs;
		std::swap(*this, copy);
		return *this;
	}
	list(list &&rhs):theSize(rhs.theSize),head(rhs.head),tail(rhs.tail)
	{
		rhs.theSize = 0;
		rhs.head = nullptr;
		rhs.tail = nullptr;
	}
	list &operator=(list &&rhs)
	{
		std::swap(theSize.rhs.theSize);
		std::swap(head, rhs.head);
		std::swap(tail, rhs.tail);
		return *this;
	}

	iterator begin() { return { head->next }; }
	const_iterator cbegin() const { return { head->next }; }
	iterator end() { return { tail }; }
	const_iterator cend() const { return { tail }; }

	int size() const { return theSize; }
	bool empty() const { return theSize == 0; }
	void clear()
	{
		while (!empty())
			pop_front();
	}
	T& front() { return *begin(); }
	const T& front()const { return *begin(); }
	T& back() { return *--end(); }
	const T& back()const { renturn *--end(); }
	void push_front(const T&x)
	{
		insert(begin(), x);
	}
	void push_front(T&&x)
	{
		insert(begin, std::move(x));
	}
	void push_back(const T&x)
	{
		insert(end(), x);
	}
	void push_back(T&&x)
	{
		insert(end(), std::move(x));
	}
	void pop_front()
	{
		erase(begin());
	}
	void pop_back()
	{
		erase(--end());
	}
	iterator insert(iterator &itr, const T&t)
	{
		Node *p = itr.current;
		theSize++;
		return { p->prev = p->prev->next = new Node(x,p->prev,p) };
	}
	iterator insert(iterator &itr, T&&x)
	{
		Node *p = itr.current;
		++theSize;
		return { p->prev = p->prev->next = new Node{x,p->prev,p} };
	}
	iterator erase(iterator itr)
	{
		Node *p = itr.current;
		iterator retVal{ p->next };
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		theSize--;
		return retVal;
	}
	iterator erase(iterator from, iterator to)
	{
		for (iterator itr = from; itr != to)
			itr = erase(itr);
		return to;
	}
private:
	int theSize;
	Node *head;
	Node *tail;

	void init() {
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}
};
}
#endif // !LIST_H

