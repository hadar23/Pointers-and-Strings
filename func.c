
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "func.h"

char DELIMITERS[] = " ,:?-";

void initString(char* str, int length) {
	printf("Please enter a string (max length = %d):\n", length);
	fgets(str, length, stdin);
	str[strcspn(str, "\n")] = '\0';
}
void printString(const char* str) {
	printf("The string you've entered is:\n%s", str);
}
int countWords(const char* str) {
	int counter = 0;
	char temp[MAX_LEN];
	char* word, *lastWord;
	strcpy(temp, str);

	word = strtok(temp, DELIMITERS);
	while (word) {
		lastWord = word;
		word = strtok(NULL, DELIMITERS);
		if (isThereALetter(lastWord))
			counter++;
	}
	return counter;
}

int isThereALetter(const char* str) {
	while (*str) {
		if (isalpha(*str))
			return 1;
		str++;
	}
	return 0;
}

void longestInCaptital(char* str) {
	int maxLen = 0, len = 0;
	char temp[strlen(str)];
	char* pLongestInTemp = temp, *placeOfTemp = temp, *word;
	strcpy(temp, str);

	word = strtok(temp, DELIMITERS);
	while (word) {
		len = strlen(word);
		if (maxLen < len) {
			maxLen = len;
			pLongestInTemp = word;
		}
		word = strtok(NULL, DELIMITERS);
	}

	str += pLongestInTemp - placeOfTemp;
	increaseOneWord(strlen(pLongestInTemp), str);
}

void increaseOneWord(int size, char* str) {
	while (size > 0) {
		*str = toupper(*str);
		size--;
		str++;
	}
}

void revertWords(char* str) {
	char temp[strlen(str)];
	char* word, *pPastWord = temp;

	convertDelimitersToStar(str);
	strcpy(temp, str);

	word = strtok(temp, "*");
	str += word - pPastWord;
	pPastWord = word;
	while (word) {
		reverseOneWord(strlen(word), str);
		word = strtok(NULL, "*");
		str += word - pPastWord;
		pPastWord = word;
	}
}

void convertDelimitersToStar(char* str) {
	while (*str) {
		if (strchr(DELIMITERS, *str))
			*str = '*';
		str++;
	}
}

void reverseOneWord(int wordLen, char* str) {
	char* end = wordLen + str - 1;

	while (str < end) {
		swap(str, end);
		end--;
		str++;
	}
}

void swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void eraseCharsFromString(char* str, char* chars) {
	char* pCurrent = str;

	while (*pCurrent) {
		if (!strchr(chars, *pCurrent)) {
			*str = *pCurrent;
			pCurrent++;
			str++;
		} else {
			while (strchr(chars, *pCurrent) && *pCurrent)
				pCurrent++;
		}
	}
	*str = '\0';
}

int isPalindrome(const char* str) {
	const char* end = strlen(str) + str;

	while (str < end) {
		if (isalpha(*str) && isalpha(*end)) {
			if (tolower(*str) != tolower(*end))
				return 0;
			str++;
			end--;
		} else if (isalpha(*str)) {
			end--;
		} else {
			str++;
		}
	}
	return 1;
}

void clearBuffer() {
	while (getchar() != '\n') {
	}
}

