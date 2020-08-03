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

// pg 91, 1.9

// Checking if are rotated versions of each other
bool StringRotation(std::string input_string1, std::string input_string2)
{
  int input_string1_length = input_string1.size();
  int input_string2_length = input_string2.size();
  
  // check if string are same size / valid lengths and
  // then concatenate input_string1 with itself to search
  // for input_string2.
  if (input_string1_length != 0 || input_string2_length != 0
   || input_string1_length == input_string2_length) {
    std::string input_string1_concat = input_string1 + input_string1;
    std::size_t found = input_string1_concat.find(input_string2);
    if (found != std::string::npos) {
      return true;
    }
  }

  return false;
}

int main(){
  std::vector<std::string> words_one = {"Cracking", "the", "coding", "interview", "practice"};
  std::vector<std::string> words_two = {"ingCrack", "the", "ingcod", "outerview", "recital"};
  
  std::cout << std::endl << "Checking if are rotated versions of each other" << std::endl;
  for (int index = 0; index < words_one.size(); index++) {
    std::cout << words_one[index] << std::string(", ") << words_two[index] << ": " << std::boolalpha << StringRotation(words_one[index], words_two[index]) << std::endl;
  }  
  
	return 0;
}


/*
Output:
$g++ -o main *.cpp
$main

Checking if are rotated versions of each other
Cracking, ingCrack: true
the, the: true
coding, ingcod: true
interview, outerview: false
practice, recital: false

Time Complexity: O(n) where n is length of input strings.

Space Complexity: O(n) where n is the size of the string
*/