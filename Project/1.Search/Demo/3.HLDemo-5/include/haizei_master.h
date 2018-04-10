/*************************************************************************
	> File Name: program_master.h
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 日 12/ 3 01:26:02 2017
 ************************************************************************/

#ifndef _HZ_MASTER_H
#define _HZ_MASTER_H

#include "hlLexer.h"
#include "hlParser.h"
#include <cassert>
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

#include "haizei_interface.h"
#include "haizei_debug.h"

namespace HL {

using std::map;
using std::string;
using std::cout;
using std::runtime_error;

class ProgramMaster;
class IFMaster;
class ExprMaster;
class PrintMaster;

class ProgramMaster : public IMaster {
public:
    class IProgramFactory : public IFactory {
    public :
        bool valid(pANTLR3_BASE_TREE);
        IMaster *creator(shared_ptr<Parameters> );
    };
    ProgramMaster() : IMaster(nullptr) {}
    ProgramMaster(shared_ptr<Parameters> param) : IMaster(param) {}
    shared_ptr<IValue> run(pANTLR3_BASE_TREE);
};

class IFMaster : public IMaster {
public:
    class IIFFactory : public IFactory {
    public :
        bool valid(pANTLR3_BASE_TREE);
        IMaster *creator(shared_ptr<Parameters> );
    };  
    IFMaster() : IMaster(nullptr) {}
    IFMaster(shared_ptr<Parameters> param) : IMaster(param) {}
    shared_ptr<IValue> run(pANTLR3_BASE_TREE);
};

class ExprMaster : public IMaster {
public:
    class IExprFactory : public IFactory {
    public :
        bool valid(pANTLR3_BASE_TREE);
        IMaster *creator(shared_ptr<Parameters> );
    };
    ExprMaster() : IMaster(nullptr) {}
    ExprMaster(shared_ptr<Parameters> param) : IMaster(param) {}
    shared_ptr<IValue> run(pANTLR3_BASE_TREE);
};

class PrintMaster : public IMaster {
public:
    class IPrintFactory : public IFactory {
    public :
        bool valid(pANTLR3_BASE_TREE);
        IMaster *creator(shared_ptr<Parameters> );
    };
    PrintMaster() : IMaster(nullptr) {}
    PrintMaster(shared_ptr<Parameters> param) : IMaster(param) {}
    shared_ptr<IValue> run(pANTLR3_BASE_TREE);
};

} // end of namespace HL
#endif
