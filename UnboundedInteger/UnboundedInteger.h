#pragma once
#include <iostream>
#include <cstdint>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>


class UnboundedInteger
{
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
        size_t numDigits = hexString.size() / 16 + (hexString.size() % 16 != 0);
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
        delete[] integer;

        size_t numDigits = hexString.size() / 16 + (hexString.size() % 16 != 0);
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

    UnboundedInteger ADD(const UnboundedInteger& second) const {
        int maxSize = std::max(size, second.size);
        uint64_t* resultInteger = new uint64_t[maxSize];
        int tmp_sum = 0;

        for (int i = 0; i < maxSize; i++) {
            uint64_t num1 = integer[i];
            uint64_t num2 = second.integer[i];
            int tmp_length = std::to_string(num1).length();

            resultInteger[i] = num1 + num2 + tmp_sum;

            int powerOfTen = pow(10, tmp_length);

            tmp_sum = ((num1 + num2) - ((num1 + num2) % powerOfTen)) / powerOfTen;

        }

        std::string ss;
        ss = convertToHexString(resultInteger, size);

        delete[] resultInteger;

        UnboundedInteger result(ss);
        return result;
    }

    UnboundedInteger SUB(const UnboundedInteger& second) const {
        int maxSize = std::max(size, second.size);
        uint64_t* resultInteger = new uint64_t[maxSize];
        int borrow = 0;

        for (int i = 0; i < maxSize; i++) {
            uint64_t num1 = (i < size) ? integer[i] : 0;
            uint64_t num2 = (i < second.size) ? second.integer[i] : 0;

            num1 -= borrow;
            borrow = 0;

            if (num1 < num2) {
                num1 += (1ULL << 64);
                borrow = 1;
            }

            resultInteger[i] = num1 - num2;
        }

        int newSize = maxSize;
        while (newSize > 1 && resultInteger[newSize - 1] == 0) {
            newSize--;
        }

        std::string ss;
        ss = convertToHexString(resultInteger, newSize);

        delete[] resultInteger;

        UnboundedInteger result(ss);
        return result;
    }


    int MOD(unsigned int modNum) const {
        std::string concatenatedNumbers;

        for (int i = 0; i < size; i++) {
            if (i != 0) {
                concatenatedNumbers += std::to_string((integer[i] * 100 + integer[i - 1]) % modNum);
            }
            else {
                concatenatedNumbers += std::to_string(integer[i] % modNum);
            }
        }

        int concatenatedInt = std::stoi(concatenatedNumbers);
        int result = concatenatedInt % modNum;

        return result;
    }
};
