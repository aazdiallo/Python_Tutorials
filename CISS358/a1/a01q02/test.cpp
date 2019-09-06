#include<iostream>
#include<vector>

void print_array(std::vector<int>& v)
{
  for (int i = 0; i < v.size(); ++i)
    std::cout << v[i] << ' ';

  std::cout << '\n';
  return;
}

// std::vector<int>left, right;
// for (int i = 0; i < half; ++i)
//   left.push_back(arr[i]);
//
// for (int j = half; j < arr.size(); ++j)
//   right.push_back(arr[j]);

// // merging two sorted arrays in increasing order
void merge(std::vector<int>& arr, std::vector<int> left, std::vector<int> right)
{
  int iterate = 0, l = 0, r = 0;
  while (iterate < left.size() + right.size()) // while
  {
    if (l < left.size() && r < right.size()) // when neither one of the subarrays is
    {                                       // is completely looped through
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

void merge_sort(std::vector<int>& arr, int start, int end)
{
  //std::cout << arr.size() << ' ';
  if (start < end)
  {
    int middle = start + (end - start)/2;
    std::vector<int>left, right;
    for (int i = 0; i < middle; ++i)
      left.push_back(arr[i]);

    for (int i = middle; i < end; ++i)
      right.push_back(arr[i]);

    merge_sort(left, start, middle);
    merge_sort(right, middle, end-1);
    merge(arr, left, right);
  }
  return;
}

int main(int argc, char const *argv[]) {
  std::vector<int>s, q;
  //s.push_back(15);
  s.push_back(5);
  s.push_back(-2);
  s.push_back(5);
  s.push_back(-7);
  s.push_back(11);
  s.push_back(33);

  q.push_back(-17);
  q.push_back(-7);
  q.push_back(13);
  q.push_back(18);
  q.push_back(31);

  merge_sort(s, 0, 6);
  print_array(s);

return 0;
}
