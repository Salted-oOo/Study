/*************************************************************************
	> File Name: program_master.h
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 日 12/ 3 01:26:02 2017
 ************************************************************************/

#ifndef _HZ_PARAMETERS_H
#define _HZ_PARAMETERS_H

#include "hlLexer.h"
#include "hlParser.h"
#include <cassert>
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>
#include <memory>
#include "haizei_interface.h"

using std::string;
using std::map;
using std::shared_ptr;

namespace HL {

class IValue;
class IDFANode;

class Parameters {
public :
    Parameters() : next(nullptr) {}
    Parameters(shared_ptr<Parameters> &next) : next(next) {}
    shared_ptr<IValue> getVal(string);
    shared_ptr<IValue> setVal(string, shared_ptr<IValue> );
    bool addVar(string);
    shared_ptr<Parameters> next;
    IDFANode *checkpoint;

private:
    map<string, shared_ptr<IValue> > memory;
};

} // end of namespace HL

#endif
