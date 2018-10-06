#pragma once
#ifndef _COLLECTION_OUT_H
#define _COLLECTION_OUT_H

#include <map>
#include <set>
#include <list>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>

using std::map;
using std::set;
using std::pair;
using std::list;
using std::vector;
using std::string;

namespace Out {
	template<typename Collection, typename D> string Join(const Collection& c, const D& d) {
		std::stringstream ss;
		bool is_fisrt = true;

		for (const auto& item : c) {
			if (!is_fisrt) {
				ss << d;
			}
			is_fisrt = false;
			ss << item;
		}
		return ss.str();
	}

	template<typename Fisrt, typename Second> std::ostream& operator<<(std::ostream& os, const pair<Fisrt, Second>& p) {
		return os << "(" << p.first << ";" << p.second << ")";
	}
	template<typename Key,   typename Value>  std::ostream& operator<<(std::ostream& os, const map <Key, Value>&	m) {
		return os << "{ " << Join(m, ", ") << " }";
	}

	template<typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& vec) {
		return os << "[ " << Join(vec, ", ") << " ]";
	}
	template<typename T> std::ostream& operator<<(std::ostream& os, const list<T>&   lst) {
		return os << "[ " << Join(lst, ", ") << " ]";
	}
	template<typename T> std::ostream& operator<<(std::ostream& os, const set<T>&	 set) {
		return os << "{ " << Join(set, ", ") << " }";
	}
}
using namespace Out;
#endif 