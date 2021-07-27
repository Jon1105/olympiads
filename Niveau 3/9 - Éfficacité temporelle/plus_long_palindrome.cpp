#include <iostream>
#include <string>
#define DEBUG

// 1. Get all substrings
// 2. Check if paldindrome
// 		if yes: compare to max
// return max

bool isPalindrome(std::string entry)
{
	size_t n = entry.size();
	if (n <= 1)
	{
		return true;
	}
	else if (entry[0] == entry[n - 1])
	{
		return isPalindrome(entry.substr(1, n - 2));
	}
	return false;
}

int main(int argc, char const *argv[])
{
	std::string entry;

	// entry = "mollakayakokomassa";

	std::cin >> entry;

	size_t max = 0;
	for (size_t start = 0; start < entry.size(); start++)
	{
		for (size_t len = 1; len < (entry.size() - start + 1); len++)
		{
			std::string sub = entry.substr(start, len);
			if (isPalindrome(sub) && sub.size() > max)
			{
				// std::cout << sub << ": " << sub.size() << '\n';
				max = sub.size();
			}
		}
	}
	std::cout << max << '\n';
	return 0;
}