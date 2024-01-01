#pragma once

#ifndef PE_P9_H
#define PE_P9_H

#include "Problem.h"
#include <format>

namespace euler
{
	struct PythagoreanTriplet {
		std::size_t a, b, c;
	};

	class P9 : public Problem<P9>
	{
	public:
		P9() : Problem("Special Pythagorean Triplet") {

		}

		std::string solution() {
			auto [a,b,c]{ computeTripletSum(1'000) };

			return std::format("Solution found with triplet a={}, b={}, c={}, abc={}", a,b,c,a*b*c);
		}

		PythagoreanTriplet computeTripletSum(std::size_t n) {
			// a^2 + b^2 = c^2
			// a + b + c = n
			// a < b < c
			// a < (a+1) < (a+2) <= n
			// Thus, 3a + 3 <= n and a <= (n-3)/3 <= n/3 - 1 and a < n/3  
			// For any a, a < b < c also means a < b < b + 1
			// 0 < b - a < b - a + 1
			// (n - a)/2
			for (std::size_t a{ 1 }; a < n/3; ++a) {
				const std::size_t BOUND{ (n - a) / 2 };
				for (std::size_t b{ a }; b < BOUND; ++b) {
					const double c{ std::hypot(a, b) };

					if (auto natural{ static_cast<std::size_t>(c) }; c == natural && a + b + natural == n) {
						return { a, b, natural };
					}
				}
			}

			return {};
		}

	};
}

#endif
