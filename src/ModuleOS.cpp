//
// ModuleOS.cpp for rush3 in /home/alexandre/piscinetek2/cpp_gkrellm
// 
// Made by Alexandre BARA
// Login   <alexandre@epitech.net>
// 
// Started on Sat Jan 21 10:36:05 2017 Alexandre BARA
// Last update Sat Jan 21 10:36:06 2017 Alexandre BARA
//

#include <sys/utsname.h>
#include "ModuleOS.hpp"

ModuleOS::ModuleOS()
{
    this->isOpen = true;
    this->name = "OS";

    struct utsname buf;
    uname(&buf);
    std::string OsName(buf.sysname);
    std::vector<std::string> vec;
    vec.push_back(OsName);
    std::string OsV(buf.release);
    vec.push_back(OsV);
    this->data = vec;
}

ModuleOS::ModuleOS(const ModuleOS& ot)
{
    this->name = "OS";
    this->isOpen = ot.getIsOpen();
    this->data = ot.getData();
}

ModuleOS&     ModuleOS::operator=(const ModuleOS &ot)
{
    this->name = "OS";
    this->isOpen = ot.getIsOpen();
    this->data == ot.getData();
    return *this;
}

const std::vector<std::string>& ModuleOS::getData() const
{
    return this->data;
}

bool ModuleOS::getIsOpen() const
{return this->isOpen;}
