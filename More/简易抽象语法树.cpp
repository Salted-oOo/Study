/*
* @Author: alivedreams
* @Date:   2017-10-24 17:53:08
* @Last Modified by:   alivedreams
* @Last Modified time: 2017-10-27 17:12:38
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <memory>
using namespace std;

enum class BinaryOpt {
	PLUS,
	MINUS,
	MUTIL,
	DIVIDE
};

class BinaryExpr;
class NumberExpr;

class Expr {
public:
	class IVisitor {
	public:
		virtual void Visit(BinaryExpr *) = 0;
		virtual void Visit(NumberExpr *) = 0;		
	};
	//Expr() = delete;
	virtual void Accept(IVisitor *) = 0;
	virtual ~Expr() = 0;
};
Expr::~Expr() {}

class BinaryExpr : public Expr{
public:
	BinaryExpr(Expr *first, BinaryOpt Op, Expr *second):
		first(first), second(second), Op(Op) {}
	virtual void Accept(IVisitor *visitor) {
		visitor->Visit(this);
	}
	std::shared_ptr<Expr> GetFirst() {return first;}
	std::shared_ptr<Expr> GetSecond() {return second;}
	BinaryOpt GetOp() {return Op;}
	virtual ~BinaryExpr() {}
private:
	std::shared_ptr<Expr> first;
	std::shared_ptr<Expr> second;
	BinaryOpt Op;
};

class NumberExpr : public Expr{
public:
	NumberExpr(int Value) : Value(Value) {}
	virtual void Accept(IVisitor *visitor) {
		visitor->Visit(this);
	}
	int GetValue() {return Value;}
	virtual ~NumberExpr() {}
private:
	int Value;

};

BinaryOpt CharToOpt(char ch) {
	switch (ch) {
		case '+' :
			return BinaryOpt::PLUS;
		case '-' :
			return BinaryOpt::MINUS;
		case '*' :
			return BinaryOpt::MUTIL;
		case '/' :
			return BinaryOpt::DIVIDE;
	}
	return BinaryOpt::PLUS;
}

Expr *__Parser(const char *&Read) {
	if (Read[0] == '(') {
		Read++;
		BinaryOpt Op = CharToOpt(Read[0]);
		Read++;
		while (Read[0] == ' ') Read++;
		Expr *first = __Parser(Read);
		while (Read[0] == ' ') Read++;
		Expr *second = __Parser(Read);
		Read++;
		return new BinaryExpr(first, Op, second); 
	} else {
		int num = 0;
		while (Read[0] != ' ' && Read[0] != ')') {
			num = num * 10 + (Read[0] - '0');
			Read++;
		}
		//cout << num << endl;
		return new NumberExpr(num);
	}
}

Expr *Parser(const char *Read) {

	return __Parser(Read);
}

class CalcNumber : public Expr::IVisitor {
public:
	int result;
	virtual void Visit(BinaryExpr *node) {
		CalcNumber firstV, secondV;
		node->GetFirst()->Accept(&firstV);
		node->GetSecond()->Accept(&secondV);
		switch (node->GetOp()) {
			case BinaryOpt::PLUS :
				this->result = firstV.result + secondV.result;
				break;
			case BinaryOpt::MINUS :
				this->result = firstV.result - secondV.result;
				break;
			case BinaryOpt::MUTIL :
				this->result = firstV.result * secondV.result;
				break;
			case BinaryOpt::DIVIDE :
				this->result = firstV.result / secondV.result;
				break;
		}
	}
	virtual void Visit(NumberExpr *node) {
		this->result = node->GetValue();
	}
};

class TransToString : public Expr::IVisitor {
public:
	TransToString() : result(""), tip("") {}
	void SetTip(std::string tip) {
		this->tip = tip;
	}
	static int OptToLevel(BinaryOpt Op) {
		switch (Op) {
			case BinaryOpt::PLUS:
			case BinaryOpt::MINUS:
				return 0;
			default :
				return 1;
		}
	}
	static string GetOptChar(BinaryOpt Op) {
		switch (Op) {
			case BinaryOpt::PLUS: return "+";
			case BinaryOpt::MINUS: return "-";
			case BinaryOpt::MUTIL: return "*";
			case BinaryOpt:: DIVIDE: return "/";
			default :
				break;
		}
		return "+";
	}

	std::string result;
	std::string tip;
	int level;
	
	virtual void Visit(BinaryExpr *node) {
		TransToString firstV, secondV;
		node->GetFirst()->Accept(&firstV);
		node->GetSecond()->Accept(&secondV);
		this->level = TransToString::OptToLevel(node->GetOp());
		if (firstV.level < this->level) {
			firstV.result = "(" + firstV.result + ")" ;
		}
		if (secondV.level < this->level) {
			secondV.result = "(" + secondV.result + ")" ;
		}
		if (node->GetOp() == BinaryOpt::MINUS || 
			node->GetOp() == BinaryOpt::DIVIDE) {
			if (secondV.level == this->level) {
				secondV.result = "(" + secondV.result + ")" ;
			}
		}
		this->result = this->tip + 
					   firstV.result + 
					   TransToString::GetOptChar(node->GetOp()) +
					   secondV.result;

	}

	virtual void Visit(NumberExpr *node) {
		this->result = "";
		int num = node->GetValue();
		do {
			this->result = static_cast<char>(num % 10 + '0') + this->result;
			num /= 10;
		}while (num);
		this->level = 2;
	}

};


int main() {
	std::shared_ptr<Expr> root(Parser("(* (+ 1 2) (- 4 5))"));
	CalcNumber ret;
	TransToString ret2;
	ret2.SetTip("output : ");
	root->Accept(&ret);
	root->Accept(&ret2);
	cout << ret.result << endl;
	//cout << ret2.result << " EQUAL TO "<< ret.result << endl;
	cout << ret2.result << endl;
	return 0;
}

