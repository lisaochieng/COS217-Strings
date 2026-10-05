/* array notation */

#include "str.h"
#include <assert.h>

size_t Str_getLength(const char pcSrc[]){
   size_t uLength = 0;

   assert(pcSrc != NULL);

   while (pcSrc[uLength] != '\0'){
      uLength++;
   }

   return uLength;
}

char *Str_copy(char pcDest[], const char pcSrc[]){
   size_t i = 0;

   assert(pcDest != NULL);
   assert(pcSrc != NULL);

   /* Copy each char from src to dest */
   while(pcSrc[i] != '\0') {
      pcDest[i] = pcSrc[i];
      i++;
   }

   /* Append null byte at the end of new copy */
   pcDest[i] = '\0';

   return pcDest;
}

char *Str_concat(char pcDest[], const char pcSrc[]){
   size_t dest_indx = 0;
   size_t src_indx = 0;

   assert(pcDest != NULL);
   assert(pcSrc != NULL);

   /* find the null byte at the end of the dest str */
   while(pcDest[dest_indx] != '\0') {
      dest_indx++;
   }

   /* copy the source string, overwrite the original null byte */
   while(pcSrc[src_indx] != '\0'){
      pcDest[dest_indx] = pcSrc[src_indx];
      dest_indx++;
      src_indx++;
   }

   /* Append a new null byte at the end */
   pcDest[dest_indx] = '\0';

   return pcDest; 
   
}

int Str_compare(const char pcS1[], const char pcS2[]){
   size_t i = 0;

   assert(pcS1 != NULL);
   assert(pcS2 != NULL);

   /* Compare chars one by one as long as they match */
   while (pcS1[i] == pcS2[i]){
      /* if match and hit null byte, identical */
      if (pcS1[i] == '\0') {
         return 0;
      }
      
      i++;
   }

   /* return the difference of the 1st chars that dont match*/
   return (int)pcS1[i] - (int)pcS2[i];
}

char *Str_search(const char pcString[], const char pcSubstring[]){
      size_t i = 0;
      size_t j;

      assert(pcString != NULL);
      assert(pcSubstring != NULL);

      /* if substr is empty return the whole str*/
      if (pcSubstring[0] == '\0'){
         return (char *)pcString;
      }

      /* char by char in string */
      while(pcString[i] != '\0'){
            j = 0;

            /*look ahead to see if substr matches starting from idx i*/
            while (pcString[i+j] == pcSubstring[j] && pcString[i+j] !=
                   '\0'){
               j++;
            }

            /* if the ahead ptr reaches the null byte in the substring
               its been found */
            if (pcSubstring[j] == '\0'){
               return (char *)&pcString[i];
               
            }
            
            i++;
         }
         /* If we finish teh whole string without returning there was
          * no match*/
         return NULL;
   }
