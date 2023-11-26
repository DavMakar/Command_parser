#include "tokenizer.hpp"
#include <QStringList>

std::vector<std::string> Tokenizer::splitInput(const QString& input)
{
    QStringList qTokenList = input.split(" ");
    TokenVector tokens;
    for(const auto& qToken : qTokenList){
        tokens.push_back(qToken.toStdString());
    }

    return tokens;
}

