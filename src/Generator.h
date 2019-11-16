#pragma once

#include "Node.h"
#include <iostream>

class Generator {
	private:
		ProgramNode *prg;
	public:
		Generator(ProgramNode *ast);
		void print(std::ostream &os) const;
};

std::ostream & operator<<(std::ostream &os, const Generator &gen);
