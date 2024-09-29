///
/// This is a Google test int add(int, int) function
///
#include "add.h"
#include <iostream>

void usage(char * myname) {
	std::cout << "Usage: ./"<<myname<< " <number 1> <number 2>" << std::endl;
}

int main (int argc, char ** argv) 
{
	if (argc != 3) {
		usage(argv[0]);
		return 255;
	}
	int val1 = std::atoi(argv[1]);
	int val2 = std::atoi(argv[2]);
	int result = add(val1,val2);

	std::cout << "add("<<val1<<", "<< val2 <<"): " << result << std::endl;

	return 0;
}


// TODO: watch https://disk.yandex.ru/d/4OzaaAriB6auWw/Семинары/Игорь%20Удовиченко%20-%20Семинар%202.mov @ 22:16 
// this tells how to configure CMakeFiles.txt