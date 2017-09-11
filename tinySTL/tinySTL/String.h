#ifndef STRING_H
#define STRING_H
#include <memory>
#include <initializer_list>
#include <cstring>
#include <algorithm>
#include <cstddef>
#include <iostream>
class String {
	friend String operator+(const String&, const String&);
	friend String add(const String&, const String&);
	friend std::ostream &operator<<(std::ostream&, const String&);
	friend std::ostream &print(std::ostream&, const String&);
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
public:
	String() : sz(0), p(nullptr) { }
	
	String(String &&s) noexcept : sz(s.size()), p(s.p) {
		std::cout << "move constructor has been called!" << std::endl;
		s.sz = 0; s.p = nullptr; }
	String &operator=(const String &);
	String(const char *cp) :
		sz(std::strlen(cp)), p(a.allocate(sz))
	{
		std::uninitialized_copy(cp, cp + sz, p);
	}

	// copy constructor: allocate a new copy of the characters in s
	String(const String &s) :sz(s.sz), p(a.allocate(s.sz))
	{
		std::uninitialized_copy(s.p, s.p + sz, p);
	}
	String &operator=(String &&) noexcept;
	String &operator=(std::initializer_list<char>);

	~String() throw() { if (p) a.deallocate(p, sz); }
	// additional assignment operators
	String &operator=(const char*);         // car = "Studebaker"
	String &operator=(char);                // model = 'T'

	const char *begin() { return p; }
	const char *begin() const { return p; }
	const char *end() { return p + sz; }
	const char *end() const { return p + sz; }
	size_t size() const { return sz; }
	void swap(String &s)
	{
		auto tmp = p; p = s.p; s.p = tmp;
		auto cnt = sz; sz = s.sz; s.sz = cnt;
	}
private:
	std::size_t sz;
	char *p;
	static std::allocator<char> a;
};
String make_plural(size_t ctr, const String &, const String &);
inline
void swap(String &s1, String &s2)
{
	s1.swap(s2);
}
#endif // !STRING_H

