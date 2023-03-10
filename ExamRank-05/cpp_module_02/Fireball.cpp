#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{
}

Fireball::~Fireball()
{
}

Fireball  *Fireball::clone() const
{
    Fireball *obj = new Fireball;
    return (obj);
}