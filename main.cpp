#include <iostream>
#include <sstream>



// Integer addition 

// Working with base 2
int GRADE_SCHOOL_INTEGER_ADDITION(int i1, int i2, int B){

  return 0;
}

// Working with base 10


// Karatsuba Algorithm for Integer Multiplication
int KARATSUBA_ALGORITHM(int i1, int i2, int B){
  return 1;
}


// Integer division (Post-graduate only)
int INTEGER_DIVISION(int i1, int i2, int B){
  return 0;
}


int main(int argc, char* argv[]){
  
  // Declare and initialize the variables extracted from the command-line argument  
  int I1 = std::atoi(argv[1]);
  int I2 = std::atoi(argv[2]);
  int B = std::atoi(argv[3]);


  
  // Output the extracted values
  // std::cout << "I1: " << I1 << std::endl;
  // std::cout << "I2: " << I2 << std::endl;
  // std::cout << "B: " << B << std::endl;
  
  int res_addition = GRADE_SCHOOL_INTEGER_ADDITION(I1, I2, B);
  int res_multiplication = KARATSUBA_ALGORITHM(I1, I2, B);
  int res_division = INTEGER_DIVISION(I1, I2, B);


  std::cout << res_addition 
            << " "
            <<  res_multiplication 
            << " " 
            << res_division
            << std::endl;

  return 0;
}
