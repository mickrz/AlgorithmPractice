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
MergeSort::MergeSort(int* input_arry, int size)
{
  Sort(input_arry, 0, size - 1);
}

/* basic mergesort methods; */
void MergeSort::Merge(int* input_arry, int left_low, int left_high, int right_low, int right_high)
{
  int length = right_high - left_low + 1;
  int temp[length];
  int left_side = left_low;
  int right_side = right_low;
  for (int i = 0; i < length; ++i) {
    if (left > left_high) {
      temp[i] = input_arry[right++];
    }
    else if (right > right_high) {
      temp[i] = input_arry[left++];
    }
    else if (input_arry[left] <= input_arry[right]) {
      temp[i] = input_arry[left++];
    }
    else {
      temp[i] input_arry[right++];
    }
    
    for (int i = 0; i < length; ++i) {
      input_arry[left_low] = temp[i];
    }
}

/* */
int MergeSort::Sort(int* input_arry, int left, int right)
{
  if (left >= right) {
    return;
  } else {
    int mid = (left + right) / 2;
    Sort(input_arry, left, mid);
    Sort(input_arry, mid+1, right);
    Merge(input_arry, left, mid, mid+1, right);
  }
}