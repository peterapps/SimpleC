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

StatementNode::StatementNode(StatementType _type, ExpressionNode *_exp) : exp(_exp), type(_type) {

}

StatementNode::~StatementNode(){
	delete exp;
}

ExpressionNode::ExpressionNode(Token tok) : num(tok.intval), type(NOP), exp(nullptr) {
}

ExpressionNode::ExpressionNode(vector<Token> toks) {
	Token tok = toks.front();
	assert(tok.type == PUNC);
	switch(tok.charval) {
		case '-':
			type = NEGATION;
			break;
		case '~':
			type = COMPLEMENT;
			break;
		case '!':
			type = LOGICAL_NOT;
			break;
		default:
			cout << "Unknown operator " << tok.charval << endl;
			assert(false);
			break;
	}
	toks.erase(toks.begin());
	if (toks.size() > 1){
		exp = new ExpressionNode(toks);
	} else {
		assert(toks.front().type == INTLIT);
		exp = new ExpressionNode(toks.front());
	}
}

ExpressionNode::~ExpressionNode(){
	if (exp) delete exp;
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
	os << "      RETURN ( " << *(st.exp) << ")";
	return os;	
}

ostream &operator<<(ostream &os, ExpressionNode &exp){
	if (!exp.exp) os << "Int<" << exp.num << "> ";
	else {
		switch(exp.type){
			case NEGATION:
				os << "NEGATION ";
				break;
			case COMPLEMENT:
				os << "COMPLEMENT ";
				break;
			case LOGICAL_NOT:
				os << "LOGICAL_NOT ";
				break;
			default:
				os << "NOP ";
				break;
		}
		os << *(exp.exp);
	}
	return os;
}
