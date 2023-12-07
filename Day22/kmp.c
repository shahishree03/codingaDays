#include <stdio.h>
#include <string.h>
void computeLPSArray(char *pattern, int patternLength, int *lps) {
int length = 0;
int i = 1;
lps[0] = 0;
while (i < patternLength) {
if (pattern[i] == pattern[length]) {
length++;
lps[i] = length;
i++;
} else {
if (length != 0) {
length = lps[length - 1];
} else {
lps[i] = 0;
i++;
}
}
}
}
void KMPSearch(char *text, char *pattern) {
int textLength = strlen(text);
int patternLength = strlen(pattern);
int lps[patternLength];
computeLPSArray(pattern, patternLength, lps);
int i = 0; // Index for text[]
int j = 0; // Index for pattern[]
while (i < textLength) {
if (pattern[j] == text[i]) {
i++;
j++;
}
if (j == patternLength) {
printf("Pattern found at index %d\n", i - j);
j = lps[j - 1];
} else if (i < textLength && pattern[j] != text[i]) {
if (j != 0) {
j = lps[j - 1];
} else {
i++;
}
}
}
}
int main() {
char *text;
char *pattern;
printf("Input of Text: ");
scanf("%s", text);
printf("Input of Pattern: ");
scanf("%s",pattern);
printf("Text: %s\n", text);
printf("Pattern: %s\n", pattern);
KMPSearch(text, pattern);
return 0;
}
