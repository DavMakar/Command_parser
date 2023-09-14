#ifndef INPUT_OUTPUT_INTERFACE_HPP
#define INPUT_OUTPUT_INTERFACE_HPP

#include <string_view>
#include <vector>
#include <string>

class IOInterface
{
public:
    virtual std::vector<std::string> getInput(std::string_view input) = 0;
    virtual void printOutput(std::string_view output) = 0;
    virtual ~IOInterface(){};
};

#endif // INPUT_OUTPUT_INTERFACE_HPP
