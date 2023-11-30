#include "CommandArgument.hpp"

CommandArgument::iterator CommandArgument::begin()
{
    return arguments_.begin();
}

CommandArgument::iterator CommandArgument::end()
{
    return arguments_.end();
}

CommandArgument::const_iterator CommandArgument::begin() const
{
    return const_iterator(arguments_.begin());
}
CommandArgument::const_iterator CommandArgument::end() const
{
    return const_iterator(arguments_.end());
}

