#include "item.hpp"

int Item::counter = 0;


Item::Item():id_(++counter)
{
}

int Item::getId()
{
    return id_;
}

Item::~Item()
{
}

// void Item::init(std::vector<std::string>& arguments)
// {
//     validateArgumnts(arguments);
//     for(size_t i = 0; i < arguments.size(); i+=2){
//         if(arguments[i] == "-w"){
//             setWidth(std::stod(arguments[i+1]));
//         }
//         if(arguments[i] == "-h"){
//             setHeight(std::stod(arguments[i+1]));
//         }
//     }   
// }

// void Item::validateArgumnts(std::vector<std::string> & arguments)
// {
//     if(arguments.size() % 2 != 0){
//         throw std::runtime_error("few arguments");
//     }

//     for (size_t i = 0; i < arguments.size(); i += 2) {
//         auto& arg = arguments[i];

//         if (validArgs.find(arg) == validArgs.end()) {
//             throw std::runtime_error("invalid argumnet " + arg );
//         }
//     }
// }

// void Item::setWidth(double w)
// {
//     width = w;
// }

// void Item::setHeight(double h)
// {
//     height = h;
// }

// std::unique_ptr<Item> Item::createItem(Iterator argsBegin, Iterator argsEnd , &argumnets)
// {
//     auto newItem = std::make_unique<Item>();
//     newItem->init();
// }

