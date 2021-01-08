/*
MIT License

Copyright (c) 2020 Mike Rzucidlo

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#include "MergeSort.h"

/* mergesort class */
MergeSort::MergeSort(int input_arry[], int size)
{
  Sort(input_arry, 0, size - 1);
  for (int i = 0; i < size; i++) {
    std::cout << i << ": " << input_arry[i] << std::endl;
  }
}

/* basic mergesort methods; */
void MergeSort::Merge(int input_arry[], int left, int mid, int right)
{
  int i, j, k;
  int left_size = mid - left + 1, right_size = right - mid;
  int *left_arry = new int[left_size], *right_arry = new int[right_size];

  for (i = 0; i < left_size; i++) {
    left_arry[i] = input_arry[left + i];
  }
  
  for (j = 0; j < right_size; j++) {
    right_arry[j] = input_arry[mid + 1 + j];
  }

  i = 0, j = 0, k = left;

  while (i < left_size && j < right_size) {
    if (left_arry[i] <= right_arry[j]) {
      input_arry[k++] = left_arry[i++];
    }
    else {
      input_arry[k++] = right_arry[j++];
    }
  }

  while (i < left_size) {
    input_arry[k++] = left_arry[i++];
  }
  while (j < right_size) {
    input_arry[k++] = right_arry[j++];
  } 

  delete[] left_arry;
  delete[] right_arry;
}

void MergeSort::Sort(int input_arry[], int left, int right)
{
  if (left >= right) {
    return;
  }
  
  int mid = (right + left - 1) / 2;
  Sort(input_arry, left, mid);
  Sort(input_arry, mid + 1, right);
  Merge(input_arry, left, mid, right);
}
