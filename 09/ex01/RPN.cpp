#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->_stack = other._stack;
	return (*this);
}

RPN::~RPN() {}


bool RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}



int RPN::applyOperator(int a, int b, char op) const
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
	{
		if (b == 0)
			throw std::runtime_error("division by zero");
		return (a / b);
	}
	throw std::runtime_error("invalid operator");
}


int RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
		{
			_stack.push(token[0] - '0');
		}
		else if (token.length() == 1 && isOperator(token[0]))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("not enough operands");
				
        	int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();

			int res = applyOperator(a, b, token[0]);
			_stack.push(res);
        
        }
		else
		{
			throw std::runtime_error("invalid token");
		}
	}

	if (_stack.size() != 1)
		throw std::runtime_error("invalid expression");

	return _stack.top();
}


