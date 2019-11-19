#pragma once

#include <vector>
#include <string>
#include "Token.h"
#include <iostream>
#include <cassert>

enum OperatorType {
	NOP, NEGATION, COMPLEMENT, LOGICAL_NOT
};

enum ExpressionType {
	CONSTANT, UNARY_OP
};

class ExpressionNode {
        public:
                ExpressionNode(Token tok);
		ExpressionNode(std::vector<Token> toks);
		~ExpressionNode();
                int num;
		OperatorType type;
		ExpressionNode *exp;
};

enum StatementType {
	RETURN
};

class StatementNode {
        public:
                StatementNode(StatementType _type, ExpressionNode *_exp);
                ~StatementNode();
                ExpressionNode *exp;
		StatementType type;
};

class FunctionNode {
        public:
                FunctionNode(std::string _return_type, std::string _identifier, std::vector<StatementNode*> &_body);
                ~FunctionNode();

                std::string return_type;
                std::string identifier;
                std::vector<StatementNode*> body;
};

class ProgramNode {
	public:
		ProgramNode();
		~ProgramNode();
		FunctionNode *main;
};

std::ostream & operator<<(std::ostream &os, ProgramNode &prg);
std::ostream & operator<<(std::ostream &os, FunctionNode &func);
std::ostream & operator<<(std::ostream &os, StatementNode &st);
std::ostream & operator<<(std::ostream &os, ExpressionNode &exp);

