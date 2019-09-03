#include <iostream>

void fill_arr(int arr[], int size)
{
  int element = 0;
  std::cout << "Enter array content\n";
  for (int i = 0; i < size; ++i)
  {
    std::cin >> element;
    arr[i] = element;
  }
}

void selection_sort_arr(int arr[], int size)
{
  int temp = 0, index = 0;
  for (int i = 0; i < size-1; i++)
  {
    for (int j = i+1; j < size; j++)
    {
      if (arr[j] < arr[index])
        index = j;
    }
    // is swap necessary
    if (arr[i] > arr[index])
    {
      temp = arr[i];
      arr[i] = arr[index];
      arr[index] = temp;
    }
    index = i+1;
  }
}

void bubble_sort_arr(int arr[], int size)
{
  int temp = 0;
  while (size > 0)
  {
    bool is_sorted = true;
    for (int i = 0; i < size -1; i++)
    {
      if (arr[i] > arr[i+1])
      {
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        is_sorted = false;
      }
    }
    if (is_sorted)
      {
        std::cout << '\n' << size << '\n';
        break;
      }
    --size;
  }
}

void insertion_sort_arr(int arr[], int size)
{
  for (int i = 1; i < size; ++i)
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

// merging two sorted arrays in increasing order
void merge(int arr[], int arr_size, int L_arr[], int sizeL, int R_arr[], int sizeR)
{
  int iterate = 0, l = 0, r = 0;
  while (iterate < arr_size) // while
  {
    if (l < sizeL && r < sizeR) // when neither one of the subarrays is
    {                           // is completely looped through
      if (L_arr[l] < R_arr[r])
      {
        arr[iterate] = L_arr[l];
        ++l; // increment Left array index
      }
      else
      {
        arr[iterate] = R_arr[r];
        ++r;
      }
    }
    else if (l >= sizeL) // when L_arr[] is completely looped through
    {
      arr[iterate] = R_arr[r];
      ++r;
    }
    else // when R_arr[] is completely looped through
    {
      arr[iterate] = L_arr[l];
      ++l;
    }

    ++iterate; // increment final array's index
  }
}
void merge_sort_arr(int arr[], int size)
{
  if (size < 2)
    return;

  int half = size / 2;
  int left[half];
  int right[size - half];

  for (int i = 0; i < half; ++i) // fill in left subarray
    left[i] = arr[i];

  for (int i = half; i < size; ++i) // fill in right subarray
    right[i] = arr[i];

  merge_sort_arr(left, half);
  merge_sort_arr(right, size - half);
  merge(arr, size, left, half, right, (size - half));

  return;
}

int main(int argc, char const *argv[]) {
  int size = 10;
  int arr[10];
  int A[] = {-2, -4, 12, 0, 5, 11, -9, 32, 8};
  merge_sort_arr(A, 9);
  std::cout << "Merge is done!" << '\n';
  for (int i = 0; i < 9; ++i)
    std::cout << A[i] << ' ';

  int a[4] = {-12, 4, 6, 18}, b[6] = {-5, 1, 3, 5, 7, 11};
  merge(arr, 10, a, 4, b, 6);
  //fill_arr(arr, size);
  //selection_sort_arr(arr, size);
  //bubble_sort_arr(arr, size);
  //insertion_sort_arr(arr, size);

  std::cout << '\n';
  for (int i = 0; i < size; ++i)
    std::cout << arr[i] << ' ';

  std::cout << '\n';
  return 0;
}
