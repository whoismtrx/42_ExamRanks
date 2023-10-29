/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:54:20 by orekabe           #+#    #+#             */
/*   Updated: 2023/10/29 20:54:21 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class   ASpell;

class   ATarget
{
    protected:
        std::string _type;
    public:
        ATarget(std::string type);
        virtual ~ATarget();
        const std::string &getType() const;
        virtual ATarget *clone() const = 0;
        void    getHitBySpell(const ASpell &obj) const;
};

#endif