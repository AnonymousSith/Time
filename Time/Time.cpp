#include "Time.h"

namespace TIME{
	Time::Time():Seconds(0), Minutes(0), Hours(0){};
	Time::Time(size_t value){
		Hours = value / 3600;
		Minutes = value % 3600 / 60;
		Seconds = value % 3600 % 60;
	}
	Time::Time(size_t new_hours, size_t new_minutes, size_t new_seconds){
		size_t hh = new_hours * 3600;
		size_t mm = new_minutes * 60;
		size_t ss = new_seconds;
		
		int value = hh + mm + ss;
		
		Hours = value / 3600;
		Minutes = value % 3600 / 60;
		Seconds = value % 3600 % 60;
	}
	Time::Time(const Time& value){
		Hours = value.Hours;
		Minutes = value.Minutes;
		Seconds = value.Seconds;
	}
	
	Time::operator size_t() const {
		return { Hours * 3600 + Minutes * 60 + Seconds };
	}

	Time Time::operator+(const Time& value) const{
		return { size_t(*this) + size_t(value) };
	}
	Time Time::operator-(const Time& value) const{
		if (size_t(*this) < size_t(value)) {
			throw std::runtime_error("Resultic value is negative number");
		}

		return { size_t(*this) - size_t(value) };
	}
	Time Time::operator*(const Time& value) const {
		return { size_t(*this) * size_t(value) };
	}
	Time Time::operator/(const Time& value) const {
		if (size_t(*this) == Time{0}) {
			throw std::invalid_argument("Divide by zero!");
		}
		return { size_t(*this) / size_t(value) };
	}

	Time Time::operator+(size_t value) const {
		return { size_t(*this) + value };
	}
	Time Time::operator-(size_t value) const {
		if (size_t(*this) < value) {
			throw std::runtime_error("Resultic value is negative number");
		}

		return { size_t(*this) - value };
	}
	Time Time::operator*(size_t value) const {
		return { size_t(*this) * value };
	}
	Time Time::operator/(size_t value) const {
		return { size_t(*this) / value };
	}
	Time Time::operator%(size_t value) const {
		return { size_t(*this) % size_t(value) };
	}

	Time& Time::operator+=(const Time& value){
		return { *this = (*this + value) };
	}
	Time& Time::operator-=(const Time& value) {
		return { *this = (*this - value) };
	}
	
	bool Time::operator>(const Time& value) const{
		return (size_t(*this) > size_t(value));
	}
	bool Time::operator<(const Time& value) const{
		return (size_t(*this) < size_t(value));
	}

	bool Time::operator==(const Time& value) const{
		return (size_t(*this) == size_t(value));
	}
	bool Time::operator!=(const Time& value) const{
		return (size_t(*this) != size_t(value));
	}
	bool Time::operator>=(const Time& value) const{
		return (size_t(*this) >= size_t(value));
	}
	bool Time::operator<=(const Time& value) const{
		return (size_t(*this) <=
 size_t(value));
	}


	std::ostream& operator<<(std::ostream& os, const Time& value){
		os << value.Hours << ":" << value.Minutes << ":" << value.Seconds;
		return os;
	}
	std::istream& operator>>(std::istream& is, Time& value) {
		is >> value.Hours >> value.Minutes >> value.Seconds;
		return is;
	}
};