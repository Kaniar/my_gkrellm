//
// ModuleName.hpp for rush3 in /home/alexandre/piscinetek2/cpp_gkrellm
// 
// Made by Alexandre BARA
// Login   <alexandre@epitech.net>
// 
// Started on Sat Jan 21 09:49:32 2017 Alexandre BARA
// Last update Sat Jan 21 09:54:37 2017 Alexandre BARA
//

#ifndef MODULENAME_HPP_
# define MODULENAME_HPP_

#include "IMonitorModule.hpp"

class	ModuleName : public IMonitorModule
{
private:
    std::string name;
    std::vector<std::string>	data;
    bool        isOpen;
public:
    ModuleName(const ModuleName&other);
    ModuleName();
    ModuleName& operator=(const ModuleName &other);
    virtual ~ModuleName(){};

    void            setIsOpen(bool b);
    bool            getIsOpen()const;
    const std::vector<std::string>&	getData()const;
};

#endif 
