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
#include <bitset>

// pg 91, 1.4

// Check if string is a permuation of a palindrome
bool PalindromePermutation(std::string input_string)
{
  std::bitset<26> bits{0};

  // check if string is empty
  if (input_string.empty()) {
    return false;
  }
  
  // iterate through and find if was already set or set
  for (const char& ch : input_string) {

    int index = 0;
    bool test = true;

    // convert char to position in std::bitset
    if (ch >= 'a' && ch <= 'z') {
      index = ch - 'a';
    }
    else if (ch >= 'A' && ch <= 'Z') {
      index = ch - 'A';
    }
    else {
      test = false;
    }

    // test if bit is set/clear
    if (test) {
      (!bits.test(index)) ? bits.set(index) : bits.reset(index);
    }
  }

  // do final calculation if string is a palindrome permutation
  std::bitset<26> result(bits.to_ulong() - 1);

  if ((bits & result) == 0) {
    return true;
  }

  return false;
}

int main(){
  std::vector<std::string> strings = {"tact coa", "I did not fool you", "Tact Coa", ""};

  std::cout << std::endl << "Checking if string is a palindrome permutation" << std::endl;
  for (auto phrase : strings) {
    std::cout << phrase << std::string(": ") << std::boolalpha << PalindromePermutation(phrase) << std::endl;
  }

  return 0;
}


/*
Output:
Checking if string is a palindrome permutation
tact coa: true
I did not fool you: false
Tact Coa: true
: false

Time Complexity:
Since it's all done in a for loop, it takes O(n) time.

Space Complexity:
No additional space except the std::bitset and string size, so it uses O(n) space where n is the length of the string.
*/