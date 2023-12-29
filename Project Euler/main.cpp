#include <iostream>
#include "p4.h"

template<typename T>
std::ostream& operator<<(std::ostream& out, std::pair<T, T> value) {
	return out;
}

int main() {
	euler::P4 problem;

	std::cout << problem.getTitle() << '\n';
	std::cout << problem.solution(100, 1000);
	std::cout << std::flush;
	std::cin.get();
}