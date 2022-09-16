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

	std::cout << GRN "========== ft_test NAMESPADE FT ==========\n" NC;
	ft_test_ft();
	std::cout << YLW "\n========== ft_test NAMESPADE STD ==========\n" NC;
	ft_test_std();

	return (0);
}