#pragma once

#include <vector>
#include <iostream>
#include "Token.h"

class Lexer {
	private:
		std::vector<Token> tokens;
		void next_token(std::istream &is, char first);
	public:
		Lexer(std::istream &is);
		std::vector<Token> & get_tokens();
};
