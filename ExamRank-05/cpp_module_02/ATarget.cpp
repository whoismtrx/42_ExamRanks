#include "ATarget.hpp"

ATarget::ATarget(std::string type)
{
    _type = type;
}

ATarget::~ATarget()
{
}

const std::string &ATarget::getType() const
{
    return (_type);
}

void    ATarget::getHitBySpell(const ASpell &obj) const
{
    std::cout << _type << " has been " << obj.getEffects() << "!\n";
}