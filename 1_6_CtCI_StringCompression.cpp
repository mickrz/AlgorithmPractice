#include <string>
#include <vector>
#include <iostream>

using namespace std;

// pg 91, 1.6

// Compress string if possible or return original string
string StringCompression(string input_string)
{
  int input_length = input_string.size();
  string output_string;
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
  vector<string> words = {"aabcccccaaa", "daddaadddaaa", "Bonjour", "super duper"};

  cout << endl << "Returning the compressed string is possible" << endl;
  for (auto word : words) {
    cout << word << string(": ") << StringCompression(word) << endl;
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