#include "Text.hpp"
#include "../serializer/iSerializer.hpp"

Text::Text(){
    m_itemOptions.insert("-content");
    m_itemOptions.insert("-size");
}

std::string Text::type()
{
    return std::string("Text");
}

std::string Text::info()
{
    std::string objInfo = type();
    return objInfo;
}

Item::Item_tag Text::tag()
{
    return Item_tag::TEXT;
}

void Text::accept(iSerializer& vi)
{
    auto text_tag = tag();
    vi.visit(text_tag);
    vi.visit(m_box);
}

void Text::setAttribute(std::string key, std::variant<std::string, double, int> value)
{
    if(key == "-content"){
        m_content = std::get<std::string>(value);
    }
    if(key == "-size"){
        m_size = std::get<int>(value);
    }
}

std::unique_ptr<Item> Text::clone()
{
    return std::make_unique<Text>();
}

int Text::getSize() const
{
    return m_size;
}

std::string Text::getContent() const
{
    return m_content;
}
