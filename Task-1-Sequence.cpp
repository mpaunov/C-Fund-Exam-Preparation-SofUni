#include <iostream>

int main(){

    int num;
    int maxSequence = 0;
    int previousNum = -99999999999;
    int counter = 0;


    std::cin >> num;

    for(int i = 0; i < num; i++){
        int currNum;
        std::cin >> currNum;

        if(currNum > previousNum){
            counter++;
            if(counter > maxSequence){
                maxSequence = counter;
            }
        }else {
            counter = 1;
        }
        previousNum = currNum;
    }

    std::cout << maxSequence << std::endl;

    return 0;
}
