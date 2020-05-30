#include <iostream>
#include <fstream>
#include"FlowCounterRepresenter.h"
int main(int argc, char* argv[])
{
	ifstream input("input.txt");
	FlowCounterRepresenter flow(input);
	std::cout << "Maximal flow value = " << flow.countMaxFlow();
	return 0;
}