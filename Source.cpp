#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <iomanip>

int main(int argc, char** argv)
{
	std::string data = "priven 777 my mail:: std::lol kek bob.de@phystech.edu fsadf@dfmail.com yandex@mail.ru 777@mail.com google@gmail.com yandexnot@mail lol@ail.ru my@mail.mipt.ru lol.kek@mipt.ru lol.kek@mipt.mail.ru lol.lol.lol.lol@mail.ru not@mailru not@mail. @mail.runot not@mail ru @mail.not not not@ not@mail. not@mail.. not@@mail.ru";

	std::regex pattern(R"((\w+\.{0,1})+@(([[:alpha:]]+\.)+\w{2,}))");

	std::sregex_iterator begin(data.cbegin(), data.cend(), pattern);
	std::sregex_iterator end;

	std::for_each(begin, end, [](const std::smatch& m)
		{
			for (std::size_t i = 0; i < m.size(); ++i)
			{
				std::cout << std::left << std::setw(25) << m[i] << " | ";
			}
			std::cout << std::endl;
		});

	return 0;
}