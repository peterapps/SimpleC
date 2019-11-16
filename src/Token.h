#pragma once

#include <string>
#include <iostream>

enum TokenType {
	NONE,
	PUNC,
	KEYWORD,
	INTLIT,
	IDENTIFIER
};

struct Token {
	enum TokenType type;
	int intval;
	std::string strval;
	char charval;

	Token();
	Token(TokenType typ);
	Token(TokenType typ, int val);
	Token(TokenType typ, std::string val);
	Token(TokenType typ, char val);
	bool operator==(const Token &rhs) const;
};

std::ostream & operator<<(std::ostream &os, const Token &t);
