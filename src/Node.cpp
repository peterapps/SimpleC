#include "Node.h"

using namespace std;

ProgramNode::ProgramNode() : main(nullptr) {

}

ProgramNode::~ProgramNode(){
	delete main;
}

FunctionNode::FunctionNode(string _return_type, string _identifier, vector<StatementNode*> &_body) : return_type(_return_type), identifier(_identifier), body(_body) {

}

FunctionNode::~FunctionNode(){
	for (auto it = body.begin(); it != body.end(); ++it){
		delete *it;
	}
}

StatementNode::StatementNode(ExpressionNode *_exp) : exp(_exp) {

}

StatementNode::~StatementNode(){
	delete exp;
}

ExpressionNode::ExpressionNode(Token tok) : num(tok.intval) {

}

ostream & operator<<(ostream &os, ProgramNode &prg){
	os << "PROGRAM" << endl;
	os << *(prg.main);
	return os;
}

ostream & operator<<(ostream &os, FunctionNode &func){
	os << "  FUNCTION: Type=" << func.return_type << ", Identifier=" << func.identifier << endl;
	os << "    Body:" << endl;
	for (auto it = func.body.begin(); it != func.body.end(); ++it){
		os << *(*it) << endl;
	}
	return os;
}

ostream & operator<<(ostream &os, StatementNode &st){
	os << "      RETURN " << *(st.exp);
	return os;	
}

ostream &operator<<(ostream &os, ExpressionNode &exp){
	os << "Int<" << exp.num << ">";
	return os;
}
