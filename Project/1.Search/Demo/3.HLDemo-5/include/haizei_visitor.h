/*************************************************************************
	> File Name: haizei_visitor.h
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 二 12/ 5 19:59:53 2017
 ************************************************************************/

#ifndef _HAIZEI_VISITOR_H
#define _HAIZEI_VISITOR_H

#include <cstdio>
#include "haizei_type.h"
#include "haizei_interface.h"

namespace HL {

class ConvertToStringVisitor : public IValue::IVisitor {
public :
    virtual void Visit(IntValue *obj);
    virtual void Visit(FloatValue *obj);
    virtual void Visit(StringValue *obj);
    virtual void Visit(ArrayValue *obj);
    shared_ptr<StringValue> getResult() { return this->result; }
private :
    shared_ptr<StringValue> result;
};

class ConvertToIntVisitor : public IValue::IVisitor {
public :
    virtual void Visit(IntValue *obj);
    virtual void Visit(FloatValue *obj);
    virtual void Visit(StringValue *obj);
    virtual void Visit(ArrayValue *obj);
    shared_ptr<IntValue> getResult() { return this->result; }
private :
    shared_ptr<IntValue> result;
};

class ConvertToFloatVisitor : public IValue::IVisitor {
public :
    virtual void Visit(IntValue *obj);
    virtual void Visit(FloatValue *obj);
    virtual void Visit(StringValue *obj);
    virtual void Visit(ArrayValue *obj);
    shared_ptr<FloatValue> getResult() { return this->result; }
private :
    shared_ptr<FloatValue> result;
};

class ConvertToArrayVisitor : public IValue::IVisitor {
public :
    virtual void Visit(IntValue *obj);
    virtual void Visit(FloatValue *obj);
    virtual void Visit(StringValue *obj);
    virtual void Visit(ArrayValue *obj);
    shared_ptr<ArrayValue> getResult() { return this->result; }

private :
    shared_ptr<ArrayValue> result;
};

class PrintValueVisitor : public IValue::IVisitor {
public :
    virtual void Visit(IntValue *obj);
    virtual void Visit(FloatValue *obj);
    virtual void Visit(StringValue *obj);
    virtual void Visit(ArrayValue *obj);
};

} // end of namespace HL

#endif
