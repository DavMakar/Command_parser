#include "Text.hpp"
#include "../serializer/iSerializer.hpp"

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
        content = std::get<std::string>(value);
    }
}

std::unique_ptr<Item> Text::clone()
{
    return std::make_unique<Text>();
}

std::string Text::getContent()
{
    return content;
}
