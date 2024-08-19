#include <iostream>
#include <string>
#include <vector>

extern GRADE_SCHOOL_INTEGE

std::vector<int> convert_to_int_vector(std::vector<std::string>& str_vec) {
    std::vector<int> int_vec;
    for (const auto& str : str_vec) {
        // Assumes each string in str_vec is a single character representing a digit
        int_vec.push_back(str[0] - '0');
    }
    return int_vec;
}

std::vector<std::string> convert_to_string_vector(std::vector<int>& vec){
    std::vector<std::string> str_vec;
    for (const auto & i: vec){
        str_vec.push_back(std::to_string(i));
    }
    return str_vec;
}
// Karatsuba Multiplication
std::vector<std::string> KARATSUBA_ALGORITHM(std::vector<std::string> I1, std::vector<std::string> I2, int B) {
    // std::vector<int> I1 = convert_to_int_vector(str_I1);
    // std::vector<int> I2 = convert_to_int_vector(str_I2);
    align(I1, I2);
    int n = std::min(I1.size(), I2.size());
    if (n == 1) {  // Base case: Use grade-school multiplication for small numbers
        return GRADE_SCHOOL_INTEGER_ADDITION(I1, I2, B);  // Adjust this to the correct multiplication
        // return ;
    }

    int mid = n / 2; // Integer division unless n is not an integer. 

    // // Split I1 into two halves
    std::vector<std::string> I1_low(I1.begin() + mid+1, I1.end());
    std::vector<std::string> I1_high(I1.begin(), I1.begin() + mid);

    // // Split I2 into two halves
    std::vector<std::string> I2_low(I2.begin() + mid+1, I2.end());
    std::vector<std::string> I2_high(I2.begin(), I2.begin() + mid);

    // // Recursively calculate the three products
    std::vector<std::string> p_3 = KARATSUBA_ALGORITHM(I1_high, I2_high, B);
    std::vector<std::string> p_0 = KARATSUBA_ALGORITHM(I1_low, I2_low, B);
    // std::vector<std::string> p_1 = KARATSUBA_ALGORITHM(I1_high, I2_low, B);
    // std::vector<std::string> p_2 = KARATSUBA_ALGORITHM(I1_low,I2_high, B);
    std::vector<std::string> cross_product = KARATSUBA_ALGORITHM(
        GRADE_SCHOOL_INTEGER_ADDITION(I1_low,I1_high, B),
        GRADE_SCHOOL_INTEGER_ADDITION(I2_low, I2_high, B),
        B
    );

    std::vector<std::string> sub1 = GRADE_SCHOOL_INTEGER_SUBTRACTION(cross_product, p_3, B);
    std::vector<std::string> sub2 = GRADE_SCHOOL_INTEGER_SUBTRACTION(sub1, p_0, B);
    // Combine the result of the 3 sub-problems. 
    // return p_3 * pow(B, 2*mid) + sub2 * (pow(B, mid)) + p_0;
  // Combine the results of the three products
    std::vector<std::string> result = GRADE_SCHOOL_INTEGER_ADDITION(
        GRADE_SCHOOL_INTEGER_ADDITION(
            multiply_by_power(p_3, pow(B, 2 * mid)),
            multiply_by_power(sub2, pow(B, mid))
        ),
        p_0
    );

    

    return result;
}

std::vector<std::string> multiply_by_power(std::vector<std::string>& vec, int power, int base){
    int size = vec.size();
    std::vector<int> result(size + power, 0); // Use integer for manipulation

    // Convert input vector from
    std::vector<int> int_vec(size);
    int_vec = convert_to_int_vector(vec);
    // Multiply each vector and place in result vector 
    for (int i=0; i<size; ++i){
        int index = i+ power;
        
    }

}


int main(int arg, char** arg){


}