#include "stdafx.h"
#include "String.h"
#include <string>

String & String::operator=(const String &s)
{
	if (p) a.deallocate(p, sz);
	p = s.p;
	sz = s.sz;
	return *this;
}

String & String::operator=(String &&rhs) noexcept
{
	std::cout << "String类使用了移动构造函数" << std::endl;
	if (this != &rhs){
		if (p)
			a.deallocate(p, sz);
	p = rhs.p;
	sz = rhs.sz;
	rhs.p = 0;
	rhs.sz = 0;
	}
	return *this;
}

String & String::operator=(std::initializer_list<char> il)
{
	if (p)
		a.deallocate(p, sz);
	p = a.allocate(sz = il.size());
	std::uninitialized_copy(il.begin(), il.end(), p);
	return *this;
}

String & String::operator=(const char *cp)
{
	if (p) a.deallocate(p, sz);
	sz = strlen(cp);
	p = a.allocate(sz);
	std::uninitialized_copy(cp, cp + sz, p);
	return *this;
}

String & String::operator=(char c)
{
	if (p) a.deallocate(p, sz);
	sz = 1;
	p = a.allocate(sz);
	*p = c;
	return *this;
}
String operator+(const String & lhs, const String &rhs)
{
	return add(lhs, rhs);
}
String add(const String &lhs , const String &rhs)
{
	String ret;
	ret.sz = rhs.size() + lhs.size();
	ret.p = String::a.allocate(ret.sz);
	std::uninitialized_copy(lhs.begin(), lhs.end(), ret.p);
	std::uninitialized_copy(rhs.begin(), rhs.end(), ret.p + lhs.sz);
	return ret;
}

std::ostream & operator<<(std::ostream &os, const String &s)
{
	return print(os, s);
}

std::ostream & print(std::ostream &os, const String &s)
{
	auto p = s.begin();
	while (p != s.end())
		os << *p++;
	return os;
}

bool operator==(const String &lhs, const String &rhs)
{
	bool x;
	if (lhs.size() == rhs.size()) {
		auto l = lhs.begin();
		auto r = rhs.begin();
		while (l != lhs.end()) {
			if (*l++ == *r++){
				x = true;
			}
			else {
				return false;
			}
		}
	}
	else
		x = false;
	return x;
}

bool operator!=(const String &lhs, const String &rhs)
{
	return !(lhs==rhs);
}

String make_plural(size_t ctr, const String &word, const String &ending)
{
	return (ctr != 1) ? add(word, ending) : word;
}
