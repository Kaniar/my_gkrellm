//
// ModuleRAM.hpp for rush3 in /home/alexandre/piscinetek2/cpp_gkrellm
// 
// Made by Alexandre BARA
// Login   <alexandre@epitech.net>
// 
// Started on Sat Jan 21 12:46:23 2017 Alexandre BARA
// Last update Sat Jan 21 12:46:24 2017 Alexandre BARA
//

#ifndef MODULERAM_HPP_
# define MODULERAM_HPP_

#include "IMonitorModule.hpp"

class	ModuleRam : public IMonitorModule
{
private:
    std::string name;
    std::vector<std::string>	data;
    bool        isOpen;
    int         TotMem;
    int         FreeMem;
    int         BuffMem;
    int         CachedMem;
    int         SwapCachedMem;
    int         UsedMem;
public:
    ModuleRam(const ModuleRam &other);
    ModuleRam();
    ModuleRam& operator=(const ModuleRam &other);
    virtual ~ModuleRam(){};

    void            setIsOpen(bool b);
    bool            getIsOpen()const;
    int             getTotMem()const;
    int             getFreeMem()const;
    int             getBuffMem()const;
    int             getCachedMem()const;
    int             getSwapCachedMem()const;
    int             getUsedMem()const;
    const std::vector<std::string>&	getData()const;
};

#endif
