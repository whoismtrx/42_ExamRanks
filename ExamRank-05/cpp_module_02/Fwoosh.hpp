#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>
#include "ASpell.hpp"

class   Fwoosh : public ASpell
{
    public:
        Fwoosh();
        ~Fwoosh();
        virtual Fwoosh *clone() const;
};

#endif