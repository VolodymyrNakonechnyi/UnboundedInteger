#include "../UnboundedInteger/UnboundedInteger.h"
#include <iostream>
#include <cstdint>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

void testXOR() {
    UnboundedInteger numberA("51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4");
    UnboundedInteger numberB("403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c");
    UnboundedInteger expectedResult("1182d8299c0ec40ca8bf3f49362e95e4ecedaf82bfd167988972412095b13db8");

    UnboundedInteger result = numberA.XOR(numberB);
    if (result.getHex() != expectedResult.getHex()) {
        throw std::runtime_error("XOR test failed");
    }
}

void testADD() {
    UnboundedInteger numberA("36f028580bb02cc8272a9a020f4200e346e276ae664e45ee80745574e2f5ab80");
    UnboundedInteger numberB("70983d692f648185febe6d6fa607630ae68649f7e6fc45b94680096c06e4fadb");
    UnboundedInteger expectedResult("a78865c13b14ae4d25e90771b54963ed2d68c0a64d4a8ba7c6f45ee0e9daa65b");

    UnboundedInteger result = numberA.ADD(numberB);
    if (result.getHex() != expectedResult.getHex()) {
        throw std::runtime_error("ADD test failed");
    }
}

void testSUB() {
    UnboundedInteger numberA("33ced2c76b26cae94e162c4c0d2c0ff7c13094b0185a3c122e732d5ba77efebc");
    UnboundedInteger numberB("22e962951cb6cd2ce279ab0e2095825c141d48ef3ca9dabf253e38760b57fe03");
    UnboundedInteger expectedResult("10e570324e6ffdbd6b9c813dec968d9bad134bc0dbb061520934f4e59c2700b9");

    UnboundedInteger result = numberA.SUB(numberB);
    if (result.getHex() != expectedResult.getHex()) {
        throw std::runtime_error("SUB test failed");
    }
}

void testINV() {
    UnboundedInteger x("446f6e277420676f2075702074686572652e2e2e2049742773206461726b2e");
    UnboundedInteger expectedResult("bb9091d88bdf9890df8a8fdf8b979a8d9ad1d1d1dfb68bd8ff8cdf9b9e8d94d1");

    UnboundedInteger result = x.INV();
    if (result.getHex() != expectedResult.getHex()) {
        throw std::runtime_error("INV test failed");
    }
}

void testMOD() {
    UnboundedInteger x("10e570324e6ffdbc6b9c813dec968d9bad134bc0dbb061530934f4e59c2700b9");
    int expectedResult(18);

    int result = x.MOD(27);
    if (result != expectedResult) {
        throw std::runtime_error("INV test failed");
    }
}

int main() {


    testINV();
    testXOR();
    testADD();
    testSUB();

    return 0;
}

