#include "Generator.h"

using namespace std;

Generator::Generator(ProgramNode *ast) : prg(ast) {}

void Generator::print(ostream &os) const {
	os << ".globl " << prg->main->identifier << endl;
	os << prg->main->identifier << ":" << endl;
	for (auto it = prg->main->body.begin(); it != prg->main->body.end(); ++it){
		StatementNode *st = *it;
		assert(st->type == RETURN);
		vector<ExpressionNode*> exps;
		ExpressionNode *temp = st->exp;
		while (temp->exp){
			exps.push_back(temp);
			temp = temp->exp;
		}
		int num = temp->num;
		os << "    movl    $" << num << ", %eax" << endl;
		for (auto rit = exps.rbegin(); rit != exps.rend(); ++rit){
			assert((*rit)->type != NOP);
			switch ((*rit)->type){
				case NEGATION:
					os << "    neg     %eax" << endl;
					break;
				case COMPLEMENT:
					os << "    not     %eax" << endl;
					break;
				case LOGICAL_NOT:
					os << "    cmpl    $0, %eax" << endl;
					os << "    movl    $0, %eax" << endl;
					os << "    sete    %al" << endl;
					break;
				default:
					cout << "Parser does not understand that operation" << endl;
					break;
			}
		}
		os << "    ret" << endl;
	}
}

ostream & operator<<(ostream &os, const Generator &gen){
	gen.print(os);
	return os;
}
