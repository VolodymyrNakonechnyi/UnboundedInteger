#include <iostream>
#include <cstdint>
#include <string>
#include <sstream>
#include <iomanip>

class UnboundedInteger {
private:
    uint64_t* integer;
    int size;
    std::string hex;

    std::string convertToHexString(uint64_t* numArray, int arraySize) const {
        std::stringstream ss;
        for (int i = 0; i < arraySize; i++) {
            ss << std::hex << std::setw(16) << std::setfill('0') << numArray[i];
        }
        return ss.str();
    }

public:
    UnboundedInteger(const std::string& hexString) {
        size_t numDigits = hexString.size() / 16 + (hexString.size() % 16 != 0); // Округлюємо вгору
        integer = new uint64_t[numDigits];
        for (size_t i = 0; i < numDigits; i++) {
            std::string digitString = hexString.substr(i * 16, 16);
            std::stringstream ss(digitString);
            ss >> std::hex >> integer[i];
        }
        size = static_cast<int>(numDigits);
        hex = hexString;
    }

    ~UnboundedInteger() {
        delete[] integer;
    }

    uint64_t getInteger() const {
        return *integer;
    }

    std::string getHex() const {
        return hex;
    }

    void setHex(const std::string& hexString) {
        // Очищаємо старі дані
        delete[] integer;

        size_t numDigits = hexString.size() / 16 + (hexString.size() % 16 != 0); // Округлюємо вгору
        integer = new uint64_t[numDigits];
        for (size_t i = 0; i < numDigits; i++) {
            std::string digitString = hexString.substr(i * 16, 16);
            std::stringstream ss(digitString);
            ss >> std::hex >> integer[i];
        }
        size = static_cast<int>(numDigits);
        hex = hexString;
    }

    void printInteger() const {
        std::cout << "Integer contents: ";
        for (int i = 0; i < size; i++) {
            std::cout << integer[i] << " ";
        }
        std::cout << std::endl;
    }

    std::string INV() const {
        uint64_t* invertedInteger = new uint64_t[size];

        for (int i = 0; i < size; i++) {
            invertedInteger[i] = ~integer[i];
        }

        std::string ss;
        ss = convertToHexString(invertedInteger, size);

        delete[] invertedInteger;

        return ss;
    }

    UnboundedInteger XOR(const UnboundedInteger& second) const {
        int maxSize = std::max(size, second.size);
        uint64_t* resultInteger = new uint64_t[maxSize];

        for (int i = 0; i < maxSize; i++) {
            uint64_t num1 = integer[i];
            uint64_t num2 = second.integer[i];
            resultInteger[i] = num1 ^ num2;
        }

        std::string ss;
        ss = convertToHexString(resultInteger, size);

        delete[] resultInteger;

        UnboundedInteger result(ss);
        return result;
    }

    UnboundedInteger AND(const UnboundedInteger& second) const {
        int maxSize = std::max(size, second.size);
        uint64_t* resultInteger = new uint64_t[maxSize];

        for (int i = 0; i < maxSize; i++) {
            uint64_t num1 = integer[i];
            uint64_t num2 = second.integer[i];
            resultInteger[i] = num1 & num2;
        }

        std::string ss;
        ss = convertToHexString(resultInteger, size);

        delete[] resultInteger;

        UnboundedInteger result(ss);
        return result;
    }

    UnboundedInteger OR(const UnboundedInteger& second) const {
        int maxSize = std::max(size, second.size);
        uint64_t* resultInteger = new uint64_t[maxSize];

        for (int i = 0; i < maxSize; i++) {
            uint64_t num1 = integer[i];
            uint64_t num2 = second.integer[i];
            resultInteger[i] = num1 | num2;
        }

        std::string ss;
        ss = convertToHexString(resultInteger, size);

        delete[] resultInteger;

        UnboundedInteger result(ss);
        return result;
    }

    UnboundedInteger ShiftR(unsigned int position) const {
        uint64_t* resultInteger = new uint64_t[size];

        for (int i = 0; i < size; i++) {
            uint64_t num1 = integer[i];
            resultInteger[i] = num1 >> position;
        }

        std::string ss;
        ss = convertToHexString(resultInteger, size);

        delete[] resultInteger;

        UnboundedInteger result(ss);
        return result;
    }

    UnboundedInteger ShiftL(unsigned int position) const {
        uint64_t* resultInteger = new uint64_t[size];

        for (int i = 0; i < size; i++) {
            uint64_t num1 = integer[i];
            resultInteger[i] = num1 << position;
        }

        std::string ss;
        ss = convertToHexString(resultInteger, size);

        delete[] resultInteger;

        UnboundedInteger result(ss);
        return result;
    }
};

int main() {
    //UnboundedInteger x("446f6e277420676f2075702074686572652e2e2e2049742773206461726b2e");
    //
    //std::cout << x.getHex() << '\n';
    //x.printInteger();
    //std::cout << std::endl << x.INV();

    UnboundedInteger numberA("51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4");
    UnboundedInteger numberB("403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c");

    UnboundedInteger numberC = numberA.XOR(numberB);
    std::cout << "XOR: " << numberC.getHex() << std::endl;

    return 0;
}
