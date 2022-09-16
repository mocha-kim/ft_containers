#include "test.hpp"

#include <vector>
#include <map>
#include <stack>

#include "../includes/vector.hpp"
#include "../includes/map.hpp"
#include "../includes/stack.hpp"

template<typename T>
class MutantStackFt : public ft::stack<T>
{
public:
	MutantStackFt() {}
	MutantStackFt(const MutantStackFt<T>& src) { *this = src; }
	MutantStackFt<T>& operator=(const MutantStackFt<T>& rhs) 
	{
		this->_container = rhs._container;
		return *this;
	}
	~MutantStackFt() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->_container.begin(); }
	iterator end() { return this->_container.end(); }
};

template<typename T>
class MutantStackStd : public std::stack<T>
{
public:
	MutantStackStd() {}
	MutantStackStd(const MutantStackStd<T>& src) { *this = src; }
	MutantStackStd<T>& operator=(const MutantStackStd<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStackStd() {}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int ft_test_ft()
{
	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}

	ft::vector<int> foo(3, 15);
	ft::vector<int> bar(5, 42);

	ft::vector<int>::const_iterator it_foo = foo.begin();
	ft::vector<int>::const_iterator it_bar = bar.begin();

	std::cout << "BEFORE SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	std::cout << foo.size() << ", " << foo.capacity() << "\n";
	std::cout << "bar contains:" << std::endl;
	std::cout << bar.size() << ", " << bar.capacity() << "\n";

	foo.swap(bar);

	std::cout << "AFTER SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	std::cout << foo.size() << ", " << foo.capacity() << "\n";
	std::cout << "bar contains:" << std::endl;
	std::cout << bar.size() << ", " << bar.capacity() << "\n";

	std::cout << "Iterator validity:" << std::endl;
	std::cout << (it_foo == bar.begin()) << std::endl;
	std::cout << (it_bar == foo.begin()) << std::endl;

	foo.assign(10, 0);

	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStackFt<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStackFt<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}


int ft_test_std()
{
	std::vector<std::string> vector_str;
	std::vector<int> vector_int;
	std::stack<int> stack_int;
	std::vector<Buffer> vector_buffer;
	std::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	std::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	std::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}

	std::vector<int> foo(3, 15);
	std::vector<int> bar(5, 42);

	std::vector<int>::const_iterator it_foo = foo.begin();
	std::vector<int>::const_iterator it_bar = bar.begin();

	std::cout << "BEFORE SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	std::cout << foo.size() << ", " << foo.capacity() << "\n";
	std::cout << "bar contains:" << std::endl;
	std::cout << bar.size() << ", " << bar.capacity() << "\n";

	foo.swap(bar);

	std::cout << "AFTER SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	std::cout << foo.size() << ", " << foo.capacity() << "\n";
	std::cout << "bar contains:" << std::endl;
	std::cout << bar.size() << ", " << bar.capacity() << "\n";

	std::cout << "Iterator validity:" << std::endl;
	std::cout << (it_foo == bar.begin()) << std::endl;
	std::cout << (it_bar == foo.begin()) << std::endl;

	foo.assign(10, 0);

	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(std::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		std::map<int, int> copy = map_int;
	}
	MutantStackStd<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStackStd<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}