#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include "nlohmann/json.hpp"
#include "solution.hpp"

using json = nlohmann::json;
using namespace std;


int main(void){
        json data = json::array();

        for(int i = 1 ; i <= 13 ; i++){
                for(int j = i ; j <= 13 ; j++){
                        for(int k = j ; k <= 13 ; k++){
                                for(int l = k ; l <= 13 ; l++){
                                        vector<Expression> expr = {
                                                {(double)i , to_string(i)} ,
                                                {(double)j , to_string(j)} ,
                                                {(double)k , to_string(k)} ,
                                                {(double)l , to_string(l)}
                                        };
                                        set<string> res;
                                        solution(expr , res);

                                        if(!res.empty()){
                                                json entry;
						entry["nums"] = {i , j , k , l};
						
						vector<string> sols;
						int cnt = 0;
						for(auto s : res){
							sols.push_back(s);
							cnt++;
							if(cnt == 3)break;
						}

						entry["solutions"] = sols;
						data.push_back(entry);
					}
				}
			}
		}
	}

	ofstream outFile("challenges.json");
	outFile << data << endl;
	return 0;
}


