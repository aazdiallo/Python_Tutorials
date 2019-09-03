#include <iostream>
#include <vector>

void print_array(std::vector<int>& v)
{
  for (int i = 0; i < v.size(); ++i)
    std::cout << v[i] << ' ';
  std::cout << '\n';

  return;
}

std::vector<int> fill_array()
{
  std::vector<int> array;
  int element;
  while (element != -999)
  {
    std::cin>> element;
    if (element != -999)
      array.push_back(element);
  }

  return array;
}

void max_subarray_sum(std::vector<int>& v, int& sum, int& start, int& end)
{
  int CMax = v[0], OMax = v[0]; // Let v[0] be CMax and OMax
  start = end = 0; // Initialize start and end indexes to v[0]
  for (int i = 1; i < v.size(); ++i) // Loop from v[1] to end of vector
  {
    if (v[i] > v[i] + CMax) // if v[i] is greater than CMax + v[i]
    {
      CMax = v[i];
      if (v[i] > OMax) // is this value greater than OMax 'Overall Maximum'
        start = i; // if so, largest index will then start from here
    }
    else
      CMax += v[i]; // add v[i] to CMax 'Current Maximum'

    if (CMax > OMax) // is CMax greater OMax
    { // if so, OMax is overwritten to CMax and end takes the value of i
      OMax = CMax;
      end = i;
    }
  }
  sum = OMax; // Sum max sub array

  return;
}

int main(int argc, char const *argv[]) {

  std::vector<int> v;
  int start = 0, end = 0, sum = 0, choice;
  std::cin>> choice;
  switch (choice) {
    case 0:
      v = fill_array();
      break;

    case 1:
    {
      int seed, size, lower, higher;
      std::cin >> seed >> size >> lower >> higher;
      srand(seed);
      for (int i = 0; i < size; i++)
        v.push_back(rand() % higher + lower);
    }break;

    default: // exit program when wrong choice is made
      return 0;
  }
  
  print_array(v); // print array content
  max_subarray_sum(v, sum, start, end); // find Max sub array and print indexes
  std::cout << sum << ' ' << start << ' ' << end << ' ';
  std::cout << '\n';

  return 0;
}
