#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <sstream>
# include <ctime>
# include <iomanip>
# include <stdexcept>
# include <algorithm>
# include <cstdlib>
# include <climits>

class PmergeMe
{
    private:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

    public:
        static void	sortAndDisplay(char **argv);

    private:
        static std::vector<int>	parseInput(char **argv);
        static void				validateNumber(const std::string &str);

        static void				mergeInsertSortVector(std::vector<int> &v);
        static void				mergeInsertSortDeque(std::deque<int> &d);

        template<typename T>
        static void	printContainer(const T &container);

        template<typename T>
        static double	getElapsedTime(void (*sortFunc)(T &), T &container);
};

#endif