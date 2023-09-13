#ifndef INPUT_OUTPUT_INTERFACE_HPP
#define INPUT_OUTPUT_INTERFACE_HPP

#include <string_view>


class IOInterface
{
public:
    virtual std::vector<std::string> getInput() = 0;
    virtual void printOutput(std::string_view output) = 0;

    virtual ~IOInterface(){};
};

#endif // INPUT_OUTPUT_INTERFACE_HPP
