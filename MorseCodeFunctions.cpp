#include "MorseCodeFunctions.h"
#include "Binary_Tree.h"
#include <iostream>
#include <fstream>
#include <sstream>

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
    std::cout << "Inserted letter: " << letter << " at position: " << code << std::endl;  // Debugging
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
        char letter = line[0];
        std::string code = line.substr(2);  // Morse code part (skip first 2 characters: letter and space)
        std::cout << "Inserting letter: " << letter << " with Morse code: " << code << std::endl;
        insert_morse_code(root, letter, code);
    }
    infile.close();
    return Binary_Tree<char>(root);
}

// Find Morse code for a given letter
std::string find_morse_code(BTNode<char>* node, char target_letter) {
    if (!node) return "";
    if (node->data == target_letter) return "";
    std::string left_result = find_morse_code(node->left, target_letter);
    if (!left_result.empty()) return "." + left_result;
    std::string right_result = find_morse_code(node->right, target_letter);
    if (!right_result.empty()) return "-" + right_result;
    return "";
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

// Encode a message into Morse code
std::string encode_message(BTNode<char>* root, const std::string& message) {
    std::string encoded_message;
    for (char c : message) {
        if (c != ' ') {
            std::string morse_code = find_morse_code(root, toupper(c));
            std::cout << "Encoding character: " << c << " to Morse code: " << morse_code << std::endl;
            if (!morse_code.empty()) encoded_message += morse_code + " ";
        } else {
            encoded_message += "  ";  // Double space for spaces between words
        }
    }
    return encoded_message;
}

// Decode a Morse code message back to text
std::string decode_message(BTNode<char>* root, const std::string& coded_message) {
    std::string decoded_message;
    std::istringstream stream(coded_message);
    std::string code;
    while (stream >> code) {
        char letter = find_letter(root, code);
        std::cout << "Decoding Morse code: " << code << " to letter: " << letter << std::endl;
        if (letter != '\0') decoded_message += letter;
    }
    return decoded_message;
}
