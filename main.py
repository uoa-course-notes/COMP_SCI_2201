import sys

def digits_transform_alloc(s):
    return [int(ch) for ch in s]

def digits_transform_output(v):
    result = ''.join(map(str, v))
    return result.lstrip('0') or '0'

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
        return [I1[0] * I2[0]]

    mid = n // 2

    I1_low = I1[mid:]
    I1_high = I1[:mid]
    I2_low = I2[mid:]
    I2_high = I2[:mid]

    z0 = KARATSUBA_ALGORITHM(I1_low, I2_low, B)
    z1 = KARATSUBA_ALGORITHM(GRADE_SCHOOL_INTEGER_ADDITION(I1_low, I1_high, B),
                             GRADE_SCHOOL_INTEGER_ADDITION(I2_low, I2_high, B), B)
    z2 = KARATSUBA_ALGORITHM(I1_high, I2_high, B)

    result_high = z2 + [0] * (2 * mid)
    result_mid = GRADE_SCHOOL_INTEGER_SUBTRACTION(
        GRADE_SCHOOL_INTEGER_SUBTRACTION(z1, z0, B), z2, B) + [0] * mid

    result = GRADE_SCHOOL_INTEGER_ADDITION(
        GRADE_SCHOOL_INTEGER_ADDITION(result_high, result_mid, B), z0, B)

    return result

def DIVISION_ALGORITHM(I1, I2, B):
    quotient = []
    remainder = 0

    for digit in I1:
        remainder = remainder * B + digit
        quotient_digit = remainder // int(''.join(map(str, I2)))
        quotient.append(quotient_digit)
        remainder -= quotient_digit * int(''.join(map(str, I2)))

    return quotient

def main():
    # pre_I1 = sys.argv[1]
    # pre_I2 = sys.argv[2]
    # pre_B = sys.argv[3]
    pre_I1 = str(240540143205242311502340531412055204150332)
    pre_I2 = str(2401150215333414545353530050)
    pre_B = str(6)

    I1 = digits_transform_alloc(pre_I1)
    I2 = digits_transform_alloc(pre_I2)
    B = int(pre_B)

    addition = GRADE_SCHOOL_INTEGER_ADDITION(I1, I2, B)
    multiplication = KARATSUBA_ALGORITHM(I1, I2, B)
    division = DIVISION_ALGORITHM(I1, I2, B)
    
    add_result = digits_transform_output(addition)
    mult_result = digits_transform_output(multiplication)
    div_result = digits_transform_output(division)
    # print("Addition:", digits_transform_output(addition))
    # print("Multiplication:", digits_transform_output(multiplication))
    # print("Division:", digits_transform_output(division))
    print(f"{add_result} {mult_result} {div_result}")
    
if __name__ == "__main__":
    main()
