#pragma once
#ifndef _TIME_H
#define _TIME_H

#include <iostream>
#include <exception>

#include "UnitTest/Unit test.h"

namespace TIME{
	class Time
	{
	private:
		size_t Seconds;
		size_t Minutes;
		size_t Hours;

		//size_t ConvertToSeconds()const; // Возвращает время в секундах
	public:
		Time();
		Time(size_t);
		Time(size_t, size_t, size_t);
		Time(const Time&);

		Time operator+(const Time&) const;
		Time operator-(const Time&) const;
		Time operator*(const Time&) const;
		Time operator/(const Time&) const;

		Time operator+(size_t) const;
		Time operator-(size_t) const;
		Time operator*(size_t) const;
		Time operator/(size_t) const;
		Time operator%(size_t) const;

		Time& operator+=(const Time&);
		Time& operator-=(const Time&);
		
		bool operator>(const Time&) const;
		bool operator<(const Time&) const;
		
		bool operator==(const Time&) const;
		bool operator!=(const Time&) const;
		bool operator>=(const Time&) const;
		bool operator<=(const Time&) const;

		operator size_t() const;
		
		friend std::ostream& operator<<(std::ostream&, const Time&);
		friend std::istream& operator>>(std::istream&, Time&);
	};
}
using namespace TIME;
#endif