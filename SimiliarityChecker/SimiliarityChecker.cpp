#include <string>
#include <iostream>
#include <cmath>
const int FULL_SCORE_LENGTH = 60;
const int FULL_SCORE_ALPHABET = 40;
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

	int compareAlphabet(const std::string& stringA, const std::string& stringB)
	{
		int lengthA = stringA.length();
		int lengthB = stringB.length();

		for (int idxA = 0; idxA < lengthA; idxA++ )
		{
			char charA = stringA[idxA];
			if (stringB.find(charA) == std::string::npos)
				return NO_SCORE;
		}
		return FULL_SCORE_ALPHABET;
	}

private:

};