#ifndef INTERFACE_SHAPE_HPP
#define INTERFACE_SHAPE_HPP

#include <memory>

class IShape
{
    virtual std::unique_ptr<IShape> clone() = 0;
};

#endif //INTERFACE_SHAPE_HPP

