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
