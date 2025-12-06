#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	throw InitializationException();
}

ScalarConverter::ScalarConverter(const ScalarConverter &o)
{
	(void)o;
	throw InitializationException();
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &o)
{
	(void)o;
	throw InitializationException();
}

void ScalarConverter::convert(std::string str)
{
    if (str.length() == 0)
    {
        std::cout << "Empty string cannot be converted." << std::endl;
        return;
    }
    else if (str.length() == 1 && !isdigit(str[0]))
    {
        char c = str[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }
    else if (str == "nan" || str == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    else if (str == "-inf" || str == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }
    else if (str[str.length() - 1] == 'f')
    {
        char* endptr;
        errno = 0;
        double temp = strtod(str.c_str(), &endptr);
        if (errno == ERANGE || endptr != str.c_str() + str.length() - 1)
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        float f = static_cast<float>(temp);
        if (f >= 32 && f <= 126)
        {
            std::cout << "char: " << static_cast<char>(f) << std::endl;
        }
        else
        {
            std::cout << "char: impossible" << std::endl;
        }
		if (f > INT_MAX  || f < INT_MIN)
			std::cout << "int: OverFlow" << std::endl;
		else
        	std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    else
    {
        char* endptr;
        errno = 0;
        double d = strtod(str.c_str(), &endptr);
        if (errno == ERANGE || endptr != str.c_str() + str.length())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        bool isInt = (str.find('.') == std::string::npos);
        if (d >= 32 && d <= 126)
        {
            std::cout << "char: " << static_cast<char>(d) << std::endl;
        }
        else
        {
            std::cout << "char: impossible" << std::endl;
        }
        if (d > INT_MAX  || d < INT_MIN)
			std::cout << "int: OverFlow" << std::endl;
		else
        	std::cout << "int: " << static_cast<int>(d) << std::endl;
        if (isInt)
        {
            std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
            std::cout << "double: " << d << ".0" << std::endl;
        }
        else
        {
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        }
    }
}
