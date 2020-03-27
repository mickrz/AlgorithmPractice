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