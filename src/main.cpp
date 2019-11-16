#include "Lexer.h"
#include "Parser.h"
#include "Generator.h"
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
	if (argc != 2 && argc != 3 && argc != 4){
		cout << "Usage: ./simplec input_file.c [output_file.s] [-v]" << endl;
	}
	bool verbose = (argc == 4) && (string(argv[3]) == "-v");

	ifstream in_file(argv[1]);
	Lexer lex(in_file);
	vector<Token> tokens = lex.get_tokens();

	if (verbose){
		cout << "----- Lexer output -----" << endl;
		for (auto it = tokens.begin(); it != tokens.end(); ++it){
			cout << *it << endl;
		}
		cout << endl;
	}

	Parser parser(tokens);
	ProgramNode *prg = parser.get_AST();
	
	if (verbose){
		cout << "----- Parser output -----" << endl;
		cout << *prg << endl;
	}

	Generator gen(prg);
	
	if (verbose){
		cout << "----- Generator output -----" << endl;
		cout << gen << endl;
	}

	if (argc == 2){
		cout << gen << endl;
	} else {
		ofstream out_file(argv[2]);
		out_file << gen << endl;
	}
}
