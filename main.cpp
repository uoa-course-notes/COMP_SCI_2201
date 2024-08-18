#include <iostream>
#include <vector>
#include <algorithm>

//
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

// Integer addition 
int GRADE_SCHOOL_INTEGER_SUBTRACTION(std::vector<int> i1, std::vector<int> i2, int B){

  return 0;
}
// Working with base 2
int GRADE_SCHOOL_INTEGER_ADDITION(std::vector<int> i1, std::vector<int> i2, int B){

  return 0;
}

// Working with base 10


// Karatsuba Algorithm for Integer Multiplication
int KARATSUBA_ALGORITHM(std::vector<int> i1, std::vector<int> i2, int B){
  return 1;
}


// Integer division (Post-graduate only)
int INTEGER_DIVISION(std::vector<int> i1, std::vector<int> i2, int B){
  return 0;
}


int main(int argc, char* argv[]){
  
    // Declare and initialize the variables extracted from the command-line argument  
    std::string pre_I1 = argv[1];
    std::string pre_I2 = argv[2];
    std::string pre_B = argv[3];
    // std::cout << pre_I1 << std::endl;

    // Extract each digit into a list of integers.
    std::vector<int> I1 = digits_transform_alloc(pre_I1);
    std::vector<int> I2 = digits_transform_alloc(pre_I2);
    std::vector<int> B_vec = digits_transform_alloc(pre_B);

    int B = B_vec[0];
  
    int res_addition = GRADE_SCHOOL_INTEGER_ADDITION(I1, I2, B);
    int res_multiplication = KARATSUBA_ALGORITHM(I1, I2, B);
    int res_division = INTEGER_DIVISION(I1, I2, B);


    std::cout << res_addition 
              << " "
              <<  res_multiplication 
              << " " 
              << res_division;

  return 0;
}
