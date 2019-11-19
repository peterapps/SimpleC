#include "Parser.h"
#include <cassert>

using namespace std;

Parser::Parser(vector<Token> _tokens) : tokens(_tokens), prg(new ProgramNode()) {
	for (auto it = tokens.begin(); it != tokens.end();){
		parse_next(it);
	}
}

void Parser::parse_next(vector<Token>::iterator &it){
	if ((*it).type == KEYWORD){
		if ((*it).strval == "int"){
			// Next token should be main
			++it;
			assert(*it == Token(IDENTIFIER,"main"));

			++it;
			assert(*it == Token(PUNC,'('));

			// For now assume no function arguments
			++it;
			assert(*it == Token(PUNC,')'));

			++it;
			assert(*it == Token(PUNC,'{'));

			// Parse function body
			++it;
			vector<StatementNode*> body;
			while (!(*it == Token(PUNC,'}'))){
				body.push_back(parse_statement(it));
			}

			// End of function block
			assert(*it == Token(PUNC,'}'));
			++it;

			// Create function node
                        prg->main = new FunctionNode("int", "main", body);
		}
	}
}

StatementNode * Parser::parse_statement(vector<Token>::iterator &it){
	assert(*it == Token(KEYWORD, "return"));
	++it;
	vector<Token> exp_tokens;
	while (!(*it == Token(PUNC, ';'))){
		exp_tokens.push_back(*it);
		++it;
	}
	assert((*exp_tokens.rbegin()).type == INTLIT);
	ExpressionNode *exp = nullptr;
	if (exp_tokens.size() > 1){
		exp = new ExpressionNode(exp_tokens);
	} else if (exp_tokens.size() == 1) {
		exp = new ExpressionNode(exp_tokens.front());
	} else {
		cout << "No expression found" << endl;
		assert(false);
	}
	assert(*it == Token(PUNC, ';'));
	++it;
	return new StatementNode(RETURN, exp);
}

ProgramNode * Parser::get_AST(){
	return prg;
}
