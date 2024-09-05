#include <bitset>
#include <iostream>

int main()
{
  std::bitset<8> bits{ 0b0000'1101 };
  std::cout << bits.size() << " bits are in the bitset\n";
  std::cout << bits.count() << " bits are set to true\n";

  std::cout << std::boolalpha;

  std::cout << "All the bits: " << bits << '\n';
  std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
  std::cout << "Bit 4 has value: " << bits.test(4) << '\n';
  std::cout << "All bits are true: " << bits.all() << '\n';
  std::cout << "Some bits are true: " << bits.any() << '\n';
  std::cout << "No bits are true: " << bits.none() << '\n';

  return 0;
}
