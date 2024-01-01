#pragma once

#ifndef PE_P8_H
#define PE_P8_H

#include "Problem.h"
#include <numeric>

namespace euler
{
	class P8 : public Problem<P8>
	{
	public:
		P8() : Problem("Largest Adjacent Digit Product") {

		}

		std::uint64_t solution() {
			return adjacentProduct(13, "73167176531330624919225119674426574742355349194934"
				"96983520312774506326239578318016984801869478851843"
				"85861560789112949495459501737958331952853208805511"
				"12540698747158523863050715693290963295227443043557"
				"66896648950445244523161731856403098711121722383113"
				"62229893423380308135336276614282806444486645238749"
				"30358907296290491560440772390713810515859307960866"
				"70172427121883998797908792274921901699720888093776"
				"65727333001053367881220235421809751254540594752243"
				"52584907711670556013604839586446706324415722155397"
				"53697817977846174064955149290862569321978468622482"
				"83972241375657056057490261407972968652414535100474"
				"82166370484403199890008895243450658541227588666881"
				"16427171479924442928230863465674813919123162824586"
				"17866458359124566529476545682848912883142607690042"
				"24219022671055626321111109370544217506941658960408"
				"07198403850962455444362981230987879927244284909188"
				"84580156166097919133875499200524063689912560717606"
				"05886116467109405077541002256983155200055935729725"
				"71636269561882670428252483600823257530420752963450");
		}

		std::uint64_t adjacentProduct(std::size_t n, const std::string& digits) {
			std::uint64_t greatest{};
			std::uint64_t product{ 1 };
			std::size_t anchor{ 0 };

			for (std::size_t i{ 0 }; i != digits.size(); ++i) {
				if (digits[i] == '0') {
					product = 1;
					anchor = i + 1;
					continue;
				}
				
				product *= (digits[i] - '0');
				if ((i - anchor) + 1 == n) {
					greatest = std::max(greatest, product);
					product /= (digits[anchor++] - '0');
				}
				
			}
			return greatest;
		}

		std::uint64_t logProduct(std::size_t n, const std::string& digits) {
			static constexpr double DIGIT_LOG2[]{
				std::numeric_limits<double>::quiet_NaN(),
				0.000000000000000, 1.000000000000000, 1.584962500721156,
				2.000000000000000, 2.321928094887362, 2.584962500721156,
				2.807354922057604, 3.000000000000000, 3.169925001442312
			};

			static constexpr auto multiplier{ [](double val, char digit) {
				return val * (digit - '0');
			} };

			std::pair greatest{ DIGIT_LOG2[0], 0ul};
			std::pair tally{ 0.0, 0ul };
			for (std::size_t i{ 0 }; i < digits.size(); ++i) {
				if (digits[i] == '0') {
					tally = { 0.0, i + 1 };
					continue;
				}
				tally.first += DIGIT_LOG2[digits[i] - '0'];
				if (1 + i - tally.second == n) {
					if (std::isnan(greatest.first) || tally.first > greatest.first) {
						greatest = tally;
					}
					tally.first -= DIGIT_LOG2[digits[tally.second++] - '0'];
				}
			}
			const bool isNAN{ std::isnan(greatest.first) };
			return isNAN ? 0.0 : std::accumulate(std::begin(digits) + greatest.second, std::begin(digits) + greatest.second + n, 1.0, multiplier);
		}
	};
}

#endif 
