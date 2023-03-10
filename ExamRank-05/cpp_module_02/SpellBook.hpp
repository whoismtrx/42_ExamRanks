#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

class   SpellBook
{
    private:
        std::map<std::string, ASpell*> book;
    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell *obj);
        void forgetSpell(std::string const &obj);
        ASpell* createSpell(std::string const &obj);
};

#endif