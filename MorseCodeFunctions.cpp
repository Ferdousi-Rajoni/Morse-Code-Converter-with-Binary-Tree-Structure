/*
 * MorseCodeFunctions.cpp
 * Module: Morse Code Encoder and Decoder
 * Author: Jannatul Ferdousi Rajoni
 * Date: 15/11/24
 * Purpose: This implementation file contains the functions required to encode messages into Morse code 
 *          and decode Morse code back into text. The program also builds a binary tree representation 
 *          of Morse code using a provided file and provides utilities to handle encoding and decoding.
 *
 * Functionality:
 * - `insert_morse_code`: Inserts a letter into the Morse code binary tree based on its code.
 * - `build_morse_tree`: Constructs a binary tree for Morse code using a data file.
 * - `find_morse_code`: Recursively finds the Morse code for a given character.
 * - `encode_message`: Encodes a given text message into Morse code.
 * - `find_letter`: Finds the character for a given Morse code sequence by traversing the tree.
 * - `decode_message`: Decodes a Morse code message back into plain text, handling spaces between words.
 *
 * Notes:
 * - The program assumes the input Morse code file contains lowercase letters and their corresponding Morse code.
 * - The message for encoding/decoding is case-insensitive.
 * - Word boundaries in Morse code are handled by recognizing double spaces during decoding.
 */



#include "MorseCodeFunctions.h"
#include "Binary_Tree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>  // For toupper function

// Insert a letter into the Morse code tree based on its code
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
std::string decode_message(BTNode<char>* root, const std::string& coded_message) {
    std::string decoded_message;
    std::istringstream stream(coded_message);
    std::string code;
    bool word_boundary = false;

    while (stream >> code) {
        // Check if we've hit a double space (word boundary)
        if (word_boundary) {
            decoded_message += ' ';  // Add space between words
            word_boundary = false;   // Reset word boundary
        }

        // Decode individual Morse code to a letter
        char letter = find_letter(root, code);
        if (letter != '\0') {
            decoded_message += letter;
        } else {
            std::cerr << "Error: Letter not found for Morse code: " << code << std::endl;
        }

        // Check if there's a double space after the current code segment
        if (stream.peek() == ' ') {
            stream.get();  // Consume the first space
            if (stream.peek() == ' ') {
                stream.get();  // Consume the second space
                word_boundary = true;  // Set word boundary for the next iteration
            }
        }
    }
    return decoded_message;
}
