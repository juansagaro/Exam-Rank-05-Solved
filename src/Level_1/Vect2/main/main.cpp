#include "../given/vect2.hpp"

int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "[1] CONSTRUCTORS AND BASIC PRINTING" << std::endl;
    std::cout << "========================================" << std::endl;
    vect2 v1;
    vect2 v2(1, 2);
    const vect2 v3(v2);
    vect2 v4 = v2;

    std::cout << "v1 (default)  : " << v1 << " \t\t[Expected: {0, 0}]" << std::endl;
    std::cout << "v1 (using []) : {" << v1[0] << ", " << v1[1] << "}" << std::endl;
    std::cout << "v2 (param)    : " << v2 << " \t\t[Expected: {1, 2}]" << std::endl;
    std::cout << "v3 (copy)     : " << v3 << " \t\t[Expected: {1, 2}]" << std::endl;
    std::cout << "v4 (assign)   : " << v4 << " \t\t[Expected: {1, 2}]" << std::endl;

    std::cout << "\n========================================" << std::endl;
    std::cout << "[2] INCREMENT AND DECREMENT OPERATORS" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "v4++ (post)   : " << v4++ << " \t\t[Expected: {1, 2}]" << std::endl;
    std::cout << "++v4 (pre)    : " << ++v4 << " \t\t[Expected: {3, 4}]" << std::endl;
    std::cout << "v4-- (post)   : " << v4-- << " \t\t[Expected: {3, 4}]" << std::endl;
    std::cout << "--v4 (pre)    : " << --v4 << " \t\t[Expected: {1, 2}]" << std::endl;

    std::cout << "\n========================================" << std::endl;
    std::cout << "[3] COMPOUND ASSIGNMENTS (+=, -=, *=)" << std::endl;
    std::cout << "========================================" << std::endl;
    v2 += v3;
    std::cout << "v2 += v3      : " << v2 << " \t\t[Expected: {2, 4}]" << std::endl;
    
    v1 -= v2;
    std::cout << "v1 -= v2      : " << v1 << " \t[Expected: {-2, -4}]" << std::endl;

    std::cout << "\n========================================" << std::endl;
    std::cout << "[4] ARITHMETIC OPERATORS (+, -, *)" << std::endl;
    std::cout << "========================================" << std::endl;
    v2 = v3 + v3 * 2;
    std::cout << "v3 + v3 * 2   : " << v2 << " \t\t[Expected: {3, 6}]" << std::endl;
    
    v2 = 3 * v2;
    std::cout << "3 * v2        : " << v2 << " \t[Expected: {9, 18}]" << std::endl;
    
    v2 += v2 += v3;
    std::cout << "v2 += v2 += v3: " << v2 << " \t[Expected: {20, 40}]" << std::endl;
    
    v1 *= 42;
    std::cout << "v1 *= 42      : " << v1 << " \t[Expected: {-84, -168}]" << std::endl;
    
    v1 = v1 - v1 + v1;
    std::cout << "v1 - v1 + v1  : " << v1 << " \t[Expected: {-84, -168}]" << std::endl;

    std::cout << "\n========================================" << std::endl;
    std::cout << "[5] UNARY MINUS & ARRAY SUBSCRIPT ([])" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "-v2           : " << -v2 << " \t[Expected: {-20, -40}]" << std::endl;
    std::cout << "v1[1] (read)  : " << v1[1] << " \t\t[Expected: -168]" << std::endl;
    
    v1[1] = 12;
    std::cout << "v1[1] = 12    : " << v1[1] << " \t\t[Expected: 12]" << std::endl;
    std::cout << "v1 updated    : " << v1 << " \t[Expected: {-84, 12}]" << std::endl;
    std::cout << "v3[1] (const) : " << v3[1] << " \t\t[Expected: 2]" << std::endl;

    std::cout << "\n========================================" << std::endl;
    std::cout << "[6] COMPARISON OPERATORS (==, !=)" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "v1 == v3      : " << (v1 == v3) << " \t\t[Expected: 0]" << std::endl;
    std::cout << "v1 == v1      : " << (v1 == v1) << " \t\t[Expected: 1]" << std::endl;
    std::cout << "v1 != v3      : " << (v1 != v3) << " \t\t[Expected: 1]" << std::endl;
    std::cout << "v1 != v1      : " << (v1 != v1) << " \t\t[Expected: 0]" << std::endl;

    std::cout << "\n========================================" << std::endl;
    std::cout << "✅ ALL TESTS EXECUTED SUCCESSFULLY" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}
