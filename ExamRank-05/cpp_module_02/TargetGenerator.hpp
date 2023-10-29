/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:57:29 by orekabe           #+#    #+#             */
/*   Updated: 2023/10/29 20:57:30 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <map>
#include "ATarget.hpp"

class   TargetGenerator
{
    private:
        std::map<std::string, ATarget*> book;
    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget *obj);
        void forgetTargetType(std::string const &obj);
        ATarget* createTarget(std::string const &obj);
};

#endif