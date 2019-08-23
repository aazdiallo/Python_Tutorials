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

void merge_sort_arr(int arr[], int size)
{
  if (size < 2)
    return;

  int half = size / 2;
  int *left = new int[half];
  if (size % 2 == 0)
    int right[half];

  else
    int right[half+1];

  for (int i = 0; i < half; ++i)
    left[i] = arr[i];

  for (int i = half; i < size; ++i)
    right[i] = arr[i];

}

int main(int argc, char const *argv[]) {
  int size = 10;
  int arr[10];
  fill_arr(arr, size);
  //selection_sort_arr(arr, size);
  //bubble_sort_arr(arr, size);
  insertion_sort_arr(arr, size);
  std::cout << '\n';
  for (int i = 0; i < size; ++i)
  std::cout << arr[i] << ' ';

  return 0;
}
