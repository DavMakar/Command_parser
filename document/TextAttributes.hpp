#ifndef TEXT_ATTRIBUTES_HPP
#define TEXT_ATTRIBUTES_HPP

#include <string>

class TextAttributes{
public:
    TextAttributes() = default;
    TextAttributes(const std::string& text, int m_size);
    std::string getText() const;
    int getSize() const;
    

private:
    std::string m_text = "";
    int m_size = 8;
};

#endif //TEXT_ATTRIBUTES_HPP