/* main.cpp
 * Module: Morse Code Encoder and Decoder
 * Author: Jannatul Ferdousi Rajoni
 * Date: 15/11/24
 * Purpose: This program allows users to encode and decode messages using Morse code.
 * It constructs a binary tree representation of Morse code from a file,
 * enabling users to encode a text message into Morse code and decode Morse code back into text.
 * The program runs interactively, accepting user input for encoding and decoding operations.
 */

#include <iostream>
#include "Binary_Tree.h"
#include "MorseCodeFunctions.h"

/**
 * Function Name: main
 * Purpose: The main entry point for the Morse Code Encoder and Decoder program.
 *          This function initializes the Morse code binary tree, processes user input,
 *          encodes a text message into Morse code, and decodes a Morse code message back into text.
 * Parameter(s): N/A
 * Precondition(s): A valid "morse_code.txt" file must be present in the working directory.
 * Returns: 0 on successful program execution.
 * Side Effect: Reads the "morse_code.txt" file and performs encoding/decoding operations.
 */
int main() {
    // Create the Morse code binary tree from the file
    std::string filename = "morse_code.txt";  // Morse code data file
    Binary_Tree<char> morse_tree = build_morse_tree(filename);

    // Get the message from the user
    std::string message;
    std::cout << "Enter a message: ";
    std::getline(std::cin, message);

    // Encode the message using Morse code
    std::string encoded_message = encode_message(morse_tree.get_root(), message);
    std::cout << "Encoded message: " << encoded_message << std::endl;

    // Decode the Morse code back into the original message
    std::string decoded_message = decode_message(morse_tree.get_root(), encoded_message);
    std::cout << "Decoded message: " << decoded_message << std::endl;

    return 0;
}
