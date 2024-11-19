*************************************************************
                      Morse Code Encoder and Decoder
*************************************************************

Author: Jannatul Ferdousi Rajoni
********************
Student ID: 200530077
********************
Date: 15/11/24

*************************************************************
DESCRIPTION:
*************************************************************
This program implements a Morse Code Encoder and Decoder using a binary tree data structure. The program supports:
- Encoding plain text messages into Morse code.
- Decoding Morse code back into plain text.
- Constructing a Morse code binary tree from a file containing letter-to-code mappings.

## Files Included
- **MorseCodeFunctions.h**: Header file containing function declarations and necessary includes.
- **MorseCodeFunctions.cpp**: Implementation file with definitions for encoding, decoding, and tree-building functions.
- **Binary_Tree.h**: Header file for the binary tree structure.
- **BTNode.h**: Header file for the binary tree node structure.
- **morse_code.txt**: A text file containing Morse code mappings for letters (e.g., `a .-`).
- **main.cpp**: Entry point for the program to demonstrate functionality.

## Features
### 1. Morse Code Tree
- A binary tree is used to represent Morse code, where:
  - `.` (dot) corresponds to the left child.
  - `-` (dash) corresponds to the right child.

### 2. Encoding Messages
- Converts plain text into Morse code.
- Spaces between words are represented by double spaces in Morse code.

### 3. Decoding Messages
- Converts Morse code into plain text.
- Handles spaces between words and errors for unrecognized codes.

### 4. File Input
- Reads Morse code mappings from a file (e.g., `morse_code.txt`) to build the tree.

## Compilation and Execution
### Compilation
To compile the program, use the following command:
```
g++ -o MorseCodeApp main.cpp MorseCodeFunctions.cpp
```

###  Input and Output
1. Encoding:
   - Input: `hello world`
   - Output: `.... . .-.. .-.. ---  .-- --- .-. .-.. -..`

2. Decoding:
   - Input: `.... . .-.. .-.. ---  .-- --- .-. .-.. -..`
   - Output: `hello world`

## File Format for Morse Data
The `morse_code.txt` file should have the following format:
```
a .-
b -...
c -.-.
...
```
Each line represents a letter and its corresponding Morse code, separated by a space.

## Notes
- Ensure the `morse_code.txt` file is in the same directory as the executable.
- The program supports case-insensitive input for encoding and decoding.

## Limitations
- Special characters (e.g., numbers or punctuation) are not supported unless included in the Morse data file.
- The program expects valid Morse code and input format.

*************************************************************
**References**
Additional information onMorse code Encoder and Decoder is obtained from:
- Class notes and materials provided by Aymen Bin Said
- Stack Overflow (https://stackoverflow.com/)
- W3 Schools (https://www.w3schools.com/cpp/)

Email: ferdousi.rajoniii@gmail.com
GitHub: https://github.com/Ferdousi-Rajoni/Morse-Code-Converter-with-Binary-Tree-Structure

