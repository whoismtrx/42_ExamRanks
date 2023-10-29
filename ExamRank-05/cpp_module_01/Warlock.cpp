/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:54:36 by orekabe           #+#    #+#             */
/*   Updated: 2023/10/29 20:54:37 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title)
{
    _name = name;
    _title = title;
    std::cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!\n";
}

const std::string &Warlock::getName() const
{
    return (_name);
}

const std::string &Warlock::getTitle() const
{
    return (_title);
}

void  Warlock::setTitle(const std::string &title)
{
    _title = title;
}

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

void    Warlock::learnSpell(ASpell *obj)
{
    book[obj->getName()] = obj;
}

void    Warlock::forgetSpell(std::string name)
{
    std::map<std::string, ASpell*>::iterator it = book.find(name);
    if (it != book.end())
        book.erase(name);
}

void    Warlock::launchSpell(std::string name, ATarget &obj)
{
    std::map<std::string, ASpell*>::iterator it = book.find(name);
    if (it != book.end())
        obj.getHitBySpell(*(it->second));
}