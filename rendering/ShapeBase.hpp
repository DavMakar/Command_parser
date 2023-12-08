#ifndef SHAPE_BASE_HPP
#define SHAPE_BASE_HPP

#include "IShape.hpp"
#include "ITextualDisplayable.hpp"

class ShapeBase : public IShape , public ITextualDisplayable{
public:
    std::unique_ptr<IShape> clone();
    void print(std::shared_ptr<Item> item) override;
};

#endif //SHAPE_BASE_HPP