/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:54:05 by orekabe           #+#    #+#             */
/*   Updated: 2023/10/29 20:54:06 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class   Warlock
{
    private:
        std::string _name;
        std::string _title;
    public:
        Warlock(std::string name, std::string title);
        ~Warlock();
        const std::string &getName() const;
        const std::string &getTitle() const;
        void  setTitle(const std::string &title);
        void introduce() const;
};

#endif