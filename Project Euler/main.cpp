#include <iostream>
#include <iomanip>
#include "p9.h"

template<typename T>
std::ostream& operator<<(std::ostream& out, std::pair<T, T> value) {
	return out;
}

int main() {
	euler::P9 problem;

	std::cout << problem.getTitle() << '\n';
	std::cout << problem.solution(); 
	//problem.logProduct(0, "");
	std::cout << std::flush;
	std::cin.get();
}