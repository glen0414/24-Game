#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "solution.hpp"

using namespace std;

int main(void){
	int a , b , c , d;
	cin >> a >> b >> c >> d;
	vector<Expression> expr = {
		{(double)a , to_string(a)} , 
		{(double)b , to_string(b)} ,
		{(double)c , to_string(c)} ,
		{(double)d , to_string(d)}
	};
	set<string> res;
	solution(expr , res);
	for(auto& s : res)
		cout << s << endl;
	return 0;
}

