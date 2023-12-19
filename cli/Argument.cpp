#include "Argument.hpp"

std::map<std::string, ArgumentType> Argument::argumentTypeMap = {
    {"-name", ArgumentType::STRING},
    {"-content",ArgumentType::STRING},
    {"-size",ArgumentType::INT},
    {"-color",ArgumentType::STRING},
    {"-style",ArgumentType::STRING},
    {"-w",ArgumentType::INT},
    {"-id", ArgumentType::INT},
    {"-x1", ArgumentType::DOUBLE},
    {"-y1", ArgumentType::DOUBLE},
    {"-x2", ArgumentType::DOUBLE},
    {"-y2", ArgumentType::DOUBLE},
    {"-x3", ArgumentType::DOUBLE},
    {"-y3", ArgumentType::DOUBLE},
};

Argument::iterator Argument::begin() {
    return m_arguments.begin();
}

Argument::iterator Argument::end() {
    return m_arguments.end();
}

Argument::const_iterator Argument::begin() const {
    return m_arguments.begin();
}

Argument::const_iterator Argument::end() const {
    return m_arguments.end();
}