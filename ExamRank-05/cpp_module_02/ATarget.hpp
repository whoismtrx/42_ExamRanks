#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class   ASpell;

class   ATarget
{
    protected:
        std::string _type;
    public:
        ATarget(std::string type);
        virtual ~ATarget();
        const std::string &getType() const;
        virtual ATarget *clone() const = 0;
        void    getHitBySpell(const ASpell &obj) const;
};

#endif