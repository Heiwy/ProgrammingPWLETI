#include <iostream>

int main() {
    //Data types
    std::cout << "Data types:" << std::endl;
    std::cout << "1. int\t\t- " << sizeof(int) << std::endl;
    std::cout << "2. short int\t- " << sizeof(short int) << std::endl;
    std::cout << "3. long int\t- " << sizeof(long int) << std::endl;
    std::cout << "4. float\t- " << sizeof(float) << std::endl;
    std::cout << "5. double\t- " << sizeof(double) << std::endl;
    std::cout << "6. long double\t- " << sizeof(long double) << std::endl;
    std::cout << "7. char\t\t- " << sizeof(char) << std::endl;
    std::cout << "8. bool\t\t- " << sizeof(bool) << std::endl;

    //Integer to binary
    int value, order = 32;
    unsigned int mask = 1 << order - 1;
    std::string result;

    std::cout << "\nType integer value: ";
    std::cin >> value;

    for (int i = 1; i <= order; i++) {
        result.push_back(value & mask ? '1' : '0');
        value <<= 1;
        if (i % order - 1 == 0) {
            result.push_back(' ');
        }
    }

    std::cout << "  In memory: " << result << std::endl;

    //Float to binary
    union { float value; int i; } uf;
    result.clear();

    std::cout << "\nType float value: ";
    std::cin >> uf.value;

    for (int i = 0; i < order; i++) {
        result.insert(0, uf.i % 2 ? "1" : "0");
        uf.i >>= 1;
        if (i == 30 or i == 29 or i == 22) {
            result.insert(0, " ");
        }
    }

    std::cout << "  In memory: " << result << std::endl;

    //Double to binary
    union { double value; long long int i; } ud;
    result.clear();
    order = 64;

    std::cout << "\nType double value: ";
    std::cin >> ud.value;

    for (int i = 0; i < order; i++) {
        result.insert(0, ud.i % 2 ? "1" : "0");
        ud.i >>= 1;
        if (i == 62 or i == 61 or i == 51) {
            result.insert(0, " ");
        }
    }

    std::cout << "  In memory: " << result << std::endl;

    system("pause");
    return 0;
}