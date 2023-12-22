#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <stdexcept>
#include <variant>

#include "BoundingBox.hpp"
#include "PenAttributes.hpp"
#include "TextAttributes.hpp"

class iSerializer;

class Item
{ 
public:
    enum class Item_tag : int { RECT , ELLIPSE, TEXT, CIRCLE};
    Item() = default;

    Item(Item_tag tag , BoundingBox box , PenAttributes PenAttributes, TextAttributes textAttributes);
    
    int getId();
    TextAttributes getTextAttributes() const ;
    BoundingBox getBoundingBox() const;
    PenAttributes getPenAttributes() const;

    void setPenAttributes(PenAttributes penAttr);
    void setTextAttributes(TextAttributes textAttr);
    void setBoundingBox(BoundingBox box);

    void accept(iSerializer& vi);
    std::string type();
    std::string info();
    Item_tag tag();

protected:
    Item_tag m_tag;
    int m_id;
    static int counter;
    TextAttributes m_textAttributes;
    PenAttributes m_penAttributes;
    BoundingBox m_box;
};


#endif //ITEM_HPP
