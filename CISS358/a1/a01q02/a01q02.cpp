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
  int element;
  while (element != -999)
  {
    std::cin>> element;
    if (element != -999)
      array.push_back(element);
  }

  return array;
}

// merging two sorted arrays in increasing order
void merge(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right)
{
  int iterate = 0, l = 0, r = 0;
  std::cout << "size: " << left.size() + right.size() << '\n';
  while (iterate < left.size() + right.size()) // while
  {
    if (l < left.size() && r < right.size()) // when neither one of the subarrays is
    {                           // is completely looped through
      if (left[l] < right[r])
      {
        arr[iterate] = left[l];
        ++l; // increment Left array index
      }
      else
      {
        arr[iterate] = right[r];
        ++r;
      }
    }
    else if (l >= left.size()) // when L_arr[] is completely looped through
    {
      arr[iterate] = right[r];
      ++r;
    }
    else // when R_arr[] is completely looped through
    {
      arr[iterate] = left[l];
      ++l;
    }

    ++iterate; // increment final array's index
  }
}
void merge_sort_arr(std::vector<int>& arr, int start, int end)
{
  if (arr.size() < 2)
    return;

  int half = arr.size() / 2;
  merge_sort_arr(arr, start, half);
  merge_sort_arr(arr, half, end);
  merge(arr, left, right);

  return;
}

int main(int argc, char const *argv[]) {
  std::vector<int> v;
  int i, j, choice;
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
  merge_sort_arr(v); // sort array
  //std::cout << sum << ' ' << start << ' ' << end << ' ';
  std::cout << '\n';

  return 0;
}
