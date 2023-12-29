#pragma once

#ifndef PE_P2_H
#define PE_P2_H

#include "Problem.h"

namespace euler 
{
	class P2 : public Problem<P2>
	{
	public:
		P2() : Problem("Even Fibonacci Numbers summation") {

		}
		std::size_t solution(std::size_t limit) {
			std::size_t a{ 0 };
			std::size_t b{ 2 };
			std::size_t sum{ 0 };
			while (b <= limit) {
				// std::pow(4, i) - std::pow(3, i) + std::pow(2, i) - 1 };
				sum += b;
				a = std::exchange(b, b * 4 + a);
			}
			return sum;
		}
	};
}

#endif
