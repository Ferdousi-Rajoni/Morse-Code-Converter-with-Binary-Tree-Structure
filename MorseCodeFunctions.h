#ifndef MORSECODEFUNCTIONS_H
#define MORSECODEFUNCTIONS_H

#include <string>
#include "BTNode.h"
#include "Binary_Tree.h"

// Functions for encoding, decoding, and building Morse code
void insert_morse_code(BTNode<char>* root, char letter, const std::string& code);
Binary_Tree<char> build_morse_tree(const std::string& filename);
std::string encode_message(BTNode<char>* root, const std::string& message);
std::string decode_message(BTNode<char>* root, const std::string& coded_message);
std::string find_morse_code(BTNode<char>* root, char target_letter);
char find_letter(BTNode<char>* root, const std::string& code);

#endif
