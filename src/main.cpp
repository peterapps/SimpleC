#include "Lexer.h"
#include "Parser.h"
#include <fstream>
#include <vector>

using namespace std;

int main(){
	ifstream in_file("return_2.c");
	Lexer lex(in_file);
	vector<Token> tokens = lex.get_tokens();
	cout << "Lexer output:" << endl;
	for (auto it = tokens.begin(); it != tokens.end(); ++it){
		cout << *it << endl;
	}
	cout << endl;

	Parser parser(tokens);
	cout << "Parser output:" << endl;
	ProgramNode *prg = parser.get_AST();
	cout << "Program" << endl;
	FunctionNode *main = prg->main;
	cout << "  Function: type=" << main->return_type;
	cout << ", identifier=" << main->identifier << endl;
	for (size_t i = 0; i < main->body.size(); ++i){
		StatementNode *st = main->body[i];
		cout << "    Statement: Expression(";
		cout << st->exp->num;
		cout << ")" << endl;
	}
}
