/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:54:17 by orekabe           #+#    #+#             */
/*   Updated: 2023/10/29 20:54:18 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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