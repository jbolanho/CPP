#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <sstream>
# include <iostream>
# include <stdexcept>
# include <cctype>

class RPN
{
    private:
        std::stack<int> _stack;

        bool isOperator(char c) const;
        int applyOperator(int a, int b, char op) const;

    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        int evaluate(const std::string &expression);
};

#endif