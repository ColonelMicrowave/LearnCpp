First, getNumOfSides is defined in Shape.h (not recommended but used for the example)
Contents of Shape.h are also included in SecondShape.h
Both header files are included in main.cpp which takes the return value from getNumOfSides in Shape.cpp and prints it to the console
This would cause a compile error as there are duplicate getNumOfSides functions so compiler will not know which one to use in the int main() function
However the use of header guards will prevent this ("#ifndef" preprocessor command) as only one getNumOfSides function will be used
