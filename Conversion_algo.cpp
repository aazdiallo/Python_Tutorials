#include <iostream>
#include <stack>


void decimal_to_binary(int number_to_convert, stack<int>& mystack)
{
  while (number_to_convert > 0)
  {
    int remainder = number_to_convert % 2;
    mystack.push(remainder);
    number_to_convert /= 2;
  }
}

int main(int argc, char const *argv[]) {
  stack<int>binary;
  int number_to_convert = 0;

  stad::cout << "Enter number to covert into binary: ";
  std::cin >> number_to_convert;
  decimal_to_binary(number_to_convert, binary);
  while (!binary.empty()) {
    std::cout << binary.pop() << ' ';
  }

  return 0;
}
