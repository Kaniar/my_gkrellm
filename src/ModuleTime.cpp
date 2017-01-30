//
// ModuleTime.cpp for rush3 in /home/alexandre/piscinetek2/cpp_gkrellm
// 
// Made by Alexandre BARA
// Login   <alexandre@epitech.net>
// 
// Started on Sat Jan 21 10:36:14 2017 Alexandre BARA
// Last update Sat Jan 21 10:36:14 2017 Alexandre BARA
//

//
// ModuleOS.cpp for rush3 in /home/alexandre/piscinetek2/cpp_gkrellm
//
// Made by Alexandre BARA
// Login   <alexandre@epitech.net>
//
// Started on Sat Jan 21 10:36:05 2017 Alexandre BARA
// Last update Sat Jan 21 10:36:06 2017 Alexandre BARA
//

#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "ModuleTime.hpp"

ModuleTime::ModuleTime()
{
    this->isOpen = true;
    this->name = "OS";

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream os;
    os << std::put_time(&tm, "%d-%m-%Y %Hh-%Mm-%Ss");
    std::vector<std::string> vec;
    vec.push_back(os.str());
    this->data = vec;
}

ModuleTime::ModuleTime(const ModuleTime& ot)
{
    this->name = "OS";
    this->isOpen = ot.getIsOpen();
    this->data = ot.getData();
}

ModuleTime&     ModuleTime::operator=(const ModuleTime &ot)
{
    this->name = "OS";
    this->isOpen = ot.getIsOpen();
    this->data == ot.getData();
    return *this;
}

const std::vector<std::string>& ModuleTime::getData() const
{
    return this->data;
}

bool ModuleTime::getIsOpen() const
{return this->isOpen;}
