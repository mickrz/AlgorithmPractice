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

// pg 90, 1.2

// Assume ascii, if using a different set, then add/change here...
static const uint8_t ASCII_LIMIT = 128;

// Determine if input strings are permuations of each other
bool CheckPermutation(const std::string input_string1, const std::string input_string2)
{
  uint16_t input_length1 = input_string1.length();
  uint16_t input_length2 = input_string2.length();

  // this would imply some character(s) are not the same
  if (input_length1 != input_length2) {
    return false;
  }

  // iterate through and keep track of character counts
  uint8_t count[ASCII_LIMIT]={0};

  for (uint8_t i = 0; i < input_length1; i++) {
    count[input_string1[i]]++;
  }

  // check counts in 2nd string and if less than 0
  for (uint8_t i = 0; i < input_length2; i++) {
    count[input_string2[i]]--;
    if (count[input_string2[i]] < 0) {
      return false;
    }
  }
  return true;
}

int main(){

  std::vector<std::string> words = {"Cracking", "ckCarnig", "coding"};
  std::cout << std::endl << "Checking if permutations of each other" << std::endl;

  if (CheckPermutation(words[0], words[1])) {
    std::cout << words[0] << std::string(" and ") << words[1] << " are permuations of each other" << std::endl;
  }
  else {
    std::cout << words[0] << std::string(" and ") << words[1] << " are not permuations of each other" << std::endl;
  }

  if (CheckPermutation(words[2], words[1])) {
    std::cout << words[2] << std::string(" and ") << words[1] << " are permuations of each other" << std::endl;
  }
  else {
    std::cout << words[2] << std::string(" and ") << words[1] << " are not permuations of each other" << std::endl;
  }
  return 0;
}


/*
Output:
$g++ -o main *.cpp
$main

Checking if permutations of each other
Cracking and ckCarnig are permuations of each other
coding and ckCarnig are not permuations of each other

Time Complexity: O(n) since iterating each input string and using hash map to
 track the count. If using nested for loops and no hash table, then O(n*n).

Space Complexity: O(n + m) where n is string length and m is size of hash table.
*/