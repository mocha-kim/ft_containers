#include "test.hpp"

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

	std::cout << "==========================================\n";
	std::cout << "               FT MAIN TEST               \n";
	std::cout << "==========================================\n";
	std::cout << GRN "---------- ft_test NAMESPADE FT ----------\n" NC;
	ft_test_ft();
	std::cout << YLW "--------- ft_test NAMESPADE STD ----------\n" NC;
	ft_test_std();

	std::cout << "\n==========================================\n";
	std::cout << "                VECTOR TEST               \n";
	std::cout << "==========================================\n";
	vector_test();

	std::cout << "\n==========================================\n";
	std::cout << "                 STACK TEST               \n";
	std::cout << "==========================================\n";
	stack_test();

	std::cout << "\n==========================================\n";
	std::cout << "                   MAP TEST                 \n";
	std::cout << "==========================================\n";
	map_test();

	return 0;
}