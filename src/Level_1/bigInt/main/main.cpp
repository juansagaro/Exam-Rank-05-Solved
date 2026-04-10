#include "../given/bigInt.hpp"
#include <iostream>

int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "[1] CONSTRUCTORS AND BASIC PRINTING" << std::endl;
    std::cout << "========================================" << std::endl;
    const bigint a(42);
    bigint b(21);
    bigint c;
    bigint d(1337);
    bigint e(d);

    std::cout << "a = " << a << "\t\t[Expected: 42]" << std::endl;
    std::cout << "b = " << b << "\t\t[Expected: 21]" << std::endl;
    std::cout << "c = " << c << "\t\t[Expected: 0]" << std::endl;
    std::cout << "d = " << d << "\t\t[Expected: 1337]" << std::endl;
    std::cout << "e = " << e << "\t\t[Expected: 1337]" << std::endl;

    std::cout << "\n========================================" << std::endl;
    std::cout << "[2] ADDITION OPERATIONS (+, +=)" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "a + b = " << a + b << "\t\t[Expected: 63]" << std::endl;
    std::cout << "(c += a) = " << (c += a) << "\t[Expected: 42]" << std::endl;

    std::cout << "\n========================================" << std::endl;
    std::cout << "[3] INCREMENTS (++, post and pre)" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "State of b = " << b << "\t[Expected: 21]" << std::endl;
    std::cout << "++b = " << ++b << "\t\t[Expected: 22]" << std::endl;
    std::cout << "b++ = " << b++ << "\t\t[Expected: 22]" << std::endl;

    std::cout << "\n========================================" << std::endl;
    std::cout << "[4] DIGIT SHIFT (<<, >>)" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << "\t[Expected: 230000000042]" << std::endl;
    std::cout << "(d <<= 4) = " << (d <<= 4) << "\t[Expected: 13370000]" << std::endl;
    std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << "\t[Expected: 133700]" << std::endl;

    std::cout << "\n========================================" << std::endl;
    std::cout << "[5] COMPARATORS (<, <=, >, >=, ==, !=)" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Current state of a = " << a << std::endl;
    std::cout << "Current state of d = " << d << std::endl;

    std::cout << "(d < a)  = " << (d < a) << "\t\t[Expected: 0]" << std::endl;
    std::cout << "(d <= a) = " << (d <= a) << "\t\t[Expected: 0]" << std::endl;
    std::cout << "(d > a)  = " << (d > a) << "\t\t[Expected: 1]" << std::endl;
    std::cout << "(d >= a) = " << (d >= a) << "\t\t[Expected: 1]" << std::endl;
    std::cout << "(d == a) = " << (d == a) << "\t\t[Expected: 0]" << std::endl;
    std::cout << "(d != a) = " << (d != a) << "\t\t[Expected: 1]" << std::endl;

    std::cout << "\n========================================" << std::endl;
    std::cout << "✅ ALL TESTS EXECUTED SUCCESSFULLY" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}
