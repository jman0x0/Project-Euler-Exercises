#pragma once

#ifndef PE_P6_H
#define PE_P6_H

#include "Problem.h"

namespace euler
{
	class P6 : public Problem<P6>
	{
	public:
		P6() : Problem("Sum Square Difference") {

		}

		std::size_t solution(std::size_t n) {
			const auto series{ sumOfSeries(n) };
			const auto squares{ sumOfSquares(n) };
			return (series * series) - squares;
		}
	private: 
		std::size_t sumOfSeries(std::size_t n) {
			return (n * (n + 1)) / 2;
		}

		std::size_t sumOfSquares(std::size_t n) {
			return (n * n + n) * (2 * n + 1) / 6;
		}
	};
}

#endif
