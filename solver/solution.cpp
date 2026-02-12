#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include "solution.hpp"

using namespace std;

bool is24(double val){
	return (abs(val - 24) <= epsilon);
}

void solution(vector<Expression>& expr , set<string>& res){
	if(expr.size() == 1){
		if(is24(expr[0].val))
			res.insert(expr[0].str);
		return;
	}

	// take two number do +,-,*,/
	for(int i = 0 ; i < expr.size() ; i++){
		for(int j = 0 ; j < expr.size() ; j++){
			if(i == j)continue;

			vector<Expression> next;
			for(int k = 0 ; k < expr.size() ; k++){
				if(k != i && k != j)
					next.push_back(expr[k]);
			}

			Expression a = expr[i] , b = expr[j];
			// plus
			if(a.val <= b.val){
				next.push_back({a.val + b.val , "(" + a.str + " + " + b.str + ")"});
				solution(next , res);
				next.pop_back(); //restore
			}

			// substract
			next.push_back({a.val - b.val , "(" + a.str + " - " + b.str + ")"});
			solution(next , res);
			next.pop_back();

			// multiple
			if(a.val <= b.val){
				next.push_back({a.val * b.val , "(" + a.str + " * " + b.str + ")"});
				solution(next , res);
				next.pop_back();
			}

			// divide
			if(b.val > epsilon){
				next.push_back({a.val / b.val , "(" + a.str + " / " + b.str + ")"});
				solution(next , res);
				next.pop_back();
			}
		}
	}
}


