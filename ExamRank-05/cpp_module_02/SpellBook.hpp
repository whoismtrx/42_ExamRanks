/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:57:23 by orekabe           #+#    #+#             */
/*   Updated: 2023/10/29 20:57:24 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

class   SpellBook
{
    private:
        std::map<std::string, ASpell*> book;
    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell *obj);
        void forgetSpell(std::string const &obj);
        ASpell* createSpell(std::string const &obj);
};

#endif