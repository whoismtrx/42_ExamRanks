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