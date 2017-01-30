//
// ModuleName.cpp for rush3 in /home/alexandre/piscinetek2/cpp_gkrellm
// 
// Made by Alexandre BARA
// Login   <alexandre@epitech.net>
// 
// Started on Sat Jan 21 10:36:22 2017 Alexandre BARA
// Last update Sat Jan 21 15:57:15 2017 Benjamin Dubois
//

#include <sys/unistd.h>
#include "ModuleName.hpp"
#include <sstream>

ModuleName::ModuleName()
{
    this->name = "Name";
    this->isOpen = true;
    char host[100];
    char user[100];

    std::vector<std::string> vec;
    gethostname(host, sizeof(host));
    std::string str(host);
    vec.push_back(str);
    getlogin_r(user, sizeof(user));
    std::string str2(user);
    vec.push_back(str2);
    this->data = vec;
}

ModuleName::ModuleName(const ModuleName& ot)
{
    this->name = "Name";
    this->isOpen = ot.getIsOpen();
    this->data = ot.getData();
}

ModuleName&     ModuleName::operator=(const ModuleName &ot)
{
    this->name = "Name";
    this->isOpen = ot.getIsOpen();
    this->data == ot.getData();
    return *this;
}

const std::vector<std::string>& ModuleName::getData() const
{
    return this->data;
}

bool ModuleName::getIsOpen() const
{return this->isOpen;}
