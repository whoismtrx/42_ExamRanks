/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:54:12 by orekabe           #+#    #+#             */
/*   Updated: 2023/10/29 20:54:13 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects)
{
    _name = name;
    _effects = effects;
}

ASpell::~ASpell()
{
}

const std::string &ASpell::getName() const
{
    return (_name);
}

const std::string &ASpell::getEffects() const
{
    return (_effects);
}

void    ASpell::launch(const ATarget &obj) const
{
    obj.getHitBySpell(*this);
}