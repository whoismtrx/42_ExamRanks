/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:57:26 by orekabe           #+#    #+#             */
/*   Updated: 2023/10/29 20:57:27 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
}

void    TargetGenerator::learnTargetType(ATarget *obj)
{
    book[obj->getType()] = obj;
}

void    TargetGenerator::forgetTargetType(std::string const &name)
{
    std::map<std::string, ATarget*>::iterator it = book.find(name);
    if (it != book.end())
        book.erase(name);
}

ATarget    *TargetGenerator::createTarget(std::string const &name)
{
    std::map<std::string, ATarget*>::iterator it = book.find(name);
    if (it != book.end())
        return (it->second->clone());
    return (NULL);
}