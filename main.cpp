#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Huffman.h"

using namespace std;

int main(int argc, char* argv[]) {
  
  if (argc != 2) {
    cerr << "Usage error, expected: ./a.out *.txt\n";
    exit(1);
  }
  
  string input_file = argv[1];
  Huffman h(input_file);
  h.BuildHuffmanTree();
  h.PrintCharFrequencies(); 
  h.SetBitCodes();
  h.SetBitsPerChar();
  h.Stats();
  h.BitMap();
  cout << "Priting Huffman Codes:" << endl;
  h.PrintMessage(); //hufmanccodes
  cout << "Huffman code to OG TEXT:" << endl;
  h.HuffmanDecompress(); // printing text is right
  //cout << "Displaying Prefix Tree:" << endl; // 
  //h.DisplayPrefixTree();
  
  return 0;
}


