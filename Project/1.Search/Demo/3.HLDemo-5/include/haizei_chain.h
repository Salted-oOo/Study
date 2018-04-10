/*************************************************************************
	> File Name: program_master.h
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 日 12/ 3 01:26:02 2017
 ************************************************************************/

#ifndef _HL_CHAIN_H
#define _HL_CHAIN_H

#include "hlLexer.h"
#include "hlParser.h"
#include <cassert>
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>
#include "haizei_parameters.h"
#include "haizei_interface.h"

using std::map;
using std::string;
using std::cout;
using std::runtime_error;

namespace HL {

class MasterChain {
public :
    static MasterChain *get() {
        if (MasterChain::single) return MasterChain::single;
        MasterChain::single = new MasterChain();
        return MasterChain::single;
    }
    static void destroy() {
        if (MasterChain::single == nullptr) return ;
        MasterChain::get()->~MasterChain();
        MasterChain::single = nullptr;
    }
    shared_ptr<IValue> valid(pANTLR3_BASE_TREE, shared_ptr<Parameters> );
private:
    static MasterChain *single;
    MasterChain();
    ~MasterChain();
    IFactory *p;
};

} // end of namespace HL
#endif
