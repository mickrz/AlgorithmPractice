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

#include <vector>
#include <iostream>

// pg 90, 1.3

// Determine if input strings are permuations of each other
bool Urlify(char* input_string, int len)
{
  // check that string is not empty
  if (input_string != NULL) {
    if(input_string[0] == '\0') {
      return false;
    }
  }

  int i = 0;
  int spaceCount = 0;
  int new_len = len;

  // count spaces in true length area
  for (; i < len; i++) {
    if (input_string[i] == ' ') {
      spaceCount++;
    }
  }

  // adjust length of string by spaceCount
  new_len += 2 * spaceCount - 1;
  
  // start from the end and copy accordingly
  for(i = len - 1; i >= 0; --i) {
    if (input_string[i] != ' ') {
      input_string[new_len--] = input_string[i];
    }
    else {
      input_string[new_len--] = '0';
      input_string[new_len--] = '2';
      input_string[new_len--] = '%';
    }
  }
  return true;
}


int main(){

	std::cout << std::endl << "Replace all spaces in a string with '%20'" << std::endl;
    char in_string1[] = "The sky is blue      ";
    std::cout << "Test #1: " << in_string1 << std::endl;
    if (Urlify(in_string1, 15)) {
      std::cout << in_string1 << std::endl;
    }
    else {
      std::cout << "Invalid string" << std::endl;
    }

    char in_string2[] = "The grass is greener on the other side              ";
    std::cout << "Test #2: " << in_string2 << std::endl;
    if (Urlify(in_string2, 38)) {
      std::cout << in_string2 << std::endl;
    }
    else {
      std::cout << "Invalid string" << std::endl;
    }

    char in_string3[] = "";
    std::cout << "Test #3: " << in_string3 << std::endl;
    if (Urlify(in_string3, 5)) {
      std::cout << in_string3 << std::endl;
    }
    else {
      std::cout << "Invalid string" << std::endl;
    }
    
	return 0;
}

/*
Output:
$g++ -o main *.cpp
$main

Replace all spaces in a string with '%20'
Test #1: The sky is blue      
The%20sky%20is%20blue
Test #2: The grass is greener on the other side              
The%20grass%20is%20greener%20on%20the%20other%20side
Test #3: 
Invalid string


Time Complexity: O(n), There are two for loops, but disregard the constant

Space Complexity: O(n), No extra space is used, n is the space allocated as-is for the string.
*/