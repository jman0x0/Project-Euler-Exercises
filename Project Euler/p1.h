#pragma once

#ifndef PE_P1_H
#define PE_P1_H

#include "Problem.h"

namespace euler
{
	class P1 : public Problem<P1> {
	public:
		P1() : Problem("Multiple of 3 and 5") {

		}

		std::size_t solution(std::size_t n, std::size_t m1, std::size_t m2) {
			const auto linearSum{ [](std::size_t limit) {
				return (limit * (limit + 1)) / 2;
			} };
			
			const auto a{ linearSum((n-1) / m1) * m1 };
			const auto b{ linearSum((n-1) / m2) * m2};
			const auto c{ linearSum((n-1) / (m1 * m2)) * m1 * m2 };
			return a + b - c;
		}
	};
}

#endif
