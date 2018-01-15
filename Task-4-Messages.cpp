#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>

class Message{
private:
    std::string message;
    int priority;
public:
    Message(const std::string& message, int priority):
        message(message),
        priority(priority){
    }

    bool operator>(const Message& other) const {
        return this->priority > other.priority;
    }
    std::string getMessage(const Message&){
        return this->message;
    }
};

int getSingleNumberFromLine(){
    std::string line;
    getline(std::cin, line);
    std::istringstream inputLine(line);
    int number;
    inputLine >> number;

    return number;
}

int getPriority(const std::string& text, const std::string& keyword){
    std::istringstream textInWords(text);
        std::string word;

        int priority = 0;
        while(textInWords >> word){
            if(word == keyword){
                priority++;
            }
        }

    return priority;
}

int main() {
    std::cin.sync_with_stdio(false);

    std::string keyword;
    getline(std::cin, keyword);
    int pageSize = getSingleNumberFromLine();
    std::string line;
    getline(std::cin, line);

    std::priority_queue<Message, std::vector<Message>, std::greater<Message> > inbox;

    while(line != "."){

        int priority = getPriority(line, keyword);

        if(priority > 0){

        Message currentMessage(line, priority);

        inbox.push(currentMessage);

            if(inbox.size() > pageSize){
                inbox.pop();
            }
        }

        getline(std::cin, line);
    }
    std::vector<std::string> result;
    while(!inbox.empty()){
        Message currentObj(inbox.top());
        inbox.pop();
        std::string currentText = currentObj.getMessage(currentObj);
        result.push_back(currentText);
    }

    for(int i = result.size() - 1; i >= 0; i--){
        std::cout << result[i] << std::endl;
    }

    return 0;
}
