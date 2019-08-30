#include <iostream>
#include <stack>
#include <string>

// bool valid = std::cin.fail();
// while (!valid)
// {
//   std::cout << "Please enter whole numbers only!: ";
//   std::cin >> number;
//   valid = std::cin.fail();
// }

// print stack
void printStack(std::stack<int>& stacks)
{
  int places = 0;
  int remainder = stacks.size() % 4;
  bool digit_place = false;
  if (remainder != 0)
    digit_place = true;

  while (!stacks.empty())
  {
    if (remainder == 0 && digit_place)
    {
      std::cout << ' ';
      digit_place = false;
    }
    else
    {
      if (places > 3)
      {
        std::cout << ' ';
        places = 0; // reset places
      }
    }
    std::cout << stacks.top();
    stacks.pop();
    if (remainder == 0)
      ++places;

    else if (remainder > 0)
      --remainder; // decrease only if remainder doesn't equal to 0 already
  }
  std::cout << '\n';
}

// insert at bottom of stack
void insertAtBottom (std::stack<int>& stacks, int value)
{
  if (stacks.size() == 0)
    stacks.push(value);

  else
  {
    int temp = stacks.top();
    stacks.pop();
    insertAtBottom(stacks, value);
    stacks.push(temp);
  }
}

// reverse stack
void reverseStack(std::stack<int>& stacks)
{
  std::cout << "Size: " << stacks.top();
  if (stacks.size() > 0)
  {
    int var = stacks.top();
    stacks.pop();
    reverseStack(stacks);
    std::cout << var << ' ';
    insertAtBottom(stacks, var);
  }
}


int calculator ()
{
  int choice = -1;
  std::cout << "+====+====+====+====+====+====+====+====+====+===+====+\n";
  std::cout << "+====+====+====+ Scientific calculator +====+====+====+\n";
  std::cout << "+====+====+====+====+====+====+====+====+====+===+====+\n\n";
  std::cout << "\t 1. Decimal To Binary\n";
  std::cout << "\t 2. Decimal To Octal\n";
  std::cout << "\t 3. Decimal To Hexadecimal\n";
  std::cout << "\t 4. Binary To Decimal\n";
  std::cout << "\t 5. Binary To Octal\n";
  std::cout << "\t 6. Binary To Hexadecimal\n";
  std::cout << "\t 7. Octal To Binary\n";
  std::cout << "\t 8. Octal To Decimal\n";
  std::cout << "\t 9. Octal To Hexadecimal\n";
  std::cout << "\t10. Hexadecimal To Binary\n";
  std::cout << "\t11. Hexadecimal To Decimal\n";
  std::cout << "\t12. Hexadecimal To Octal\n";
  std::cout << "\nMake a choice or 0 to EXIT: ";
  std::cin >> choice;
  if (std::cin.fail())
    std::cout << "Your option should have been a digit! \nGood bye!...\n";

  else if (choice == 0)
  {
    std::cout << "You successfully exited the program!!!\n";
    return 0;
  }
  else
  {
    while (choice < 1 || choice > 12)
    {
      std::cout << "Please make a valid choice: ";
      std::cin >> choice;
    }
  }
  return choice;
}

void to_binary(std::stack<int>& stack, int number)
{
  //std::cout << "Number: " << number << '\n';
  //std::cout << "sizes: " << stack.size() << '\n';
  while (number > 0)
  {
    int remainder = number % 2;
    stack.push(remainder);
    number /= 2;
  }
}

// Converts whole numbers into different bases
void converter_function (std::stack<int>& mystack, int base, int type = 0)
{
  int number, initial_number;
  std::cout << "Enter the number to convert: ";
  std::cin >> number;
  while (std::cin.fail() || number < 0)
  {
    std::cout << "Please enter a whole number greater than 0: ";
    std::cin >> number;
  }
  // when a valid number is entered
  initial_number = number;
  switch (type)
  {
    case 0: // When conversion is from decimal to other types
    {
      to_binary(mystack, number);
      mystack.push(initial_number);
    }break;

    case 1: // When conversion is from binary to decimal
    {
      // Converts the binary number into an array of digits
      std::string binaryNumber = std::to_string(number);
      int i = 0; //iterator that iterates through the array of digits
      bool isBinary = false;
      while(isBinary == false) // Verify that the entered number is a valid binary
      {
        for (int i = 0; i < binaryNumber.length(); ++i)
        {
          if (binaryNumber[i] != '0' && binaryNumber[i] != '1')
          {
            std::cout << "Please enter a binary number: ";
            std::cin >> number;
            binaryNumber = std::to_string(number);
            isBinary = false;
          }
          else
          {
            isBinary = true;
          }
        }
      }
      // array size determines places of ^2
      int size_of_BinaryNumber = binaryNumber.length() - 1;
      int convertedNumber = 0, powers = 1;
      while (size_of_BinaryNumber >= 0)
      {
        for (int j = 0; j < binaryNumber.length(); ++j)
        {
          if (binaryNumber[j] == '1')
          {
            for (int i = 0; i < size_of_BinaryNumber; ++i)
              powers *= 2; // this doesn't execute for 2^0 hence, Powers = 1

            convertedNumber +=  powers;
            powers = 1; // reset powers
          }
          --size_of_BinaryNumber; // go to the next power down
        }
      }
      mystack.push(convertedNumber);
      mystack.push(initial_number);
      }break;

      case 2: // When conversion is from binary to octal
      {
        // Converts the binary number into an array of digits
        std::string binaryNumber = std::to_string(number);
        int i = 0; //iterator that iterates through the array of digits
        bool isBinary = false;
        while(isBinary == false) // Verify that the entered number is a valid octal
        {
          for (int i = 0; i < binaryNumber.length(); ++i)
          {
            if (binaryNumber[i] != '0' && binaryNumber[i] != '1')
            {
              std::cout << "Please enter a binary number: ";
              std::cin >> number;
              binaryNumber = std::to_string(number);
              isBinary = false;
            }
            else
            {
              isBinary = true;
            }
          }
        }
        // array size determines places of ^8
        int size_of_BinaryNumber = binaryNumber.length() - 1;
        int convertedNumber = 0, powers = 1, digit_place = 0;
        while (size_of_BinaryNumber >= 0)
        {
          for (int i = size_of_BinaryNumber; i >= 0 ; --i)
          {
            if (binaryNumber[i] == '1')
            {
              for (int j = 0; j < digit_place ; ++j)
                powers *= 2;

              if (digit_place > 2)
              {
                mystack.push(convertedNumber);
                // convertedNumber = 1 because next iteration would be 2^0
                convertedNumber = 1; // reset this every three passes "Octal"
                digit_place = 0; // reset bit place counter
              }
              else // keep adding so long as three places are not reached
                convertedNumber +=  powers;

              powers = 1; // reset powers for the upcoming iteration
            }
            ++digit_place; // count number of passed places
            --size_of_BinaryNumber; // go to the next power down
          }
        }
        mystack.push(convertedNumber);
        mystack.push(initial_number);
        }break;

        case 3: // When conversion is from binary to Hexadecimal
        {
          // Converts the binary number into an array of digits
          std::string binaryNumber = std::to_string(number);
          int i = 0; //iterator that iterates through the array of digits
          bool isBinary = false;
          while(isBinary == false) // Verify that the entered number is a valid octal
          {
            for (int i = 0; i < binaryNumber.length(); ++i)
            {
              if (binaryNumber[i] != '0' && binaryNumber[i] != '1')
              {
                std::cout << "Please enter a binary number: ";
                std::cin >> number;
                binaryNumber = std::to_string(number);
                isBinary = false;
              }
              else
              {
                isBinary = true;
              }
            }
          }
          // array size determines places of ^8
          int size_of_BinaryNumber = binaryNumber.length() - 1;
          int convertedNumber = 0, powers = 1, digit_place = 0;
          while (size_of_BinaryNumber >= 0)
          {
            for (int i = size_of_BinaryNumber; i >= 0 ; --i)
            {
              if (binaryNumber[i] == '1')
              {
                for (int j = 0; j < digit_place ; ++j)
                  powers *= 2;

                if (digit_place > 3)
                {
                  mystack.push(convertedNumber);
                  // convertedNumber = 1 because next iteration would be 2^0
                  convertedNumber = 1; // reset this every four passes "hex"
                  digit_place = 0; // reset bit place counter
                }
                else // keep adding so long as four places are not reached
                  convertedNumber +=  powers;

                powers = 1; // reset powers for the upcoming iteration
              }
              ++digit_place; // count number of passed places
              --size_of_BinaryNumber; // go to the next power down
            }
          }
          mystack.push(convertedNumber);
          mystack.push(initial_number);
          }break;

          case 4: // When conversion is from octal to binary
          {
            // Converts the binary number into an array of digits
            std::string octalNumber = std::to_string(number);
            int i = 0; //iterator that iterates through the array of digits
            bool isOctal = false;
            while(isOctal == false) // If entered number is a valid octal
            {
              int res = 0;
              for (int i = 0; i < octalNumber.length(); ++i)
              { // Verify that the entered number is a valid octal
                res = res * 10 + octalNumber[i] - '0';
                std::cout << res << ' ';
                if (res >= 0 && res < 8)
                {
                  isOctal = true;
                  res = 0; // reset res
                }
                else
                {
                  std::cout << "Please enter an octal number: ";
                  std::cin >> number;
                  octalNumber = std::to_string(number);
                  isOctal = false;
                }
              }
            }

            // when a valid octal number is entered
            // loop through all the octal digits
            std::stack<int> tempStack;
            for (int i = octalNumber.length() -1; i >= 0 ; --i)
            {
              // Char to int (std::stoi(std::to_string(octalNumber[i])))
              int res = 0;
              res = res * 10 + octalNumber[i] - '0';
              // call to_binary() function
              to_binary(tempStack, res);
              // render the octalNumber into three binary digits
              if (tempStack.size() == 1)
              { // when stack contains only one digit
                std::cout << "one element: \n";
                mystack.push(tempStack.top());
                tempStack.pop(); // empty stack
                mystack.push(0);
                mystack.push(0);
              }
              else if (tempStack.size() == 2) // when stack contains only two digit
              {
                int lst = tempStack.top(); tempStack.pop();
                int snd = tempStack.top(); tempStack.pop();
                mystack.push(snd);
                mystack.push(lst);
                mystack.push(0);

              }
              else
              {
                int lst = tempStack.top(); tempStack.pop();
                int snd = tempStack.top(); tempStack.pop();
                int fst = tempStack.top(); tempStack.pop();
                mystack.push(fst);
                mystack.push(snd);
                mystack.push(lst);
              }
            }
            mystack.push(initial_number);
          }break;

  }

}
// Converter function
void general_converter(std::stack<int>& mystack, int choice)
{
  switch (choice)
  {
    case 1: // Decimal to Binary conversion
    {
      std::cout << "Decimal To Binary Conversion!!!\n";
      converter_function(mystack, 2);
    }
    break;

    case 2: // Decimal to Octal conversion
    {
      std::cout << "Decimal To Octal Conversion!!!\n";
      converter_function(mystack, 8);
    }
    break;

    case 3: // Decimal to Hexadecimal conversion
    {
      std::cout << "Decimal To Hexadecimal Conversion!!!\n";
      converter_function(mystack, 16);
    }
    break;

    case 4: // Binary To Decimal Conversion
    {
      std::cout << "Binary To Decimal Conversion!!!\n";
      converter_function(mystack, 2, 1);
    }
    break;

    case 5: // Binary To Octal Conversion
    {
      std::cout << "Binary To Octal Conversion!!!\n";
      converter_function(mystack, 2, 2);
    }
    break;

    case 6: // Binary To Hexadecimal Conversion
    {
      std::cout << "Binary To Hexadecimal Conversion!!!\n";
      converter_function(mystack, 2, 3);
    }
    break;

    case 7: // Binary To Hexadecimal Conversion
    {
      std::cout << "Octal To Binary Conversion!!!\n";
      converter_function(mystack, 2, 4);
    }
    break;

    case 8: // Binary To Hexadecimal Conversion
    {
      std::cout << "Octal To Decimal Conversion!!!\n";
      converter_function(mystack, 2, 3);
    }
    break;

    case 9: // Binary To Hexadecimal Conversion
    {
      std::cout << "Octal To Hexadecimal Conversion!!!\n";
      converter_function(mystack, 2, 3);
    }
    break;
  }

}


int main(int argc, char const *argv[]) {
  std::stack<int>finalStack;
  //std::cout << "Size: " << finalStack.size() << '\n';
   //printStack(stackPtr);
  // reverseStack(finalStack);
  // printStack(finalStack);
  general_converter(finalStack, calculator());
  std::cout << finalStack.top() << " = ";
  finalStack.pop();
  printStack(finalStack);
  //std::cout << finalStack.top() << " = "; // Last stack element is the user's input
  //finalStack.pop(); // delete last element because that's the converted number


  return 0;
}
