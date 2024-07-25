// facebook interview question (premium question)
// Design an algorithm to encode a list of strings to a string. The encoded string is
// then sent over the network and is decoded back to the original list of strings.

#include <iostream>
#include <vector>
#include <string>


class Codec
{
public:
    // Encode a list of strings to a single string
    std::string encode(const std::vector<std::string>& strs)
    {
        std::string encoded_string;
        for (const std::string& str : strs)
        {
            encoded_string += std::to_string(str.length()) + "#" + str;
        }

        return encoded_string;
    }

    // Decodes a single string to a list of strings
    std::vector<std::string> decode(const std::string& s)
    {
        std::vector<std::string> decoded_string;
        size_t i = 0;
        while (i < s.length())
        {
            size_t j = s.find('#', i);
            size_t length = std::stoi(s.substr(i, j));
            i = j + 1;
            decoded_string.push_back(s.substr(i, length));
            i += length;
        }

        return decoded_string;
    }
};

int main()
{
    Codec codec;
    std::vector<std::string> strs = {"Hello", "World", "This", "is", "a", "test"};
    
    std::string encoded_string = codec.encode(strs);
    std::vector<std::string> decoded_strings = codec.decode(encoded_string);

    std::cout << "Encoded: " << encoded_string << std::endl;
    std::cout << "Decoded: ";
    for (const std::string& str : decoded_strings) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}