#include "Text.hpp"

Text::Text()
    :location_() ,text_(""),fontSize_(8)
{
}

Text::Text(Point location, std::string text, int fontSize)
    :location_(location) , text_(text) , fontSize_(fontSize)
{
}
