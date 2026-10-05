#ifndef STR_H
#define STR_H
#include <stddef.h>

/* Returns the number of characters in the string pointed to by pcSrc, 
 * excluding the null byte '\0'
 * Asserts that pcSrc is not null */
size_t Str_getLength(const char *pcSrc);

/* Copies the string pointed to by pcSrc including the null byte
 * into the array pointed to by pcDest. Returns pcDest
 * Asserts that both pointers are not null */
char *Str_copy(char *pcDest, const char *pcSrc);

/* Appends the string pointed to by pcSrc to the end of the string
 * pointed to by pcDest, adding a new null byte. Returns pcDest.
 * Asserts that both pointers are not null */
char *Str_concat(char *pcDest, const char *pcSrc);

/* Compares the strings pointed to by pcS1 and pcS2.
 * Returns 0 if they are similar, a negative number if pcS1 is smaller
 * than pcS2 or a positive number if pcS1 is larger than pcS2
 * Asserts that both pointers are not null*/
int Str_compare(const char *pcS1, const char *pcS2);

/* Finds the first occurrence of pcSubstring inside pcString
 * Returns a pointer to the exact memory location where the match
 * begins, or null if it isnt found. Asserts both ptrs are null */
char *Str_search(const char *pcString, const char *pcSubstring);

#endif
