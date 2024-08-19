#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept> // for std::invalid_argument
#include <cctype>    // for std::isdigit
#include <cmath>

// std::vector<int> digits_transform_alloc(const std::string& s)
// {
//     std::vector<int> result(s.size());
//     std::transform(
//         s.begin(), s.end(),
//         result.begin(), 
//         [](char ch) {return ch - '0';}
//         );
//     return result;
// }
std::vector<std::string> string_to_vector_of_strings(std::string& s) {
    std::vector<std::string> result(s.size());
    std::transform(
        s.begin(), s.end(),
        result.begin(),
        [](char ch) { return std::string(1, ch); } // Convert char to string
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


std::vector<int> convert_to_int_vector(std::vector<std::string>& str_vec) {
    std::vector<int> int_vec;
    for (const auto& str : str_vec) {
        // Assumes each string in str_vec is a single character representing a digit
        int_vec.push_back(str[0] - '0');
    }
    return int_vec;
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
    // std::cout << "Entered align" << std::endl;
    // std::cin.get();
    int s1 = I1.size();
    int s2 = I2.size();

    if (s1 == s2) return;
    else{
        // int max_size = std::max(I1.size(), I2.size());	
        int offset = std::abs(s1 - s2);
        if (s1 > s2){
            // std::cout << "Inserting I2..." << std::endl;
            // std::cin.get();
            // print_digits(I2);
            
            // Prepend zero's to I2
            I2.insert(I2.begin(), offset, 0);            
        }
        else{
            // std::cout << "Inserting I1..." << std::endl;
            // std::cin.get();
            // Prepend zero's to I1
            I1.insert(I1.begin(), offset, 0);            
        }
    }
    // std::cout << "Leaving align" << std::endl;
    // std::cin.get();
}
void align_strings(
    std::vector<std::string>& I1, 
    std::vector<std::string>& I2)
{
    // std::cout << "Entered align" << std::endl;
    // std::cin.get();
    int s1 = I1.size();
    int s2 = I2.size();

    if (s1 == s2) return;
    else{
        // int max_size = std::max(I1.size(), I2.size());	
        int offset = std::abs(s1 - s2);
        if (s1 > s2){
            // std::cout << "Inserting I2..." << std::endl;
            // std::cin.get();
            // print_digits(I2);
            
            // Prepend zero's to I2
            I2.insert(I2.begin(), offset, "0");            
        }
        else{
            // std::cout << "Inserting I1..." << std::endl;
            // std::cin.get();
            // Prepend zero's to I1
            I1.insert(I1.begin(), offset, "0");            
        }
    }
    // std::cout << "Leaving align" << std::endl;
    // std::cin.get();
}
// Working with base 2
// std::vector<std::string> GRADE_SCHOOL_INTEGER_ADDITION(std::vector<std::string> str_I1, std::vector<std::string> str_I2, int B){
//     std::vector<int> I1 = convert_to_int_vector(str_I1);
//     std::vector<int> I2 = convert_to_int_vector(str_I2);
//     align(I1, I2);

// //   if (B < 2 && B > 9) return {"-1"};
//   std::map<int, std::string> hex_map = {
//     {10,"A"},
//     {11,"B"},
//     {12,"C"},
//     {13,"D"},
//     {14,"E"},
//     {15,"F"}  
//     };
//   int c = 0;
//   // Now I1 and I2 must be of the same size
//   int s1 = I1.size();
// //   int s2 = I2.size();
//   // vector of sums 
//     std::vector<std::string> S(s1);
  
  
//   for (int i = s1-1; i>= 0; i--){ // BEGIN 
//     if (I1[i] + I2[i] + c >= B){
//         S[i] = std::to_string((I1[i] + I2[i] + c) % B);
//         // Convert to appropriate character (for higher bases)
//         std::map<int, std::string>::iterator it = hex_map.find(stoi(S[i]));        
//         if (it != hex_map.end()){
//             S[i] = it->second;
//         }
//         // std::cout << "S[i] = " << S[i] << std::endl;
//         // std::cout << "In 1st if -- Enter:" << std::endl;
//         // std::cin.get();
//         c = 1;
  
//     }
//     else{ // I1[i] + I2[i] + c < B
//         S[i] = std::to_string(I1[i] + I2[i] + c);
//         //
//         std::map<int, std::string>::iterator it = hex_map.find(stoi(S[i]));        
//         if (it != hex_map.end()){
//             S[i] = it->second;
//         }
//         c = 0;
//         // std::cout << "In 2nd if -- Enter:" << std::endl;
//         // std::cin.get();
//     }
//   } // END 

//   return S;
// }
std::vector<std::string> GRADE_SCHOOL_INTEGER_ADDITION(
    std::vector<std::string> str_I1, 
    std::vector<std::string> str_I2, 
    int B) 
{
    std::vector<int> I1 = convert_to_int_vector(str_I1);
    std::vector<int> I2 = convert_to_int_vector(str_I2);
    align(I1, I2);

    std::map<int, std::string> hex_map = {
        {10, "A"},
        {11, "B"},
        {12, "C"},
        {13, "D"},
        {14, "E"},
        {15, "F"}
    };

    int carry = 0;
    int s1 = I1.size();
    std::vector<std::string> S(s1);

    for (int i = s1 - 1; i >= 0; i--) {  // BEGIN
        int sum = I1[i] + I2[i] + carry;

        // Handle the carry and the sum modulo B
        if (sum >= B) {
            carry = 1;
            sum = sum % B;
        } else {
            carry = 0;
        }

        // Convert sum to the appropriate string representation
        if (sum >= 10) {
            S[i] = hex_map[sum];
        } else {
            S[i] = std::to_string(sum);
        }
    }  // END

    // Handle any remaining carry
    if (carry > 0) {
        S.insert(S.begin(), "1");
    }

    return S;
}


std::vector<std::string> GRADE_SCHOOL_INTEGER_SUBTRACTION(std::vector<std::string> str_I1, std::vector<std::string> str_I2, int B){
//   std::cout << "Entered Subtraction" << std::endl;
//   std::cin.get();
  std::vector<int> I1 = convert_to_int_vector(str_I1);
  std::vector<int> I2 = convert_to_int_vector(str_I2);
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
            // std::cout << "I1[i] < I2[i]" << std::endl;
            // std::cin.get();
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
            // std::cout << "I1[i] >= I2[i]" << std::endl;
            // std::cin.get();
            S[i] = std::to_string(I1[i] - I2[i]);
            std::map<int, std::string>::iterator it = hex_map.find(stoi(S[i]));        
            if (it != hex_map.end()){
                S[i] = it->second;
            }
        }
    }
    // std::cout << "Leaving subtraction" << std::endl;
    // std::cin.get();
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

std::vector<std::string> NAIVE_RECURSIVE_MULTIPLICATION(std::vector<std::string> I1, std::vector<std::string> I2, int B) {
    int n1 = I1.size();
    int n2 = I2.size();

    // Base case: if either number is 0
    if (n1 == 0 || n2 == 0) {
        return {"0"};
    }

    // Result vector to store the product of two numbers
    std::vector<int> result(n1 + n2, 0);

    // Multiply each digit of I1 by each digit of I2
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int product = std::stoi(I1[i]) * std::stoi(I2[j]);
            int temp_sum = result[i + j + 1] + product;

            result[i + j + 1] = temp_sum % B;
            result[i + j] += temp_sum / B;
        }
    }

    // Convert result vector of integers to vector of strings, skipping leading zeros
    std::vector<std::string> result_str;
    bool leading_zero = true;
    for (int num : result) {
        if (num == 0 && leading_zero) {
            continue;
        }
        leading_zero = false;
        result_str.push_back(std::to_string(num));
    }

    return result_str.empty() ? std::vector<std::string>{"0"} : result_str;
}





// Karatsuba Multiplication
// std::vector<std::string> KARATSUBA_ALGORITHM(std::vector<std::string> I1, std::vector<std::string> I2, int B) {
//     // std::vector<int> I1 = convert_to_int_vector(str_I1);
//     // std::vector<int> I2 = convert_to_int_vector(str_I2);
//     align_strings(I1, I2);
//     //Now n1 and n2 should have ths same size 
//     int n1 = I1.size(); 
//     int n2 = I2.size();
//     // Technically, only one of them is needed
//     // if (n1 == 0) {
//     //     std::cout << "Someone is 0" << std::endl;
//     //     std::cin.get();
        
//     //     return {"0"};
//     // }
//     if (n1 <= 4 || n2 <= 4) {  // Base case: Use grade-school multiplication for small numbers
//         // std::cout << "Base case entered" << std::endl;
//         // std::cin.get();
//         return NAIVE_RECURSIVE_MULTIPLICATION(I1, I2, B);  // Adjust this to the correct multiplication
//         // return ;
//     }
//     int mid = n1 / 2; // Integer division unless n is not an integer. 

//     // // Split I1 into two halves
//     std::vector<std::string> I1_low(I1.begin() + mid+1, I1.end());
//     std::vector<std::string> I1_high(I1.begin(), I1.begin() + mid+1);

//     // // Split I2 into two halves
//     std::vector<std::string> I2_low(I2.begin() + mid+1, I2.end());
//     std::vector<std::string> I2_high(I2.begin(), I2.begin() + mid+1);
//     std::cout << "Finished splitting" << std::endl;
//     std::cout << "I1_low = "; print_digits(I1_low);
//     std::cout << "I1_high = ";print_digits(I1_high);
//     std::cout << "I2_low = "; print_digits(I2_low);
//     std::cout << "I2_high = ";print_digits(I2_high);
//     std::cin.get();

//     // // Recursively calculate the three products
//     std::vector<std::string> p_3 = KARATSUBA_ALGORITHM(I1_high, I2_high, B);
//     std::vector<std::string> p_0 = KARATSUBA_ALGORITHM(I1_low, I2_low, B);
//     // std::vector<std::string> p_1 = KARATSUBA_ALGORITHM(I1_high, I2_low, B);
//     // std::vector<std::string> p_2 = KARATSUBA_ALGORITHM(I1_low,I2_high, B);
//     // std::cout << "Finished computing p_3 and p_0" << std::endl;
//     // std::cin.get();
//     // std::cout << "p3 = ";
//     // print_digits(p_3);
//     // std::cout << "p0 = ";
//     // print_digits(p_0);

//     std::vector<std::string> a_b = GRADE_SCHOOL_INTEGER_ADDITION(I1_low, I1_high, B);
//     std::vector<std::string> c_d = GRADE_SCHOOL_INTEGER_ADDITION(I2_low, I2_high, B);
//     // std::cout << "-------------cross------------" << std::endl;
//     // print_digits(a_b);
//     // print_digits(c_d);
//     // std::cin.get();
    
//     std::vector<std::string> cross_product = KARATSUBA_ALGORITHM(
//         a_b, c_d,B
// );

//     // std::cout << "Finished cross_product: ";
//     // print_digits(cross_product);
//     // std::cout << " Entering subtraction." << std::endl;
//     // std::cin.get();

//     std::vector<std::string> sub1 = GRADE_SCHOOL_INTEGER_SUBTRACTION(cross_product, p_3, B);
//     // std::cout << "Finished sub1" << std::endl;
//     // std::cin.get();
//     // print_digits(sub1);

//     std::vector<std::string> sub2 = GRADE_SCHOOL_INTEGER_SUBTRACTION(sub1, p_0, B);
//     // std::cout << "Finished sub2" << std::endl;
//     // print_digits(sub2);
//     // std::cin.get();
    
//     // Combine the result of the 3 sub-problems. 
//     // return p_3 * pow(B, 2*mid) + sub2 * (pow(B, mid)) + p_0;
//   // Combine the results of the three products
//     // std::cout << "Combining" << std::endl;
//     // std::cin.get();
//     std::vector<std::string> power1 = {std::to_string(int(pow(10, 2*mid)))};
//     std::vector<std::string> power2 = {std::to_string(int(pow(10, mid)))};
//     std::vector<std::string> op2 = NAIVE_RECURSIVE_MULTIPLICATION(cross_product, power2, B);
//     std::vector<std::string> op3 = GRADE_SCHOOL_INTEGER_ADDITION(op2,p_0, B);
//     std::vector<std::string> result = 
//         GRADE_SCHOOL_INTEGER_ADDITION(
//         NAIVE_RECURSIVE_MULTIPLICATION(p_3, power1, B),
//         op3, B);
//     return result;    
// }

std::vector<std::string> KARATSUBA_ALGORITHM(std::vector<std::string> I1, std::vector<std::string> I2, int B) {
    align_strings(I1, I2);

    int n1 = I1.size();
    int n2 = I2.size();

    if (n1 <= 4 || n2 <= 4) {
        return NAIVE_RECURSIVE_MULTIPLICATION(I1, I2, B);
    }

    int mid = n1 / 2;

    std::vector<std::string> I1_low(I1.begin() + mid, I1.end());
    std::vector<std::string> I1_high(I1.begin(), I1.begin() + mid);

    std::vector<std::string> I2_low(I2.begin() + mid, I2.end());
    std::vector<std::string> I2_high(I2.begin(), I2.begin() + mid);

    std::vector<std::string> z0 = KARATSUBA_ALGORITHM(I1_low, I2_low, B);
    std::vector<std::string> z2 = KARATSUBA_ALGORITHM(I1_high, I2_high, B);

    std::vector<std::string> I1_sum = GRADE_SCHOOL_INTEGER_ADDITION(I1_low, I1_high, B);
    std::vector<std::string> I2_sum = GRADE_SCHOOL_INTEGER_ADDITION(I2_low, I2_high, B);

    std::vector<std::string> z1 = KARATSUBA_ALGORITHM(I1_sum, I2_sum, B);
    z1 = GRADE_SCHOOL_INTEGER_SUBTRACTION(z1, z0, B);
    z1 = GRADE_SCHOOL_INTEGER_SUBTRACTION(z1, z2, B);

    // Combine the results with appropriate shifts
    for (int i = 0; i < 2 * (n1 - mid); i++) {
        z2.push_back("0");
    }

    for (int i = 0; i < n1 - mid; i++) {
        z1.push_back("0");
    }

    std::vector<std::string> result = GRADE_SCHOOL_INTEGER_ADDITION(z2, z1, B);
    result = GRADE_SCHOOL_INTEGER_ADDITION(result, z0, B);

    return result;
}

// Helper function to multiply a vector of strings by a power of the base



void get_input(std::string& I1, std::string& I2, std::string& B) {
    std::string input_line;
    
    // Prompt the user for input
    // std::cout << "Enter I1, I2, and B (separated by spaces): ";
    std::getline(std::cin, input_line);
    
    // Use a stringstream to parse the input
    std::stringstream ss(input_line);
    
    // Read I1 and I2 as strings, and B as an integer
    ss >> I1 >> I2 >> B;
}





int main(int argc, char *argv[]){
    std::string pre_I1;
    std::string pre_I2;
    std::string pre_B ;

    // std::cout << "I1: " << pre_I1 << std::endl
    //           << "I2: " << pre_I2 << std::endl
    //           << "Base: " << pre_B 
    //           << std::endl;
    // Gettting user input using I/O device instead of taking input from the command line
    // Assignment description: very substamdard, to say the least (:
    get_input(pre_I1, pre_I2, pre_B);
    

    // Extract each digit into a list of integers.
    std::vector<std::string> I1 = string_to_vector_of_strings(pre_I1);
    std::vector<std::string> I2 = string_to_vector_of_strings(pre_I2);
    int B = stoi(pre_B);

    // std::vector<std::string> res_addition = {"0", "1", "0"};
    std::vector<std::string> res_addition = GRADE_SCHOOL_INTEGER_ADDITION(I1, I2, B);
    std::vector<std::string> res_multiplication = KARATSUBA_ALGORITHM(I1, I2, B);
    // std::vector<std::string> res_multiplication = NAIVE_RECURSIVE_MULTIPLICATION(I1, I2, B);

    std::string result_add = digits_transform_output(res_addition);
    std::string result_mult = digits_transform_output(res_multiplication);
    // std::cout << result_add << std::endl;
    
    std::cout << result_add 
              << " " 
              << result_mult 
              << " "
              << "0\n";
    
    return 0;
}
