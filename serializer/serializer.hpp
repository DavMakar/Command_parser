#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "../document/idocument.hpp"
#include "../command_factories/commandFactory.hpp"

class Serializer{
public:
    void save(IDocument& doc, const std::string& filename);
    void load(IDocument& doc, const std::string& filename);
private:
    std::unique_ptr<CommandFactory> selectFactory(const std::string& arg);
};


#endif //SERIALIZER_HPP