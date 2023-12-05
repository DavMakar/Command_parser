#include "Argument.hpp"

Argument::iterator Argument::begin()
{
    return m_arguments.begin();
}

Argument::iterator Argument::end()
{
    return m_arguments.end();
}

Argument::const_iterator Argument::begin() const
{
    return const_iterator(m_arguments.begin());
}
Argument::const_iterator Argument::end() const
{
    return const_iterator(m_arguments.end());
}

