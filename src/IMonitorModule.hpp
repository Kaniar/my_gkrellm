//
// IMonitorModule.hpp for rush3 in /home/alexandre/piscinetek2/cpp_gkrellm
// 
// Made by Alexandre BARA
// Login   <alexandre@epitech.net>
// 
// Started on Sat Jan 21 09:45:56 2017 Alexandre BARA
// Last update Sat Jan 21 09:50:35 2017 Alexandre BARA
//

#ifndef IMONITORMODULE_HPP_
# define IMONITORMODULE_HPP_

#include <vector>
#include <string>

class	IMonitorModule
{
public:
    virtual ~IMonitorModule(){};
    virtual const std::vector<std::string>& getData()const = 0;
    virtual bool getIsOpen()const = 0;
};

#endif
