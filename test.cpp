#include <sstream>
#include <iostream>

#include <string>



int main(int argc, char *argv[]){
    std::string sentence = "I would like to have a talk with my friend.";
    char delimiter = ' ';

    std::istringstream iss(sentence);
    std::string word = "";

    while (iss >> word){
        std::cout << word << std::endl;
        
    }
    
    return 0;
}