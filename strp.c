#include "str.h"
#include <assert.h>

size_t Str_getLength(const char *pcSrc){
   const char *pcEnd;

   assert(pcSrc != NULL);

   pcEnd = pcSrc;
   while (*pcEnd != '\0'){
      pcEnd++;
   }

   return (size_t)(pcEnd - pcSrc);

}

char *Str_copy(char *pcDest, const char *pcSrc) {
   char *pcCurrent = pcDest;

   assert(pcDest != NULL);
   assert(pcSrc != NULL);

   /* copy chars and advance both ptrs*/
   while (*pcSrc != '\0'){
      *pcCurrent = *pcSrc;
      pcCurrent++;
      pcSrc++;
   }
   /* apprend the terminating null byte*/
   *pcCurrent = '\0';

   return pcDest;
}

char *Str_concat(char *pcDest, const char *pcSrc) {
   char *pcEnd = pcDest;

   assert(pcDest != NULL);
   assert(pcSrc != NULL);

   /* Move pcEnd to null byte at the end of dest string*/
   while (*pcEnd != '\0'){
      pcEnd++;
   }

   /* copy chars from the src and overwrite the original null byte */
   while (*pcSrc != '\0') {
      *pcEnd = *pcSrc;
      pcEnd++;
      pcSrc++;
   }

   /* append the whole concat str with a new null byte*/
   *pcEnd = '\0';

   return pcDest;
}

int Str_compare(const char *pcS1, const char *pcS2)
{
   assert(pcS1 != NULL);
   assert(pcS2 != NULL);

   /* Compare chars as long as they match */
   while (*pcS1 == *pcS2) {
      /* If they match and we hit the null byte, the strings are
       * identical */
      if (*pcS1 == '\0'){
         return 0;
      }
      pcS1++;
      pcS2++;
   }

   /* return the diff of the first unmatching chars*/
   return (int)*pcS1 - (int)*pcS2;
}

char *Str_search(const char *pcString, const char *pcSubstring){
   const char *pcTempMain;
   const char *pcTempSub;

   assert(pcString != NULL);
   assert(pcSubstring != NULL);

   /* if the substring is empty, return the whole str*/
   if (*pcSubstring == '\0'){
      return (char *)pcString;
   }


   /* going through string char by char */
   while (*pcString != '\0') {
      /* Set up temp ptrs for the look ahead */
      pcTempMain = pcString;
      pcTempSub = pcSubstring;

      /* Check to see if the substring matches starting from pcMain */
      while (*pcTempMain == *pcTempSub && *pcTempMain != '\0'){
         pcTempMain++;
         pcTempSub++;
      }

      /* if ptr ahead reaches null byte of substring, its found */
      if (*pcTempSub == '\0') {
         return (char *)pcString;
      }

      /* move anchor forward to check next starting pos*/
      pcString++;
   }

   /* finish whole string without returning there is no match */
   return NULL;
}
