#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		PmergeMe::sortAndDisplay(argv);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}