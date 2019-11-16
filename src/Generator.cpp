#include "Generator.h"

using namespace std;

Generator::Generator(ProgramNode *ast) : prg(ast) {}

void Generator::print(ostream &os) const {
	os << ".globl " << prg->main->identifier << endl;
	os << prg->main->identifier << ":" << endl;
	for (auto it = prg->main->body.begin(); it != prg->main->body.end(); ++it){
		os << "    movl    $" << (*it)->exp->num << ", %eax" << endl;
		os << "    ret" << endl;
	}
}

ostream & operator<<(ostream &os, const Generator &gen){
	gen.print(os);
	return os;
}
