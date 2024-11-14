#include <iostream>
#include "Binary_Tree.h"
#include "MorseCodeFunctions.h"

int main() {
    std::string filename = "morse_code.txt";  // Morse code data file
    Binary_Tree<char> morse_tree = build_morse_tree(filename);

    std::string message = "HELLO WORLD";
    std::string encoded_message = encode_message(morse_tree.get_root(), message);
    std::cout << "Encoded message: " << encoded_message << std::endl;

    std::string decoded_message = decode_message(morse_tree.get_root(), encoded_message);
    std::cout << "Decoded message: " << decoded_message << std::endl;

    return 0;
}
