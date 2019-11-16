#pragma once

#include "Token.h"
#include "Node.h"
#include <vector>

class Parser {
	private:
		std::vector<Token> tokens;
		void parse_next(std::vector<Token>::iterator &it);
		StatementNode * parse_statement(std::vector<Token>::iterator &it);
		ProgramNode *prg;
	public:
		Parser(std::vector<Token> _tokens);
		ProgramNode * get_AST();
};
