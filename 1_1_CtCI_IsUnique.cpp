#include <string>
#include <vector>
#include <iostream>
#include <bitset>

// pg 90, 1.1

// Assume ascii, if using a different set, then add/change here...
static const uint8_t ASCII_LIMIT = 128;

// Determine if input string has unique characters
bool IsUnique(const std::string input_string)
{
  uint16_t input_length = input_string.length();
  std::bitset<128> bits{0};

  // this would imply some character(s) would be duplicate
  if (input_length > ASCII_LIMIT) {
      return false;
  }

  // iterate through and find if was already set or set
  for (uint8_t i = 0; i < input_length; i++) {
    if (!bits.test(input_string[i])) {
        bits.set(input_string[i]);
    }
    else {
        return false;
    }
  }
  return true;
}

int main(){
  std::vector<std::string> words = {"Cracking", "the", "coding", "interview", "practice"};
  std::cout << std::endl << "Checking if unique" << std::endl;
  for (auto word : words) {
    std::cout << word << std::string(": ") << std::boolalpha << IsUnique(word) << std::endl;
  }

  return 0;
}


/*
Output:
$g++ -o main *.cpp
$main
Checking if unique
Cracking: true
the: true
coding: true
interview: false
practice: false

Time Complexity: O(n) since iterating through once over each character and
 are using a bitset to manage if a char has been seen before. Otherwise,
 the string could be cycled through using two for loops to check if a
 character appear more than once is the input string.

Space Complexity: O(n + m) where n is string length and m is bitset length.
 If a bitset is not used, the O(n).
*/