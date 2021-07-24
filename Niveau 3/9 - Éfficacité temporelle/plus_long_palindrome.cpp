#include <iostream>
#include <string>
#define DEBUG

void output(std::string label, int value, char indicator = '\0')
{
	if (indicator == '\0')
		std::cout << label << ": " << value << '\n';

	else
		std::cout << label << "(" << indicator << "): " << value << '\n';
}

// http://www.france-ioi.org/algo/task.php?idChapter=528&idTask=1171

size_t palindromeLength(std::string s, size_t i)
{
	if (i == 0) // check if s[i-1] is invalid
		return 1;
	else if (s[i - 1] == s[i])
	{
		s.erase(s.begin() + i - 1, s.begin() + i + 1);
		return 2 + palindromeLength(s, i - 1);
	}
	else if (i == s.size() - 1)
	{
		return 0;
	}
	else if (s[i - 1] == s[i + 1])
	{
		s.erase(s.begin() + i - 1);
		s.erase(s.begin() + i + 1);
		return 2 + palindromeLength(s, i - 1);
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	std::string entry;

#ifdef DEBUG
	entry = "mollakayakokomassa";
#else
	std::cin >> entry;
#endif

	size_t count = 0;
	for (size_t i = 0; i < entry.size(); i++)
	{
		size_t temp = palindromeLength(entry, i);
		output("temp", temp, entry[i]);
		if (temp > count)
			count = temp;
	}
	output("Final Result", count);
	// std::cout << count << '\n';
	return 0;
}