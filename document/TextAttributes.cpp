#include "TextAttributes.hpp"

TextAttributes::TextAttributes(const std::string &text, int size)
    :m_text(text) , m_size(size)
{
}

std::string TextAttributes::getText() const
{
    return m_text;
}

int TextAttributes::getSize() const
{
    return m_size;
}
