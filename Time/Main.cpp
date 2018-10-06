#include <iostream>
#include <conio.h>
#include "Time.h"

int main(int argc, char* argv[]){
	Time a;
	std::cin >> a;

	Time b;
	std::cin >> b;
	
	std::cout << a+b;
	_getch();
	return 0;
}