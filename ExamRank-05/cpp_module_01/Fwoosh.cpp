#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{
}

Fwoosh::~Fwoosh()
{
}

Fwoosh  *Fwoosh::clone() const
{
    Fwoosh *obj = new Fwoosh;
    return (obj);
}