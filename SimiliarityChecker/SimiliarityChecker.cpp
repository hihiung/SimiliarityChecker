#include <string>
#include <iostream>
#include <cmath>
const int FULL_SCORE_LENGTH = 60;
const int NO_SCORE = 0;

class SimChecker
{
public:
	SimChecker() {}

	void calcLengthLongShort(int& lengthLong, int& lengthShort, 
		const std::string& stringA, const std::string& stringB)
	{
		if (stringA.length() >= stringB.length())
		{
			lengthLong = stringA.length();
			lengthShort = stringB.length();
		}
		else
		{
			lengthLong = stringB.length();
			lengthShort = stringA.length();
		}
	}

	int calcScoreBasedOnLength(int lengthLong, int lengthShort)
	{
		int score = int((1.0f - double(lengthLong - lengthShort) / double(lengthShort)) * 60.f);
		score = std::max(NO_SCORE, score);

		return score;
	}

	int compareLength(const std::string& stringA, const std::string& stringB)
	{
		if (stringA.length() == stringB.length())
			return FULL_SCORE_LENGTH;

		int lengthLong = 0; int lengthShort = 0;
		calcLengthLongShort(lengthLong, lengthShort, stringA, stringB);
		return calcScoreBasedOnLength(lengthLong, lengthShort);
	}

private:

};