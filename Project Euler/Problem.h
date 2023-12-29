#pragma once

#ifndef PE_PROBLEM_H
#define PE_PROBLEM_H

#include <iostream>
#include <vector>
#include <string>

namespace euler
{
	template<typename Derived, typename... solargs>
	class Problem
	{
	public:
		using Solution = Derived;
	private:
		const std::string m_title;
		std::vector<void(Derived::*)()> members;
	public:
		Problem(const std::string& title)
			: m_title(title) {

		}

		virtual ~Problem() = 0;

		void benchmark() {

		}

		const std::string& getTitle() const noexcept {
			return m_title;
		}
	};

	template<typename Derived, typename... solargs>
	inline Problem<Derived, solargs...>::~Problem() = default;
}

#endif
