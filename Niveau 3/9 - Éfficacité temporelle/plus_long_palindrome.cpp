#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	std::string entry;

	// entry = "mollakayakokomassa";

	std::cin >> entry;

	size_t max = 0;
	size_t len = 0;
	size_t out = 0;

	for (size_t i = 0; i < entry.size(); i++)
	{
		// state = false;
		len = 0;
		out = 0;
		if (i - 1 >= 0 && i + 1 < entry.size() && entry[i - 1] == entry[i + 1])
		{
			len += 3;
			out++;

			while (true)
			{
				if ((i - 1 - out) >= 0 && (i + 1 + out) < entry.size() && entry[i - 1 - out] == entry[i + 1 + out])
				{
					len += 2;
					out++;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			len = 1;
		}
		if (len > max)
		{
			max = len;
		}
		// state = true;
		len = 0;
		out = 0;
		if (i - 1 >= 0 && i < entry.size() && entry[i - 1] == entry[i])
		{
			len += 2;
			out++;

			while (true)
			{
				if ((i - 1 - out) >= 0 && (i + out) < entry.size() && entry[i - 1 - out] == entry[i + out])
				{
					len += 2;
					out++;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			len = 1;
		}

		if (len > max)
		{
			max = len;
		}
	}

	std::cout << max << '\n';
	return 0;
}