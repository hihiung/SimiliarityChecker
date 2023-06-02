#include <string>
#include <iostream>


class SimChecker
{
public:
	SimChecker() {}
	int compareLength(const std::string& stringA, const std::string& stringB)
	{
		if (stringA.length() == stringB.length())
			return 60;
		return 0;
	}
	int getResult(const std::string& stringA, const std::string& stringB)
	{
		return compareLength(stringA, stringB);
	}

private:

};