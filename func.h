

#ifndef FUNC_H_
#define FUNC_H_
#define MAX_LEN			100

void initString(char* str, int length);
void printString(const char* str);
int countWords(const char* str);
int isThereALetter(const char* str);
void longestInCaptital(char* str);
void increaseOneWord(int size, char* str);
void revertWords(char* str);
void convertDelimitersToStar(char* str);
void reverseOneWord(int wordLen, char* dst);
void swap(char* a, char* b);
void eraseCharsFromString(char* str, char* chars);
int isPalindrome(const char* str);
void clearBuffer();

#endif /* FUNC_H_ */
