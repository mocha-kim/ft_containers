#include "test.hpp"

template<class T>
static bool print_value_compare(const T& ft, const T& std)
{
	bool ret = t1 == t2;
	std::cout << "> ";
	if (ret)
		std::cout << GRN "OK\n" NC;
	else
		std::cout << RED "KO\n" NC;
	return ret;
}

template<class T>
static bool print_value(const T& ft, const T& std)
{
	std::cout << "> \n"
    std::cout << " FT: " << ft << "\n";
    std::cout << "STD: " << std << "\n";
    return t1 == t2 ? true : false;
}

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	std::cout << GRN "========== ft_test NAMESPADE FT ==========\n" NC;
	ft_test_ft();
	std::cout << YLW "\n========== ft_test NAMESPADE STD ==========\n" NC;
	ft_test_std();

	return 0;
}