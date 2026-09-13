#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "sha.c"

typedef uint32_t u32t ;
int main(int argv, char * argc[]){
      FILE *binREAD= fopen(argc[2], "rb");
      fseek(binREAD, 0, SEEK_END); //move cursor to the end 
      long len = ftell(binREAD); //count the len of a file binary contect
      rewind(binREAD); //what the fuck?

      u32t * buffer = malloc(len); //where i will write the buffer
      fread(buffer,1,len,binREAD); //read from f, 1-len, put it to buffer


      //scan attempt 1

      FILE *malware = fopen(argc[1], "rb");
      fseek(malware, 0, SEEK_END); 
      long len2 = ftell(malware); 
      rewind(malware); 


      unsigned char * Malbuffer = malloc(len2); 
      fread(Malbuffer,1,len2,malware); 
      u32t * H = sha256(Malbuffer);

      for (int i = 0 ; i < 8 ; i++){
            if (H[i] != buffer[i]){
                  printf("NOT %s\n", argc[1]);
                  return 0;
            }
      }

      printf("%s DETECTED\n", argc[1]);

      return 1; 
}
