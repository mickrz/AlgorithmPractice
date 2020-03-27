#include <string>
#include <vector>
#include <iostream>

// pg 91, 1.6

// Compress string if possible or return original string
std::string StringCompression(std::string input_string)
{
  int input_length = input_string.size();
  std::string output_string;
  int char_count = 0;
  
  for (int i = 1; i < input_length; i++) {
    // track count of char
    if (input_string[i-1] == input_string[i]) {
      char_count++;
    }
    else {
      // current char not equal to previous so append previous char with count
      output_string += input_string[i-1] + std::to_string(char_count);
      char_count = 0;
    }
  }
  
  return (input_length <= output_string.size()) ? input_string : output_string;
}

int main(){
  std::vector<std::string> words = {"aabcccccaaa", "daddaadddaaa", "Bonjour", "super duper"};

  std::cout << std::endl << "Returning the compressed string is possible" << std::endl;
  for (auto word : words) {
    std::cout << word << std::string(": ") << StringCompression(word) << std::endl;
  }
	return 0;
}


/*
Output:
$g++ -o main *.cpp
$main

Returning the compressed string is possible
aabcccccaaa: a1b0c4
daddaadddaaa: d0a0d1a1d2
Bonjour: Bonjour
super duper: super duper

Time Complexity:
O(n) where n is length of input string

Space Complexity:
O(n + m) although there is accounting for the length output_string (m), this
could be a waste if it's longer than the input string (n).
*/