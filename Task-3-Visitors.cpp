#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

int main(){
    std::cin.sync_with_stdio(false);

    typedef std::pair<std::string, int> visitor;

    std::map<std::string, visitor> visitorsById;
    std::vector<int> results;

    std::string command;
    std::cin >> command;

    while(command != "end"){

        if(command == "entry"){
            std::string id, name;
            int age;
            std::cin >> id >> name >> age;

            visitorsById[id] = visitor(name, age);

        }else if(command == "name"){
            std::string name;
            std::cin >> name;

            int counter = 0;

            for(auto member : visitorsById){
                if(member.second.first == name){
                    counter++;
                }
            }
            results.push_back(counter);


        }else if(command == "age"){
            int beginAge, endAge;
            std::cin >> beginAge >> endAge;

            int counter = 0;
            for(auto member : visitorsById){
                if(member.second.second >= beginAge && member.second.second < endAge){
                    counter++;
                }
            }
            results.push_back(counter);
        }

        std::cin >> command;
    }

    for(int i = 0; i < results.size(); i++){
        std::cout << results[i] << std::endl;
    }

    return 0;
}
