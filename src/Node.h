#pragma once

#include <vector>
#include <string>
#include "Token.h"

class ExpressionNode {
        public:
                ExpressionNode(Token tok);
                int num;
};

class StatementNode {
        public:
                StatementNode(ExpressionNode *_exp);
                ~StatementNode();
                ExpressionNode *exp;
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
