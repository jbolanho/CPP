#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::parseInput(char **argv)
{
	std::vector<int> numbers;
	for (int i = 1; argv[i]; i++)
	{
		validateNumber(argv[i]);
		long num = std::atol(argv[i]);
		if (num > INT_MAX)
			throw std::runtime_error("Error");
		numbers.push_back(static_cast<int>(num));
	}
	if (numbers.empty())
		throw std::runtime_error("Error");
	return numbers;
}

void PmergeMe::validateNumber(const std::string &str)
{
	if (str.empty())
		throw std::runtime_error("Error");
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			throw std::runtime_error("Error");
	}
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &v)
{
	if (v.size() <= 1)
		return;

    std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		if (v[i] > v[i + 1])
			pairs.push_back(std::make_pair(v[i + 1], v[i]));
		else
			pairs.push_back(std::make_pair(v[i], v[i + 1]));
	}
	int leftover = (v.size() % 2) ? v.back() : -1;
    
    std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i)
		mainChain.push_back(pairs[i].second);
	mergeInsertSortVector(mainChain);
    
    std::vector<int> pend;
	for (size_t i = 0; i < pairs.size(); ++i)
		pend.push_back(pairs[i].first);

	for (size_t i = 0; i < pend.size(); ++i)
	{
		std::vector<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
		mainChain.insert(pos, pend[i]);
	}

	if (leftover != -1)
	{
		std::vector<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
		mainChain.insert(pos, leftover);
	}

	v = mainChain;
}


void PmergeMe::mergeInsertSortDeque(std::deque<int> &d)
{
	if (d.size() <= 1)
		return;

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < d.size(); i += 2)
	{
		if (d[i] > d[i + 1])
			pairs.push_back(std::make_pair(d[i + 1], d[i]));
		else
			pairs.push_back(std::make_pair(d[i], d[i + 1]));
	}
	int leftover = (d.size() % 2) ? d.back() : -1;

	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i)
		mainChain.push_back(pairs[i].second);
	mergeInsertSortDeque(mainChain);

	std::deque<int> pend;
	for (size_t i = 0; i < pairs.size(); ++i)
		pend.push_back(pairs[i].first);

	for (size_t i = 0; i < pend.size(); ++i)
	{
		std::deque<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
		mainChain.insert(pos, pend[i]);
	}

	if (leftover != -1)
	{
		std::deque<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
		mainChain.insert(pos, leftover);
	}

	d = mainChain;
}

template<typename T>
void PmergeMe::printContainer(const T &container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<typename T>
double PmergeMe::getElapsedTime(void (*sortFunc)(T &), T &container)
{
	std::clock_t start = std::clock();
	sortFunc(container);
	std::clock_t end = std::clock();
	return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; 
}


void PmergeMe::sortAndDisplay(char **argv)
{
	std::vector<int> vec = parseInput(argv);
	std::deque<int> deq(vec.begin(), vec.end());

	std::cout << "Before: ";
	printContainer(vec);

	double vecTime = getElapsedTime<std::vector<int> >(mergeInsertSortVector, vec);
	double deqTime = getElapsedTime<std::deque<int> >(mergeInsertSortDeque, deq);

	std::cout << "After: ";
	printContainer(vec);

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vec.size()
			  << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
			  << " elements with std::deque  : " << deqTime << " us" << std::endl;
}