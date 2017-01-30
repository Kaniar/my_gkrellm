//
// ModuleOS.hpp for rush3 in /home/alexandre/piscinetek2/cpp_gkrellm
// 
// Made by Alexandre BARA
// Login   <alexandre@epitech.net>
// 
// Started on Sat Jan 21 10:09:23 2017 Alexandre BARA
// Last update Sat Jan 21 10:09:24 2017 Alexandre BARA
//

#ifndef MODULEOS_HPP_
#define MODULEOS_HPP_
#include "IMonitorModule.hpp"

class   ModuleOS  : public IMonitorModule
{
private:
    std::string name;
    std::vector<std::string> data;
    bool        isOpen;
public:
    ModuleOS();
    ModuleOS(const ModuleOS& other);
    ModuleOS& operator=(const ModuleOS& other);
    ~ModuleOS(){};

    void            setIsOpen(bool b);
    bool            getIsOpen()const;
    const std::vector<std::string>&    getData()const;
};

#endif