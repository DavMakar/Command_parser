#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <vector>
#include <QString>

using Token = std::string;
using TokenVector = std::vector<Token>;

class Tokenizer
{
public:
    TokenVector splitInput(const QString& input);
};

#endif // TOKENIZER_HPP
