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