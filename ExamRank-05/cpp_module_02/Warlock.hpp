/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:57:34 by orekabe           #+#    #+#             */
/*   Updated: 2023/10/29 20:57:35 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class   Warlock
{
    private:
        std::string _name;
        std::string _title;
        SpellBook   sbook;
    public:
        Warlock(std::string name, std::string title);
        ~Warlock();
        const   std::string &getName() const;
        const   std::string &getTitle() const;
        void    setTitle(const std::string &title);
        void    introduce() const;
        void    learnSpell(ASpell *obj);
        void    forgetSpell(std::string name);
        void    launchSpell(std::string name, ATarget &obj);
};

#endif