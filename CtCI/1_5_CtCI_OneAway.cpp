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

#include <string>
#include <vector>
#include <iostream>

// pg 91, 1.5

// Check if string is one away
bool OneAway(std::string reference_string, std::string comparison_string)
{
  int ref_size = reference_string.size(), cmp_size = comparison_string.size();
  int ref_index = 0, cmp_index = 0;

  if (ref_size > cmp_size) {
    // reference is bigger than comparison string
    while (ref_index < ref_size && cmp_index < cmp_size) {
      if (reference_string[ref_index] != comparison_string[cmp_index]) {
        if (ref_index != cmp_index) {
          return false;
        }
        // this should align the strings, otherwise strings aren't one away
        ref_index++;
      }
      else {
        // iterate to the next char
        ref_index++;
        cmp_index++;
      }
    }
    return true;
  }
  else if (ref_size < cmp_size) {
    // reference is smaller than comparison string
    while (ref_index < ref_size && cmp_index < cmp_size) {
      if (reference_string[ref_index] != comparison_string[cmp_index]) {
        if (ref_index != cmp_index) {
          return false;
        }
        // this should align the strings, otherwise strings aren't one away
        cmp_index++;
      }
      else {
        // iterate to the next char
        ref_index++;
        cmp_index++;
      }
    }
    return true;
  }
  else if (ref_size == cmp_size) {
    // reference is equal to comparison string
    bool found_diff = false;
    while (ref_index < ref_size) {
      if (reference_string[ref_index] != comparison_string[ref_index]) {
        if (found_diff) {
          return false;
        }
        found_diff = true;
      }
      ref_index++;
    }
    // this covers the case if strings are the same
    return found_diff;
  }
  return false;
}

int main(){
  std::string reference("pale"); 
  std::vector<std::string> words = {"ple", "pales", "bale", "bae", "pale"};

  std::cout << std::endl << "Checking if string is one away from master" << std::endl;
  for (auto word : words) {
    std::cout << word << std::string(": ") << std::boolalpha << OneAway(reference, word) << std::endl;
  }

  return 0;
}


/*
Output:
$g++ -o main *.cpp
$main

Checking if string is one away from reference
ple: true
pales: true
bale: true
bae: false
pale: false

Time Complexity:
This is just one iteration through the string, so it takes O(n) time.

Space Complexity:
There is no additional space required so it uses O(n) space.
*/