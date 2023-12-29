#pragma once

#ifndef PE_P3_H
#define PE_P3_H

#include "Problem.h"

namespace euler
{
	class P3 : public Problem<P3>
	{
	public:
		P3() : Problem("Largest Prime Factor") {

		}

		std::size_t solution(std::size_t n) {
			std::size_t limit{ static_cast<std::size_t>(std::sqrt(n)) };
			std::size_t i{ 2 };
			while (i <= limit) {
				if (n % i == 0) {
					n /= i;
					limit = static_cast<std::size_t>(std::sqrt(n));
					continue;
				}
				++i;
			}
			return n;
		}
	};
}

#endif
