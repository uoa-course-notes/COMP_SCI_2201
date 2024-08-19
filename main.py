import sys

def digits_transform_alloc(s):
    return [int(ch) for ch in s]

def digits_transform_output(v):
    result = ''.join(map(str, v))
    return result.lstrip('0') or '0'

def get_input():
    # Prompt the user to enter three integers separated by spaces
    # user_input = input("Enter three non-negative integers (I1 I2 B), separated by spaces: ")
    user_input = input()
    # Split the input string into three parts
    I1_str, I2_str, B_str = user_input.split()
    
    # Convert the strings to integers
    I1 = int(I1_str)
    I2 = int(I2_str)
    B = int(B_str)
    
    return I1, I2, B


def align(I1, I2):
    len_diff = len(I1) - len(I2)
    if len_diff > 0:
        I2 = [0] * len_diff + I2
    elif len_diff < 0:
        I1 = [0] * (-len_diff) + I1
    return I1, I2

def GRADE_SCHOOL_INTEGER_ADDITION(I1, I2, B):
    I1, I2 = align(I1, I2)
    carry = 0
    S = []

    for i in range(len(I1) - 1, -1, -1):
        total = I1[i] + I2[i] + carry
        S.append(total % B)
        carry = total // B

    if carry > 0:
        S.append(carry)

    return S[::-1]

def GRADE_SCHOOL_INTEGER_SUBTRACTION(I1, I2, B):
    I1, I2 = align(I1, I2)
    S = []

    for i in range(len(I1) - 1, -1, -1):
        diff = I1[i] - I2[i]
        if diff < 0:
            I1[i - 1] -= 1
            diff += B
        S.append(diff)

    return S[::-1]

def KARATSUBA_ALGORITHM(I1, I2, B):
    I1, I2 = align(I1, I2)
    n = len(I1)
    if n == 1:  # Base case
        return GRADE_SCHOOL_INTEGER_ADDITION([I1[0] * I2[0]], [], B)

    mid = n // 2

    # Split digits
    I1_low = I1[mid:]
    I1_high = I1[:mid]
    I2_low = I2[mid:]
    I2_high = I2[:mid]

    # Recursive calls
    z0 = KARATSUBA_ALGORITHM(I1_low, I2_low, B)
    z1 = KARATSUBA_ALGORITHM(GRADE_SCHOOL_INTEGER_ADDITION(I1_low, I1_high, B),
                             GRADE_SCHOOL_INTEGER_ADDITION(I2_low, I2_high, B), B)
    z2 = KARATSUBA_ALGORITHM(I1_high, I2_high, B)

    # Combine results
    result_high = z2 + [0] * (2 * mid)
    result_mid = GRADE_SCHOOL_INTEGER_SUBTRACTION(
        GRADE_SCHOOL_INTEGER_SUBTRACTION(z1, z0, B), z2, B) + [0] * mid

    result = GRADE_SCHOOL_INTEGER_ADDITION(
        GRADE_SCHOOL_INTEGER_ADDITION(result_high, result_mid, B), z0, B)

    return result



def DIVISION_ALGORITHM(I1, I2, B):
    quotient = []
    remainder = 0
    I2_value = int(''.join(map(str, I2)))  # Convert I2 to a single integer

    for digit in I1:
        remainder = remainder * B + digit
        quotient_digit = remainder // I2_value
        quotient.append(quotient_digit)
        remainder -= quotient_digit * I2_value

    # Trim leading zeros from quotient
    while len(quotient) > 1 and quotient[0] == 0:
        quotient.pop(0)
        
    return quotient


def main():
    # pre_I1 = sys.argv[1]
    # pre_I2 = sys.argv[2]
    # pre_B = sys.argv[3]
    # Get 3 integers from the user 
    pre_I1, pre_I2, pre_B = get_input()

    # Transforms each input into a vector of integers
    I1 = digits_transform_alloc(str(pre_I1))
    I2 = digits_transform_alloc(str(pre_I2))
    B = int(str(pre_B))
    
    # print(f"{I1}, {I2}, {B}")

    addition = GRADE_SCHOOL_INTEGER_ADDITION(I1, I2, B)
    multiplication = KARATSUBA_ALGORITHM(I1, I2, B)
    division = DIVISION_ALGORITHM(I1, I2, B)
    # subtraction = GRADE_SCHOOL_INTEGER_SUBTRACTION(I1, I2, B)
    
    
    add_result = digits_transform_output(addition)
    # sub_result = digits_transform_output(subtraction)
    mult_result = digits_transform_output(multiplication)
    div_result = digits_transform_output(division)
    
    # print(f"Addition: {add_result}")
    # print(f"Subtraction: {sub_result}")
    # print(f"Multiplication: {mult_result}")
    # print("Multiplication:", digits_transform_output(multiplication))
    # print("Division:", digits_transform_output(division))
    print(f"{add_result} {mult_result} {div_result}")
    
    
    
    # print("---------------------------------FULL TEST--------------------------------------------")
    # test_add = 34303100302104324243311110103331002244444311310243102223032232133423342010144440202004040320213 
    # test_mult = 23132020143304230203120440421433140433104433224312424214100403111220004124440112331143134010413414200123334222243310102330 
    # test_div = 103420003131314212110244422124214444340431341001134002033013412440310
    # if (str(test_add) == add_result and 
    #     str(test_mult) == mult_result):
        
    #     print("Hellalujah!")
    # else: 
    #     print("=====================Something is wrong!===================")
if __name__ == "__main__":
    main()
