# HUFFMAN-CODE

## Project Description 
Huffman coding is a lossless data compression algorithm that assigns variable-length codes to characters in a message or data stream based on their 
frequency of occurrence. The most frequent characters are assigned the shortest codes, and the least frequent characters are assigned the longest codes. 
This results in a more efficient use of storage space, as the most frequently occurring characters take up less space than the less frequently 
occurring characters. The algorithm was developed by David A. Huffman in 1951.

Huffman coding is a lossless data compression algorithm. It is used to compress data by creating a prefix code where shorter codewords are assigned to more frequently occurring characters or symbols in the data, and longer codewords are assigned to less frequently occurring characters. This allows for more efficient encoding and decoding of the data, as the more common symbols will be represented by shorter codewords. Huffman coding is used in a variety of applications, including data compression for storage and transmission, as well as in data compression for text and image compression.

In this code we use any text file and compress its data using Huffman Coding.

  > ## How to run it? 
g++ main.cpp Huffman.cpp Node.cpp -o run
./run computer.txt

You can try to use any text file you want to run it with any text file you want just:
g++ main.cpp Huffman.cpp Node.cpp -o run
./run <THE_NAME_OF_THE_TXT_FILE_YOU_WANT>

 > ## Final deliverable
## Screenshots
In this screenshots we are going to run the program with the computer.txt file that contains 5 paragraph worth of texts.

The first output are the different characters composing what is in the text file and its frequency next to it.

<img width="83" alt="chahracter list" src="https://user-images.githubusercontent.com/114533891/212437662-06c114dc-9cff-43da-b1eb-a02a1bc35755.png">


Once we know the frequency we can not get the total bits by multiply it by 8 and as we can see computer.txt is composed of 
15,496 bits in total.

<img width="229" alt="without compression" src="https://user-images.githubusercontent.com/114533891/212416272-7e006b3d-2a90-4c88-bb63-7a5ceb60f81c.png">

Now we once it is compressed, we can see that the total number of bits being used drastically decreased by almost half. 
From 15,496 bits to 8,678 after using the huffman coding.

<img width="314" alt="with compression" src="https://user-images.githubusercontent.com/114533891/212416277-ba43a2e6-9523-49e9-b1e8-2631c3c20300.png">

As we can see the picture bellow, each character is being assigned with its unique bits. The longer the bits of a character means it is being use less compared to some character with the least bits.

<img width="99" alt="assingning" src="https://user-images.githubusercontent.com/114533891/212416285-98079c3a-7067-4c34-97da-249968c3d89d.png">

Now it is outputing the Huffman Codes:

<img width="772" alt="huffman codes" src="https://user-images.githubusercontent.com/114533891/212436851-d79ac786-3aad-4be3-b2de-fddfe12ad355.png">

Now that we have the Huffman Codes, it is easy to turn it back to its original text: 

<img width="490" alt="huffman to og text" src="https://user-images.githubusercontent.com/114533891/212437053-a8c74a1a-55fb-4772-97f0-b42621d9e4b1.png">


