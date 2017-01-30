//
// ModuleTime.hpp for rush3 in /home/alexandre/piscinetek2/cpp_gkrellm
// 
// Made by Alexandre BARA
// Login   <alexandre@epitech.net>
// 
// Started on Sat Jan 21 10:04:20 2017 Alexandre BARA
// Last update Sat Jan 21 10:04:27 2017 Alexandre BARA
//

#ifndef MODULETIME_HPP_
# define MODULETIME_HPP_

#include "IMonitorModule.hpp"

class   ModuleTime : public IMonitorModule
{
private:
    std::string name;
    std::vector<std::string> data;
    bool        isOpen;
public:
    ModuleTime();
    ModuleTime(const ModuleTime&other);
    ModuleTime& operator=(const ModuleTime&other);
    virtual ~ModuleTime(){};

    void        setIsOpen(bool b);
    bool        getIsOpen()const;
    const std::vector<std::string>& getData()const;
};

#endif