#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
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


// Use this to convert the resulting vector of strings into a string
std::string digits_transform_output(const std::vector<std::string>& s){
    std::string result = "";
    for (const std::string& elem: s){   
        result += elem;
    }

    // Remove leading zeros from the result
    result = result.erase(0, std::min(result.find_first_not_of("0"), result.size() -1));
    return result;
}



template <typename T>
void print_digits(const std::vector<T>& result){
    u_int size = result.size();
    std::cout << "<";
    for (u_int i=0; i<size; i++){
        if (i == size -1) std::cout << result[i];
        else std::cout << result[i] << ",";   
    }
    std::cout << ">" << std::endl;
}



// Solving the alignment problem
void align(
    std::vector<int>& I1, 
    std::vector<int>& I2)
{
    int s1 = I1.size();
    int s2 = I2.size();

    if (s1 == s2) return;
    else{
        // int max_size = std::max(I1.size(), I2.size());	
        int offset = std::abs(s1 - s2);
        if (s1 > s2){
            // Prepend zero's to I2
            I2.insert(I2.begin(), offset, 0);            
        }
        else{
            // Prepend zero's to I1
            I1.insert(I1.begin(), offset, 0);            
        }
    }
}

// Working with base 2
std::vector<std::string> GRADE_SCHOOL_INTEGER_ADDITION(std::vector<int> I1, std::vector<int> I2, int B){
  align(I1, I2);
//   if (B < 2 && B > 9) return {"-1"};
  std::map<int, std::string> hex_map = {
    {10,"A"},
    {11,"B"},
    {12,"C"},
    {13,"D"},
    {14,"E"},
    {15,"F"}  
    };
  int c = 0;
  // Now I1 and I2 must be of the same size
  int s1 = I1.size();
//   int s2 = I2.size();
  // vector of sums 
    std::vector<std::string> S(s1);
  
  
  for (int i = s1-1; i>= 0; i--){ // BEGIN 
    if (I1[i] + I2[i] + c >= B){
        S[i] = std::to_string((I1[i] + I2[i] + c) % B);
        // Convert to appropriate character (for higher bases)
        std::map<int, std::string>::iterator it = hex_map.find(stoi(S[i]));        
        if (it != hex_map.end()){
            S[i] = it->second;
        }
        // std::cout << "S[i] = " << S[i] << std::endl;
        // std::cout << "In 1st if -- Enter:" << std::endl;
        // std::cin.get();
        c = 1;
  
    }
    else{ // I1[i] + I2[i] + c < B
        S[i] = std::to_string(I1[i] + I2[i] + c);
        //
        std::map<int, std::string>::iterator it = hex_map.find(stoi(S[i]));        
        if (it != hex_map.end()){
            S[i] = it->second;
        }
        c = 0;
        // std::cout << "In 2nd if -- Enter:" << std::endl;
        // std::cin.get();
    }
  } // END 

  return S;
}


std::vector<std::string> GRADE_SCHOOL_INTEGER_SUBTRACTION(std::vector<int> I1, std::vector<int> I2, int B){
  align(I1, I2);
  std::map<int, std::string> hex_map = {
    {10,"A"},
    {11,"B"},
    {12,"C"},
    {13,"D"},
    {14,"E"},
    {15,"F"}
  };
//   int c = 0;
  // Now I1 and I2 must be of the same size
  int s1 = I1.size();
  //   int s2 = I2.size();
  // vector of sums 
  std::vector<std::string> S(s1);
    for (int i = s1-1; i >= 0; i--){
        if (I1[i] - I2[i] < 0){
            I1[i] = I1[i] + B;

            S[i] = std::to_string(I1[i] - I2[i]);
            std::map<int, std::string>::iterator it = hex_map.find(stoi(S[i]));        
            if (it != hex_map.end()){
                S[i] = it->second;
            }
            // Decrement the next digit by 1 
            I1[i-1]--;
        }
        else{ // I1[i] - I2[i] >= 0
            S[i] = std::to_string(I1[i] - I2[i]);
            std::map<int, std::string>::iterator it = hex_map.find(stoi(S[i]));        
            if (it != hex_map.end()){
                S[i] = it->second;
            }
        }
    }

  return S;
}


// std::vector<std::string> KARATSUBA_ALGORITHM(std::vector<int> I1, std::vector<int> I2, int B){
//   align(I1, I2);
//   std::map<int, std::string> hex_map = {
//     {10,"A"},
//     {11,"B"},
//     {12,"C"},
//     {13,"D"},
//     {14,"E"},
//     {15,"F"}
//   };
//   // Now I1 and I2 must be of the same size
//   int s1 = I1.size();
//   std::vector<std::string> S(s1);





//   return S;
// }

// Karatsuba Multiplication
std::vector<std::string> KARATSUBA_ALGORITHM(std::vector<int> I1, std::vector<int> I2, int B) {
    align(I1, I2);
    int n = I1.size();
    if (n <= 4) {  // Base case: Use grade-school multiplication for small numbers
        return GRADE_SCHOOL_INTEGER_ADDITION(I1, I2, B);  // Adjust this to the correct multiplication
    }

    int mid = n / 2; // Integer division unless n is not an integer. 

    // // Split I1 into two halves
    std::vector<int> I1_low(I1.begin() + mid+1, I1.end());
    std::vector<int> I1_high(I1.begin(), I1.begin() + mid);

    // // Split I2 into two halves
    std::vector<int> I2_low(I2.begin() + mid+1, I2.end());
    std::vector<int> I2_high(I2.begin(), I2.begin() + mid);

    // // Recursively calculate the three products
    // std::vector<std::string> z0 = KARATSUBA_ALGORITHM(I1_low, I2_low, B);
    // std::vector<std::string> z1 = KARATSUBA_ALGORITHM(GRADE_SCHOOL_INTEGER_ADDITION(I1_low, I1_high, B),
    //                                                   GRADE_SCHOOL_INTEGER_ADDITION(I2_low, I2_high, B), B);
    // std::vector<std::string> z2 = KARATSUBA_ALGORITHM(I1_high, I2_high, B);

    // // Combine the results using grade-school subtraction and addition
    // std::vector<std::string> r1 = GRADE_SCHOOL_INTEGER_SUBTRACTION(z1, z0, B);
    // std::vector<std::string> r2 = GRADE_SCHOOL_INTEGER_SUBTRACTION(r1, z2, B);
    // std::vector<std::string> result = GRADE_SCHOOL_INTEGER_ADDITION(z2, r2, B);
    // result = GRADE_SCHOOL_INTEGER_ADDITION(result, z0, B);

    // return result;
    return {};
}

void get_input(std::string& I1, std::string& I2, std::string& B) {
    std::string input_line;
    
    // Prompt the user for input
    // std::cout << "Enter I1, I2, and B (separated by spaces): ";
    std::getline(std::cin, input_line);
    
    // Use a stringstream to parse the input
    std::stringstream ss(input_line);
    
    // Read I1 and I2 as strings, and B as an integer
    ss >> I1 >> I2 >> B;
    
    // Check if the input was valid (i.e., B is a non-negative integer)
    // if (ss.fail() || B < 0) {
    //     std::cerr << "Invalid input. Please make sure B is a non-negative integer and I1, I2 are valid strings.\n";
    //     std::exit(EXIT_FAILURE);
    // }
}





int main(int argc, char *argv[]){
    std::string pre_I1;
    std::string pre_I2;
    std::string pre_B;
    get_input(pre_I1, pre_I2, pre_B);

    // std::cout << "I1: " << pre_I1 << std::endl
    //           << "I2: " << pre_I2 << std::endl
    //           << "Base: " << pre_B 
    //           << std::endl;
    

    // Extract each digit into a list of integers.
    std::vector<int> I1 = digits_transform_alloc(pre_I1);
    std::vector<int> I2 = digits_transform_alloc(pre_I2);
    int B = stoi(pre_B);

    // int s1 = I1.size();
    // int s2 = I2.size();

    std::vector<std::string> res_addition = GRADE_SCHOOL_INTEGER_ADDITION(I1, I2, B);
    std::vector<std::string> res_multiplication = KARATSUBA_ALGORITHM(I1, I2, B);


    std::string result_add = digits_transform_output(res_addition);
    std::string result_mult = digits_transform_output(res_multiplication);

    std::cout << result_add 
              << " " 
              << "0" 
              << " "
              << "0\n";
    
    return 0;
}
