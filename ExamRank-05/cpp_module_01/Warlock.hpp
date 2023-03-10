#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class   Warlock
{
    private:
        std::string _name;
        std::string _title;
        std::map<std::string, ASpell*> book;
    public:
        Warlock(std::string name, std::string title);
        ~Warlock();
        const   std::string &getName() const;
        const   std::string &getTitle() const;
        void    setTitle(const std::string &title);
        void    introduce() const;
        void    learnSpell(ASpell *obj);
        void    forgetSpell(std::string name);
        void    launchSpell(std::string name, ATarget &obj);
};

#endif