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
