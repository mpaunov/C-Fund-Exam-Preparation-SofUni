#include <iostream>
#include <string>
#include <sstream>
#include <stack>

int getActualFrom(const std::string& text, int from){
    while(from > 0 && (text[from - 1] != ' ')){
        from--;
    }
    return from;
}
int getActualTo(const std::string& text, int to){
    while(to < text.size() - 1 && (text[to + 1] != ' ')){
        to++;
    }
    return to;
}

int main () {

    std::string text;
    getline(std::cin, text);

    std::string line;
    getline(std::cin, line);

    std::stack<std::string> copyContainer;

    while(line != "end"){
        std::istringstream lineIn(line);

        std::string command;

        lineIn >> command;

        if(command == "copy"){
            int from, to;
            lineIn >> from >> to;

            from = getActualFrom(text, from);
            to = getActualTo(text, to);

            std::string copyStr = text.substr(from, 1 + (to - from));

            copyContainer.push(copyStr);

        } else if(command == "paste"  && !copyContainer.empty()){
            int position;
            lineIn >> position;

            std::string copiedStr = copyContainer.top();
            copyContainer.pop();

            if(text[position] == ' '){
                text.insert(position, std::string(" ") + copiedStr);
            }else {
                text.insert(position, copiedStr);
            }
        }
        getline(std::cin, line);

    }

    std::cout << text << std::endl;

    return 0;
}
