#include "Lexer.h"
#include <string>
#include <cassert>

using namespace std;

bool is_punc(char c){
	string valids = "{}();-~!+*/";
	for (size_t i = 0; i < valids.length(); ++i){
		if (c == valids[i]) return true;
	}
	return false;
}

bool is_digit(char c){
	return c >= '0' && c <= '9';
}

bool is_alpha_und(char c){
	return (c == '_') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_alphanum(char c){
	return is_alpha_und(c) || is_digit(c);
}

void Lexer::next_token(istream &is, char first){
	// Skip whitespace
	if (isspace(first)) return;
	// Create token for matching
	Token t;
	// Match punctuation
	if (is_punc(first)){
		t.type = PUNC;
		t.charval = first;
	}
	// Match integer literal
	else if (isdigit(first)){
		char temp;
		string str(1, first);
		while (is.get(temp) && is_digit(temp)){
			str += temp;
		}
		is.unget();
		t.type = INTLIT;
		int value = stoi(str);
		t.intval = value;
	}
	// Match identifier or keyword
	else if (is_alpha_und(first)){
		// Keywords will appear to identifiers at first because only the first character is seen
		string str(1, first);
		char temp;
		while (is.get(temp) && is_alphanum(temp)){
			str += temp;
		}
		is.unget();
		// Keyword
		if (str == "int" || str == "return"){
			t.type = KEYWORD;
		}
		// Identifier
		else {
			t.type = IDENTIFIER;
		}
		t.strval = str;
	} else {
		cout << "Unknown token" << endl;
		assert(false);
	}
	// Append token to list
	tokens.push_back(t);
}

Lexer::Lexer(istream &is) {
	char c;
	while (is.get(c)){
		next_token(is, c);
	}
}

vector<Token> & Lexer::get_tokens(){
	return tokens;
}
