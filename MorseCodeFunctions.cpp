/*
 * MorseCodeFunctions.cpp
 * Module: Morse Code Encoder and Decoder
 * Author: Jannatul Ferdousi Rajoni
 * Date: 15/11/24
 * Purpose: This implementation file contains the functions required to encode messages into Morse code 
 *          and decode Morse code back into text. The program also builds a binary tree representation 
 *          of Morse code using a provided file and provides utilities to handle encoding and decoding.
 *
 * File Dependencies:
 * - `MorseCodeFunctions.h`: Header file containing function declarations.
 * - `Binary_Tree.h`: Provides the Binary Tree data structure, specifically the `BTNode` template class.
 */

#include "MorseCodeFunctions.h"
#include "Binary_Tree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>  // For toupper function

// Insert a letter into the Morse code tree based on its code
// Parameters:
//   - root: The root node of the binary tree.
//   - letter: The letter to insert.
//   - code: The Morse code for the letter (string of '.' and '-').
// Side Effect: The binary tree is updated with the new letter at the appropriate position.
void insert_morse_code(BTNode<char>* root, char letter, const std::string& code) {
    BTNode<char>* current = root;
    for (char symbol : code) {
        if (symbol == '.') {
            if (!current->left) current->left = new BTNode<char>('*');
            current = current->left;
        } else if (symbol == '-') {
            if (!current->right) current->right = new BTNode<char>('*');
            current = current->right;
        }
    }
    current->data = letter;
    //std::cout << "Inserted letter: " << letter << " at position: " << code << std::endl;
}

// Build the Morse code tree from a file
// Parameters:
//   - filename: The name of the file containing Morse code mappings.
// Returns: A `Binary_Tree` object representing the constructed Morse code tree.
// Side Effect: The binary tree is built by reading the file, where each line corresponds to a letter 
//   and its Morse code.
Binary_Tree<char> build_morse_tree(const std::string& filename) {
    BTNode<char>* root = new BTNode<char>('*');
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }
    std::string line;
    while (std::getline(infile, line)) {
        if (line.empty()) continue;
        char letter = line[0];  // The letter (lowercase)
        std::string code = line.substr(2);  // Morse code part (skip first 2 characters: letter and space)
        insert_morse_code(root, letter, code);
    }
    infile.close();
    return Binary_Tree<char>(root);
}

// Find Morse code for a given letter
// Parameters:
//   - node: The current node of the tree to check.
//   - target_letter: The letter to find the Morse code for.
//   - code: A reference to a string that will store the Morse code for the target letter.
// Returns: `true` if the Morse code is found, `false` otherwise.
// Side Effect: The `code` string is updated with the Morse code for the target letter if found.
bool find_morse_code(BTNode<char>* node, char target_letter, std::string& code) {
    if (!node) return false;
    if (node->data == target_letter) return true;

    // Check left (dot)
    code.push_back('.');
    if (find_morse_code(node->left, target_letter, code)) return true;
    code.pop_back();

    // Check right (dash)
    code.push_back('-');
    if (find_morse_code(node->right, target_letter, code)) return true;
    code.pop_back();

    return false;
}

// Encode a message into Morse code
// Parameters:
//   - root: The root of the Morse code binary tree.
//   - message: The message to encode.
// Returns: A string containing the encoded Morse code with word boundaries represented by double spaces.
// Side Effect: If a character is not found in the tree, an error message is printed.
std::string encode_message(BTNode<char>* root, const std::string& message) {
    std::string encoded_message;
    for (char c : message) {
        if (c != ' ') {
            char lower_c = tolower(c);  // Convert to lowercase for encoding
            std::string morse_code;
            if (find_morse_code(root, lower_c, morse_code)) {  // Use lower_c for finding Morse code
                encoded_message += morse_code + " ";
            } else {
                std::cerr << "Error: Morse code not found for character: " << c << std::endl;
            }
        } else {
            encoded_message += "  ";  // Double space for spaces between words
        }
    }
    return encoded_message;
}

// Find the letter for a given Morse code sequence
// Parameters:
//   - node: The current node of the Morse code binary tree.
//   - code: The Morse code sequence to decode.
// Returns: The letter corresponding to the code, or `'\0'` if not found.
char find_letter(BTNode<char>* node, const std::string& code) {
    BTNode<char>* current = node;
    for (char symbol : code) {
        if (symbol == '.') current = current->left;
        else if (symbol == '-') current = current->right;
        if (!current) return '\0';
    }
    return current->data;
}

// Decode a Morse code message back to text
// Parameters:
//   - root: The root of the Morse code binary tree.
//   - coded_message: The encoded Morse code message to decode.
// Returns: A string containing the decoded message in plain text.
// Side Effect: If an invalid Morse code is encountered, an error message is printed. Word boundaries are 
//   handled by recognizing double spaces between words.
std::string decode_message(BTNode<char>* root, const std::string& coded_message) {
    std::string decoded_message;
    std::istringstream stream(coded_message);
    std::string morse_code;
    while (stream >> morse_code) {
        if (morse_code == "  ") {
            decoded_message += ' ';  // Word boundary
        } else {
            char letter = find_letter(root, morse_code);
            if (letter != '\0') decoded_message += letter;
            else std::cerr << "Error: Invalid Morse code encountered: " << morse_code << std::endl;
        }
    }
    return decoded_message;
}
