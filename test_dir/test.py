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


def GRADE_SCHOOL_INTEGER_ADDITION_V2(num1, num2, B):
    """Perform addition of two integers in base B."""
    # Convert numbers to lists of digits
    I1 = [int(digit) for digit in str(num1)]
    I2 = [int(digit) for digit in str(num2)]
    
    I1, I2 = align(I1, I2)
    carry = 0
    S = []

    for i in range(len(I1) - 1, -1, -1):
        total = I1[i] + I2[i] + carry
        S.append(total % B)
        carry = total // B

    if carry > 0:
        S.append(carry)

    # Convert the result list back to an integer
    return int(''.join(map(str, S[::-1])))



# def GRADE_SCHOOL_INTEGER_SUBTRACTION(I1, I2, B):
#     I1, I2 = align(I1, I2)
#     S = []

#     for i in range(len(I1) - 1, -1, -1):
#         diff = I1[i] - I2[i]
#         if diff < 0:
#             I1[i - 1] -= 1
#             diff += B
#         S.append(diff)

#     return S[::-1]


def GRADE_SCHOOL_INTEGER_SUBTRACTION(num1, num2, B):
    """Perform subtraction of two integers in base B."""
    # Convert numbers to lists of digits
    I1 = [int(digit) for digit in str(num1)]
    I2 = [int(digit) for digit in str(num2)]
    
    I1, I2 = align(I1, I2)
    S = []

    for i in range(len(I1) - 1, -1, -1):
        diff = I1[i] - I2[i]
        if diff < 0:
            I1[i - 1] -= 1
            diff += B
        S.append(diff)

    # Convert the result list back to an integer
    return int(''.join(map(str, S[::-1])))



def KARATSUBA_ALGORITHM(I1, I2, B):
    pass 


def vector_to_integer(vector, B):
    """Convert a vector of strings representing digits to a single integer."""
    # Join the vector into a single string
    number_str = ''.join(map(str, vector))
    
    # Convert the string to an integer with base B
    number = int(number_str, B)
    
    return number



# def karatsuba(I1, I2, B):
    # One-digit multiplication (primitive multiplication)
    if I1 < B or I2 < B:
        return I1*I2
    else:
        n = max(len(str(I1)), len(str(I2)))
        half = n//2
        a = I1 // (10 ** (half))
        b = I1 % (10 ** (half))
        c = I2 // (10 ** (half))
        d = I2 % (10 ** (half))
        
        ac = karatsuba(a, c)
        bd = karatsuba(b, d)
        
        ad_plus_bc = karatsuba(a+b, c+d) - ac - bd
        return ac * (B ** (2*half)) + (ad_plus_bc * (B ** half)) + bd


def karatsuba(I1, I2, B):
    """Karatsuba multiplication algorithm for integers in base B."""
    # Base case: perform simple multiplication for single-digit numbers
    if I1 < B and I2 < B:
        return I1 * I2
    
    # Convert numbers to strings to find length
    n = max(len(str(I1)), len(str(I2)))
    half = n // 2
    
    # Split the numbers into high and low parts
    power = B ** half
    a, b = divmod(I1, power)
    c, d = divmod(I2, power)
    
    # Recursive Karatsuba steps
    ac = karatsuba(a, c, B)
    bd = karatsuba(b, d, B)
    ad_plus_bc = GRADE_SCHOOL_INTEGER_ADDITION(
        karatsuba(a, d, B), 
        karatsuba(b, c, B), 
        B
    )
    ad_plus_bc = GRADE_SCHOOL_INTEGER_SUBTRACTION(ad_plus_bc, GRADE_SCHOOL_INTEGER_ADDITION(ac, bd, B), B)
    
    # Combine results
    return (
        ac * (B ** (2 * half)) + 
        ad_plus_bc * (B ** half) + 
        bd
    )




def main():  
    pre_I1, pre_I2, pre_B = get_input()

    # pre_I1, pre_I2, pre_B = 11000100100001001111000001010110110110010101100101110101100001111010110000,10000000, 2
    
    # Transforms each input into a vector of integers
   
    
    # add_v2 = str(GRADE_SCHOOL_INTEGER_ADDITION_V2(pre_I1, pre_I2, pre_B))
    
 
    
    x = 3334300043033101334143431111201144131211432223120140132003144311032434400244 == 3334300043033101334143431111201144131211432223120140132003144311032434400244
    
    multiplication = karatsuba(pre_I1, pre_I2, pre_B)
    # mult_result = digits_transform_output(multiplication)
 
    print(f"Multiplication: {multiplication}")


    print("---------------------------------FULL TEST--------------------------------------------")
    # test_add = 34303100302104324243311110103331002244444311310243102223032232133423342010144440202004040320213 
    # test_div = 103420003131314212110244422124214444340431341001134002033013412440310
    
    # test_mult = mult_result
    # expected_mult = 110001001000010011110000010101101101100101011001011101011000011110101100000000000
    # if (test_mult != expected_mult):
    #     print(f"Got {mult_result}")
    #     print(f"Expected {expected_mult}")
   
    # if (str(test_add) == add_result and 
    #     str(test_mult) == mult_result):
        
    #     print("Hellalujah!")
    # else: 
    #     print("=====================Something is wrong!===================")
if __name__ == "__main__":
    main()