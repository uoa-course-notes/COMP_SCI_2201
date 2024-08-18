#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>


std::vector<int> digits_transform_alloc(const std::string& s)
{
    std::vector<int> result(s.size());
    std::transform(
        s.begin(), s.end(),
        result.begin(), 
        [](char ch) {return ch - '0';}
        );
    return result;
}

void print_digits(const std::vector<int>& result){
    u_int size = result.size();
    std::cout << "<";
    for (int i=0; i<size; i++){
        if (i == size -1) std::cout << result[i];
        else std::cout << result[i] << ",";   
    }
    std::cout << ">" << std::endl;
}


int main(int argc, char *argv[]){
    // std::string sentence = "I would like to have a talk with my friend.";
    // char delimiter = ' ';

    // std::istringstream iss(sentence);
    // std::string word = "";

    // while (iss >> word){
    //     std::cout << word << std::endl;
    // }

    // int I1 = atoi(argv[1]);
    // int I2 = atoi(argv[2]);
    // int B = atoi(argv[3]);
    std::string pre_I1 = argv[1];
    std::string pre_I2 = argv[2];
    std::string pre_B = argv[3];
    // std::cout << pre_I1 << std::endl;

    // Extract each digit into a list of integers.
    std::vector<int> I1 = digits_transform_alloc(pre_I1);
    std::vector<int> I2 = digits_transform_alloc(pre_I2);
    std::vector<int> B = digits_transform_alloc(pre_B);

    print_digits(I1);    
    print_digits(I2);    
    print_digits(B);    
    
    
    return 0;
}

// ./run.sh 111111101111011111110110110001000101111000011100111