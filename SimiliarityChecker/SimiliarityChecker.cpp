#include <string>
#include <iostream>
#include <cmath>
const int FULL_SCORE_LENGTH = 60;
const int FULL_SCORE_ALPHABET = 40;
const int NO_SCORE = 0;
const int ALPHABET_SZ = 26;
enum Status
{
	NOT_EXIST = 0,
	ONLY_IN_A = 1,
	ONLY_IN_B = 2,
	BOTH_HAVE_THIS = 3,
};

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

	int alphabet2idx(char alphabet)
	{
		return alphabet - 'A';
	}

	int calcScoreBasedOnLength(int lengthLong, int lengthShort)
	{
		int score = int((1.0f - double(lengthLong - lengthShort) / double(lengthShort)) * 60.f);
		score = std::max(NO_SCORE, score);

		return score;
	}

	int compareAlphabet(const std::string& stringA, const std::string& stringB)
	{
		int alphabetArray[26] = { Status::NOT_EXIST };

		updateAlphabetArray(alphabetArray, stringA, stringB);
		return calcScoreBasedOnAlphabet(alphabetArray);
	}

	int compareLength(const std::string& stringA, const std::string& stringB)
	{
		if (stringA.length() == stringB.length())
			return FULL_SCORE_LENGTH;

		int lengthLong = 0; int lengthShort = 0;
		calcLengthLongShort(lengthLong, lengthShort, stringA, stringB);
		return calcScoreBasedOnLength(lengthLong, lengthShort);
	}


	int alphabetArrayCounter(const bool* alphabetArray)
	{
		int count = 0;
		for (int idx = 0; idx < 26; idx++)
		{
			if (alphabetArray[idx] == true)
				count++;
		}
		return count;
	}

	void updateAlphabetArray(int* alphabetArray, const std::string& stringA, const std::string& stringB)
	{
		int lengthA = stringA.length();
		int lengthB = stringB.length();

		// update Alphabets from string A
		for (int idxA = 0; idxA < lengthA; idxA++)
		{
			char charA = stringA[idxA];
			alphabetArray[alphabet2idx(charA)] = Status::ONLY_IN_A;
		}

		// update Alphabets from string B
		for (int idxB = 0; idxB < lengthB; idxB++)
		{
			char charB = stringB[idxB];
			if (alphabetArray[alphabet2idx(charB)] == Status::NOT_EXIST) {
				alphabetArray[alphabet2idx(charB)] = Status::ONLY_IN_B;
				continue;
			}
			
			if (alphabetArray[alphabet2idx(charB)] == Status::ONLY_IN_A)
				alphabetArray[alphabet2idx(charB)] = Status::BOTH_HAVE_THIS;
		}
	}


	int calcScoreBasedOnAlphabet(int* alphabetArray)
	{
		int total_alphabet = 0;
		int both_a_and_b = 0;

		for (int idx = 0; idx < ALPHABET_SZ; idx++)
		{
			if (alphabetArray[idx] == Status::NOT_EXIST)
				continue;

			total_alphabet++;
			if (alphabetArray[idx] == Status::BOTH_HAVE_THIS)
				both_a_and_b++;
		}

		return int((float(both_a_and_b) / float(total_alphabet)) * FULL_SCORE_ALPHABET);

	}

private:

};