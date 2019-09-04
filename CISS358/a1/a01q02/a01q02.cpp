#include<iostream>
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
  int element = 0;
  while (element != -999)
  {
    std::cin>> element;
    if (element != -999)
      array.push_back(element);
  }
  return array;
}

void insertion_sort_arr(std::vector<int>& arr)
{
  for (int i = 1; i < arr.size(); ++i)
  {
    int j = i;
    while (j > 0 && arr[j] < arr[j-1])
    {
      int temp = arr[j-1];
      arr[j-1] = arr[j];
      arr[j]   = temp;
      --j;
    }
  }
}

void find_number(std::vector<int>& arr, int number)
{
  int start = 0, end = arr.size() - 1;
  while (start < end)
  {
    if (arr[start] + arr[end] == number)
    {
      std::cout << start << ' ' << end << '\n';
      break;
    }
    else if (arr[start] + arr[end] > number)
      --end; // move to the next element downward

    else if (arr[start] + arr[end] < number)
      ++start; // move to the next element upward
  }

  // if (start >= end)
  // {
  //   std::cout << "number is not found\n";
  //   return;  // exit program if element is not found
  // }
}

int main(int argc, char const *argv[]) {
  std::vector<int> v;
  int choice;
  std::cin>> choice;
  switch (choice) {
    case 0:
    {
      int number;
      std::cin >> number;
      v = fill_array(); // let user fill in array elements
      insertion_sort_arr(v); // sort the array
      find_number(v, number); // see if some of array elements == number
    }break;

    case 1:
    {
      int seed, size, lower, higher, number;
      std::cin >> seed >> number >> size >> lower >> higher;
      srand(seed);
      for (int i = 0; i < size; i++)
        v.push_back(rand() % higher + lower); // fill in array with random ints
        
      insertion_sort_arr(v); // sort the array
      find_number(v, number); // see if some of array elements == number
    }break;

    default: // exit program when wrong choice is made
      return 0;
  }

  print_array(v); // print array content
  return 0;
}
