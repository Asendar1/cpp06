#pragma once

#include <cstdlib>  // For strtod, strtol, errno
#include <cerrno>   // For errno
#include <iostream>
#include <string>
#include <limits>
#include <climits>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &o);
		ScalarConverter &operator=(const ScalarConverter &o);
		~ScalarConverter();

		class InitializationException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "ScalarConverter cannot be instantiated.";
				}
		};
	public:
		static void convert(std::string str);
};
