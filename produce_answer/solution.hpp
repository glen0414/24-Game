#include <iostream>
#include <vector>
#include <string>
#include <set>
#define epsilon 1e-6

typedef struct Expression{
        double val;
	std::string str;
}Expression;

void solution(std::vector<Expression>& expr , std::set<std::string>& res);

