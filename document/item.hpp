#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <stdexcept>
#include <variant>

#include "BoundingBox.hpp"
#include "PenStyle.hpp"

class iSerializer;

class Item
{ 
using Options = std::unordered_set<std::string>;
public:
    enum class Item_tag : int { RECT , ELLIPSE, TEXT, CIRCLE};
    virtual ~Item() = default;
    Options getOptions() const ;
    BoundingBox getBoundingBox() const;
    PenStyle getPenStyle() const;

    void setPenStyle(PenStyle penStyle);
    void setOptions(Options options);
    void setBoundingBox(BoundingBox box);

    virtual void accept(iSerializer& vi) = 0;
    virtual std::string type() = 0;
    virtual std::string info() = 0;
    virtual Item_tag tag() = 0;
    virtual void setAttribute(std::string key , std::variant<std::string,double,int> value) = 0;
    virtual std::unique_ptr<Item> clone() = 0;  

protected:
    PenStyle m_penStyle;
    Options m_itemOptions;
    BoundingBox m_box;
};


#endif //ITEM_HPP
