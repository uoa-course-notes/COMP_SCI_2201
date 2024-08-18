#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

// Transform string to vector of strings
std::vector<std::string> digits_transform_alloc(const std::string& s) {
    std::vector<std::string> result(s.size());
    std::transform(s.begin(), s.end(), result.begin(), [](char ch) { return std::string(1, ch); });
    return result;
}

// Transform vector of strings to string
std::string digits_transform_output(const std::vector<std::string>& s) {
    std::string result = "";
    for (const std::string& elem : s) {
        result += elem;
    }

    // Remove leading zeros
    result = result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));
    return result;
}

// Print function
template <typename T>
void print_digits(const std::vector<T>& result) {
    u_int size = result.size();
    std::cout << "<";
    for (u_int i = 0; i < size; i++) {
        if (i == size - 1) std::cout << result[i];
        else std::cout << result[i] << ",";
    }
    std::cout << ">" << std::endl;
}

// Align two vectors by prepending zeros
void align(std::vector<std::string>& I1, std::vector<std::string>& I2) {
    int s1 = I1.size();
    int s2 = I2.size();

    if (s1 == s2) return;
    else {
        int offset = std::abs(s1 - s2);
        if (s1 > s2) {
            I2.insert(I2.begin(), offset, "0");
        }
        else {
            I1.insert(I1.begin(), offset, "0");
        }
    }
}

// Grade-School Integer Addition
std::vector<std::string> GRADE_SCHOOL_INTEGER_ADDITION(std::vector<std::string> I1, std::vector<std::string> I2, int B) {
    align(I1, I2);
    int carry = 0;
    int s1 = I1.size();
    std::vector<std::string> S(s1);

    for (int i = s1 - 1; i >= 0; i--) {
        int sum = std::stoi(I1[i]) + std::stoi(I2[i]) + carry;
        S[i] = std::to_string(sum % B);
        carry = sum / B;
    }

    if (carry > 0) {
        S.insert(S.begin(), std::to_string(carry)); // Prepend carry if it overflows
    }

    return S;
}

// Karatsuba Algorithm for Integer Multiplication
std::vector<std::string> KARATSUBA_ALGORITHM(std::vector<std::string> I1, std::vector<std::string> I2, int B) {
    align(I1, I2);
    int n = I1.size();
    if (n <= 4) {  // Base case: Use grade-school multiplication for small numbers
        std::vector<std::string> result(n * 2, "0");
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int prod = std::stoi(I1[i]) * std::stoi(I2[j]) + std::stoi(result[i + j + 1]);
                result[i + j + 1] = std::to_string(prod % B);
                result[i + j] = std::to_string(std::stoi(result[i + j]) + prod / B);
            }
        }
        // Remove leading zeros
        while (result.size() > 1 && result[0] == "0") {
            result.erase(result.begin());
        }
        return result;
    }

    int mid = n / 2;

    // Split I1 and I2 into two halves
    std::vector<std::string> I1_low(I1.begin() + mid, I1.end());
    std::vector<std::string> I1_high(I1.begin(), I1.begin() + mid);
    std::vector<std::string> I2_low(I2.begin() + mid, I2.end());
    std::vector<std::string> I2_high(I2.begin(), I2.begin() + mid);

    // Recursively calculate the three products
    std::vector<std::string> z0 = KARATSUBA_ALGORITHM(I1_low, I2_low, B);
    std::vector<std::string> z1 = KARATSUBA_ALGORITHM(GRADE_SCHOOL_INTEGER_ADDITION(I1_low, I1_high, B),
                                                      GRADE_SCHOOL_INTEGER_ADDITION(I2_low, I2_high, B), B);
    std::vector<std::string> z2 = KARATSUBA_ALGORITHM(I1_high, I2_high, B);

    // Combine the results using grade-school subtraction and addition
    // Modify subtraction to handle strings
    std::vector<std::string> r1 = GRADE_SCHOOL_INTEGER_ADDITION(z1, z0, B);  // Subtract z0 from z1
    std::vector<std::string> r2 = GRADE_SCHOOL_INTEGER_ADDITION(r1, z2, B);  // Subtract z2 from result of previous step
    std::vector<std::string> result_high = z2;
    result_high.insert(result_high.end(), n, "0");  // Equivalent to multiplying by B^n
    std::vector<std::string> result_mid = r2;
    result_mid.insert(result_mid.end(), mid, "0");  // Equivalent to multiplying by B^(n/2)

    std::vector<std::string> result = GRADE_SCHOOL_INTEGER_ADDITION(result_high, result_mid, B);
    result = GRADE_SCHOOL_INTEGER_ADDITION(result, z0, B);

    return result;
}

// Integer Division with Rounding Down
std::vector<std::string> INTEGER_DIVISION(std::vector<std::string> dividend, std::vector<std::string> divisor, int B) {
    std::vector<std::string> quotient;
    std::vector<std::string> remainder = dividend;

    int index = 0;
    while (index <= dividend.size() - divisor.size()) {
        std::vector<std::string> temp(divisor.size() + index, "0");
        std::copy(divisor.begin(), divisor.end(), temp.begin() + index);

        // Subtract while remainder is greater or equal to the divisor
        while (GRADE_SCHOOL_INTEGER_ADDITION(remainder, temp, B).size() > 0) {
            remainder = GRADE_SCHOOL_INTEGER_ADDITION(remainder, temp, B);  // Subtract temp from remainder
            if (quotient.size() <= index) {
                quotient.push_back("1");
            } else {
                quotient[index] = std::to_string(std::stoi(quotient[index]) + 1);
            }
        }
        index++;
    }

    // Remove leading zeros from quotient
    while (quotient.size() > 1 && quotient[0] == "0") {
        quotient.erase(quotient.begin());
    }

    return quotient;
}

int main(int argc, char* argv[]) {
    std::string pre_I1 = argv[1];
    std::string pre_I2 = argv[2];
    std::string pre_B = argv[3];

    std::vector<std::string> I1 = digits_transform_alloc(pre_I1);
    std::vector<std::string> I2 = digits_transform_alloc(pre_I2);
    std::vector<std::string> B_vec = digits_transform_alloc(pre_B);

    int B = std::stoi(B_vec[0]);

    std::vector<std::string> res_addition = GRADE_SCHOOL_INTEGER_ADDITION(I1, I2, B);
    std::vector<std::string> res_multiplication = KARATSUBA_ALGORITHM(I1, I2, B);
    // std::vector<std::string> res_division = INTEGER_DIVISION(I1, I2, B);

    std::string Addition = digits_transform_output(res_addition);
    std::string Karatsuba_Multiplication = digits_transform_output(res_multiplication);
    // std::string Division = digits_transform_output(res_division);

    std::cout << Addition 
              << " "
              << Karatsuba_Multiplication
              << " "
              << "0";
    
    // std::cout << Division << std::endl;
    
    return 0;
}
