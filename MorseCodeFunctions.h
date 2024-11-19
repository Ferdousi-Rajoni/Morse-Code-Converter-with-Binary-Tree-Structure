/*
 * MorseCodeFunctions.h
 * Module: Morse Code Encoder and Decoder
 * Author: Jannatul Ferdousi Rajoni
 * Date: 15/11/24
 * Purpose: This header file declares functions and data structures for encoding, decoding, 
 *          and constructing a Morse code binary tree. It provides the necessary declarations 
 *          to facilitate the encoding of messages into Morse code and the decoding of Morse code back into text.
 */

#ifndef MORSECODEFUNCTIONS_H
#define MORSECODEFUNCTIONS_H

#include <string>
#include "BTNode.h"
#include "Binary_Tree.h"

/*
 * Function: insert_morse_code
 * Purpose: Inserts a letter into the Morse code binary tree based on its code.
 * Parameters:
 *   - root: A pointer to the root node of the binary tree.
 *   - letter: The character to insert into the tree.
 *   - code: The Morse code associated with the letter (a string of '.' and '-').
 * Returns: None.
 * Side Effect: The binary tree is modified with the new letter at the appropriate position.
 */
void insert_morse_code(BTNode<char>* root, char letter, const std::string& code);

/*
 * Function: build_morse_tree
 * Purpose: Builds a Morse code binary tree from a file that maps letters to Morse code.
 * Parameters:
 *   - filename: The name of the file containing the letter-to-Morse code mappings.
 * Returns: A Binary_Tree object representing the constructed Morse code tree.
 * Side Effect: The binary tree is constructed by reading from the file and inserting nodes.
 */
Binary_Tree<char> build_morse_tree(const std::string& filename);

/*
 * Function: encode_message
 * Purpose: Encodes a message into Morse code using a provided Morse code binary tree.
 * Parameters:
 *   - root: A pointer to the root node of the Morse code binary tree.
 *   - message: The message to encode (a string of characters).
 * Returns: A string representing the encoded Morse code message with word boundaries indicated by double spaces.
 * Side Effect: An error is printed if a character cannot be encoded into Morse code.
 */
std::string encode_message(BTNode<char>* root, const std::string& message);

/*
 * Function: decode_message
 * Purpose: Decodes a Morse code message back into text using a provided Morse code binary tree.
 * Parameters:
 *   - root: A pointer to the root node of the Morse code binary tree.
 *   - coded_message: The Morse code message to decode (a string of '.' and '-' with spaces).
 * Returns: A string representing the decoded text message.
 * Side Effect: An error is printed if invalid Morse code is encountered.
 */
std::string decode_message(BTNode<char>* root, const std::string& coded_message);

/*
 * Function: find_morse_code
 * Purpose: Finds the Morse code corresponding to a given letter by traversing the Morse code binary tree.
 * Parameters:
 *   - root: A pointer to the root node of the Morse code binary tree.
 *   - target_letter: The letter for which the Morse code is being searched.
 * Returns: A string representing the Morse code for the letter, or an empty string if not found.
 */
std::string find_morse_code(BTNode<char>* root, char target_letter);

/*
 * Function: find_letter
 * Purpose: Finds the letter corresponding to a given Morse code sequence by traversing the Morse code binary tree.
 * Parameters:
 *   - root: A pointer to the root node of the Morse code binary tree.
 *   - code: The Morse code sequence (a string of '.' and '-') to decode.
 * Returns: The decoded letter if found, or `'\0'` if the letter is not found.
 */
char find_letter(BTNode<char>* root, const std::string& code);

#endif
