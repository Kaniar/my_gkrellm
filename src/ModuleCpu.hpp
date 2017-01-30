//
// ModuleCpu.hpp for rush3 in /home/alexandre/piscinetek2/cpp_gkrellm
// 
// Made by Alexandre BARA
// Login   <alexandre@epitech.net>
// 
// Started on Sat Jan 21 16:32:50 2017 Alexandre BARA
// Last update Sat Jan 21 16:32:53 2017 Alexandre BARA
//

#ifndef MODULECPU_HPP_
# define MODULECPU_HPP_

#include "IMonitorModule.hpp"

class	ModuleCpu : public IMonitorModule
{
private:
    std::string name;
    std::vector<std::string>	data;

    bool        isOpen;
    std::vector<int>    total;
    std::vector<int>    working;
    std::vector<float>  percent;
    int nb;
public:
    ModuleCpu(const ModuleCpu &other);
    ModuleCpu();
    ModuleCpu& operator=(const ModuleCpu &other);
    virtual ~ModuleCpu(){};

    void            setIsOpen(bool b);
    bool            getIsOpen()const;
    std::vector<int>  getTotal()const;
    std::vector<int>             getWorking()const;
    std::vector<float>             getPercent()const;
    const std::vector<std::string>&	getData()const;
    int	getNb()const;
};

#endif
