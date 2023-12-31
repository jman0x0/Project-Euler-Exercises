#pragma once

#ifndef PE_P5_H
#define PE_P5_H

#include "Problem.h"

namespace euler
{
	class P5 : public Problem<P5>
	{
	public:
		P5() : Problem("Smallest Multiple") {

		}

		std::uint64_t solution(std::size_t n) {
			std::vector<bool> sieve;
			sieve.resize(n, true);

			for (std::size_t i{ 2 }; i < n; ++i) {
				for (std::size_t j{ i * i }; j < n; j += i) {
					sieve[j] = false;
				}
			}

			
			std::vector<std::uint64_t> primes;
			for (std::size_t i{ 2 }; i < n; ++i) {
				if (sieve[i]) primes.push_back(i);
			}

			std::uint64_t product{ 1 };
			for (auto prime : primes) {
				auto count{ prime };
				while (count <= n) {
					count *= prime;
				}
				product *= count / prime;
			}
			return product;
		}

		std::uint64_t solution2(std::size_t n) {
			std::uint64_t product{ 1 };
			for (std::size_t i{ 2 }; i <= n; ++i) {
				if (product % i != 0) {
					for (std::size_t j{ 2 }; j <= n; ++j) {
						if ((product * j) % i == 0) {
							product *= j;
							break;
						}
					}
				}
			}
			return product;
		}
	};
}

#endif
