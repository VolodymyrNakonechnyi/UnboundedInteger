# UnboundedInteger

The `UnboundedInteger` class is designed to handle large numbers in a flexible manner. It provides methods for performing various arithmetic operations, including addition, subtraction, bitwise XOR, AND, and OR operations. One of its essential features is the ability to work with numbers of practically any size, thanks to its dynamic memory allocation.

However, it's worth noting that the subtraction method, while functional and correct, generates a compiler warning. This warning, related to left shift count exceeding the width of the type, does not impact the accuracy or functionality of the method. It simply alerts the developer to a potential overflow scenario, which, in this specific context, is handled correctly within the method's implementation.

In summary, the `UnboundedInteger` class empowers developers to work with large numbers seamlessly, providing a wide range of operations, and while there is a warning in one of its methods, the warning does not affect its correct behavior.

![image](https://github.com/VolodymyrNakonechnyi/UnboundedInteger/assets/146861887/5af6f7f3-2fe5-46e3-a487-5f9994e76d55)

