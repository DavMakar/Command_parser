#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <memory>

class Item
{ 
public:
    Item();
    virtual ~Item();
    int getId();
    template<typename It>
    void init(It begin , It end);

    virtual std::string info() = 0;
    virtual std::string getAttrbute(std::string key) = 0;
    virtual void setAttribute(std::string key , std::string value) = 0;
    virtual std::unique_ptr<Item> clone() = 0;  
private:
    int id_;
    static int counter;

protected:
    std::unordered_map<std::string, std::string> attributes_;
    std::unordered_set<std::string> validArguments;
};

template <typename It>
void Item::init(It begin, It end)
{
    if(std::distance(begin, end) % 2 != 0){
        throw std::runtime_error("few argumnets");
    }
    for(auto it = begin ; it != end ; it+=2){
        if(validArguments.find(*it) == validArguments.end()){
            throw std::runtime_error("invalid argumnet " + *it);
        }
        setAttribute(*it, *std::next(it));
    }
}
#endif //ITEM_HPP