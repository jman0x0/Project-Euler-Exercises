#pragma once

#ifndef PE_P7_H
#define PE_P7_H

#include "Problem.h"

namespace euler
{
	class P7 : public Problem<P7>
	{
	public:
		P7() : Problem("Nth prime number") {

		}

		std::uint64_t solution() {
			return nthprime(10001);
		}

		std::uint64_t nthprime(std::size_t n) {
			std::size_t count{};
			std::size_t prime{};
			for (std::size_t i{ 2 }; count <= n && i < std::numeric_limits<std::size_t>::max(); ++i) {
				if (isprime(i)) {
					prime = i;
					++count;
				}
			}

			return prime;
		}
		
		bool isprime(std::size_t n) {
			if (n > 2 && n % 2 == 0) {
				return false;
			}

			const auto end{ static_cast<std::size_t>(std::sqrt(n)) };
			for (std::size_t i{ 3 }; i <= end; i += 2) {
				if (n % i == 0) {
					return false;
				}
			}

			return n > 1;
		}
	};
}

#endif
