#include <string>
#include <iostream>

const int FULL_SCORE_LENGTH = 60;
const int NO_SCORE = 0;

class SimChecker
{
public:
	SimChecker() {}


	void calcLengthLongShort(int& longer, int& shorter, const std::string& stringA, const std::string& stringB)
	{
		if (stringA.length() >= stringB.length())
		{
			longer = stringA.length();
			shorter = stringB.length();
		}
		else
		{
			longer = stringB.length();
			shorter = stringA.length();
		}
	}

	int compareLength(const std::string& stringA, const std::string& stringB)
	{
		if (stringA.length() == stringB.length())
			return FULL_SCORE_LENGTH;


		int lengthLong = 0; int lengthShort = 0;
		calcLengthLongShort(lengthLong, lengthShort, stringA, stringB);
		if (lengthLong >= 2 * lengthShort)
			return NO_SCORE;

		return NO_SCORE;
	}
	int getResult(const std::string& stringA, const std::string& stringB)
	{
		return compareLength(stringA, stringB);
	}

private:

};