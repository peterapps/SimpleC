#include "Token.h"

using namespace std;

Token::Token() : type(NONE) {}

Token::Token(TokenType typ) : type(typ) {}

Token::Token(TokenType typ, int val) : type(typ), intval(val) {}

Token::Token(TokenType typ, string val) : type(typ), strval(val) {}

Token::Token(TokenType typ, char val) : type(typ), charval(val) {}

bool Token::operator==(const Token &rhs) const {
	if (type != rhs.type) return false;
	if (type == PUNC) return charval == rhs.charval;
	else if (type == KEYWORD || type == IDENTIFIER) return strval == rhs.strval;
	else if (type == INTLIT) return intval == rhs.intval;
	else return true;
}

ostream & operator<<(ostream &os, const Token &t){
        os << "Token(";
        switch (t.type){
                case NONE:
                        os << "NONE";
                        break;
                case PUNC:
                        os << "PUNC, '" << t.charval << '\'';
                        break;
                case KEYWORD:
                        os << "KEYWORD, \"" << t.strval << '"';
                        break;
                case INTLIT:
                        os << "INTLIT, " << t.intval;
                        break;
                case IDENTIFIER:
                        os << "IDENTIFIER, \"" << t.strval << '"';
                        break;
                default:
                        os << "UNKNOWN";
                        break;
        }
        os << ")";
        return os;
}

