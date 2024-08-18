#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// Solving the problem of digit allocation 
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



// ----------------------------------------------------------------
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


// Solving the problem of alignment 
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




// Integer Subtraction 
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




// Karatsuba Algorithm for Integer Multiplication
// std::vector<int> KARATSUBA_ALGORITHM(std::vector<int> I1, std::vector<int> I2, int B) {
//     align(I1, I2);
//     int n = I1.size();
//     if (n <= 4) {  // Base case: Use grade-school multiplication for small numbers
//         // Implement the grade-school multiplication here
//         std::vector<int> result(n * 2, 0);
//         for (int i = n - 1; i >= 0; --i) {
//             for (int j = n - 1; j >= 0; --j) {
//                 int prod = I1[i] * I2[j] + result[i + j + 1];
//                 result[i + j + 1] = prod % B;
//                 result[i + j] += prod / B;
//             }
//         }
//         // Remove leading zeros
//         while (result.size() > 1 && result[0] == 0) {
//             result.erase(result.begin());
//         }
//         return result;
//     }

//     int mid = n / 2;

//     // Split I1 and I2 into two halves
//     std::vector<int> I1_low(I1.begin() + mid, I1.end());
//     std::vector<int> I1_high(I1.begin(), I1.begin() + mid);
//     std::vector<int> I2_low(I2.begin() + mid, I2.end());
//     std::vector<int> I2_high(I2.begin(), I2.begin() + mid);

//     // Recursively calculate the three products
//     std::vector<int> z0 = KARATSUBA_ALGORITHM(I1_low, I2_low, B);
//     std::vector<int> z1 = KARATSUBA_ALGORITHM(GRADE_SCHOOL_INTEGER_ADDITION(I1_low, I1_high, B),
//                                               GRADE_SCHOOL_INTEGER_ADDITION(I2_low, I2_high, B), B);
//     std::vector<int> z2 = KARATSUBA_ALGORITHM(I1_high, I2_high, B);

//     // Combine the results using grade-school subtraction and addition
//     std::vector<int> r1 = GRADE_SCHOOL_INTEGER_SUBTRACTION(z1, z0, B);
//     std::vector<int> r2 = GRADE_SCHOOL_INTEGER_SUBTRACTION(r1, z2, B);
//     std::vector<int> result_high = z2;
//     result_high.insert(result_high.end(), n, 0);  // Equivalent to multiplying by B^n
//     std::vector<int> result_mid = r2;
//     result_mid.insert(result_mid.end(), mid, 0);  // Equivalent to multiplying by B^(n/2)
    
//     std::vector<int> result = GRADE_SCHOOL_INTEGER_ADDITION(result_high, result_mid, B);
//     result = GRADE_SCHOOL_INTEGER_ADDITION(result, z0, B);

//     return result;
// }


// Integer Division with Rounding Down (Post-graduate only)
// std::vector<int> INTEGER_DIVISION(std::vector<int> dividend, std::vector<int> divisor, int B) {
//     std::vector<int> quotient;
//     std::vector<int> remainder(dividend.size(), 0);

//     for (int i = 0; i < dividend.size(); i++) {
//         remainder[i] = dividend[i];
//     }

//     int index = 0;
//     while (index <= dividend.size() - divisor.size()) {
//         std::vector<int> temp(divisor.size() + index, 0);
//         std::copy(divisor.begin(), divisor.end(), temp.begin() + index);
//         while (GRADE_SCHOOL_INTEGER_SUBTRACTION(remainder, temp, B).size() > 0) {
//             remainder = GRADE_SCHOOL_INTEGER_SUBTRACTION(remainder, temp, B);
//             if (quotient.size() <= index) {
//                 quotient.push_back(1);
//             } else {
//                 quotient[index]++;
//             }
//         }
//         index++;
//     }

//     // Remove leading zeros from quotient
//     while (quotient.size() > 1 && quotient[0] == 0) {
//         quotient.erase(quotient.begin());
//     }

//     return quotient;
// }


int main(int argc, char* argv[]){

    // Declare and initialize the variables extracted from the command-line argument  
    std::string pre_I1 = argv[1];
    std::string pre_I2 = argv[2];
    std::string pre_B = argv[3];


    // Extract each digit into a list of integers.
    std::vector<int> I1 = digits_transform_alloc(pre_I1);
    std::vector<int> I2 = digits_transform_alloc(pre_I2);
    std::vector<int> B_vec = digits_transform_alloc(pre_B);

    int B = B_vec[0];

    
  
    std::vector<std::string> res_addition = GRADE_SCHOOL_INTEGER_ADDITION(I1, I2, B);
    // std::vector<std::string> res_multiplication = KARATSUBA_ALGORITHM(I1, I2, B);
    // std::vector<int> res_division = INTEGER_DIVISION(I1, I2, B);
    
    std::string Addition = digits_transform_output(res_addition);
    // std::string Multiplication = digits_transform_output(res_multiplication);
    // std::string Division = digits_transform_output(res_division);
    std::cout << Addition
              << " "
              << "0"
              << " "
              << "0";
    

  return 0;
}
