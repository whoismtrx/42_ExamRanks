#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
}

void    SpellBook::learnSpell(ASpell *obj)
{
    book[obj->getName()] = obj;
}

void    SpellBook::forgetSpell(std::string const &name)
{
    std::map<std::string, ASpell*>::iterator it = book.find(name);
    if (it != book.end())
        book.erase(name);
}

ASpell    *SpellBook::createSpell(std::string const &name)
{
    std::map<std::string, ASpell*>::iterator it = book.find(name);
    if (it != book.end())
        return (it->second->clone());
    return (NULL);
}