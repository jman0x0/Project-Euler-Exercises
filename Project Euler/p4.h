#pragma once

#ifndef PE_P4_H
#define PE_P4_H

#include "Problem.h"

namespace euler
{
	class P4 : public Problem<P4>
	{
	public:
		P4() : Problem("Largest Palindrome Product") {

		}

		std::pair<std::size_t, std::size_t> solution(std::size_t min, std::size_t max) {
			std::size_t a{}, b{};
			std::size_t greatest{};

			auto reverse{ [](auto n) {
				std::size_t backwards{0 };
				while (n != 0) {
					backwards = backwards * 10 + n % 10;
					n /= 10;
				}
				return backwards;
			} };
			for (std::size_t i{ min }; i < max; ++i) {
				for (std::size_t j{ max - 1 }; j >= min; --j) {
					if (const auto product{ i * j }; product > greatest && reverse(product) == product) {
						a = i;
						b = j;
						greatest = product;
						break;
					}
				}
			}

			return { a, b };
		}
	};
}

#endif