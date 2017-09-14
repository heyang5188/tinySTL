#ifndef LIST_H
#define LIST_H
class List
{
	struct Node
	{};
public:
	class const_iterator{};
	class iterator : public const_iterator{};
public:
	List();
	List(const List&rhs);
	~List();
	List &operator=(const List&rhs);
	List( List &&rhs);
	List &operator=(List &&rhs);
	iterator begin();
	const_iterator cbegin() const;
	iterator end();
	cosst_iterator cend() const;

	int size() const { return theSize(); }
	bool empty() const { return theSize() == 0; }
	void clear()
	{
		while (!empty())
			pop_front();
	}
	
private:
	int theSize();
	Node *head;
	Node *tail;
};
#endif // !LIST_H

