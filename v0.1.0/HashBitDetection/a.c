#include <stdio.h>
#include "sha.c"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint64_t u64t;
typedef uint32_t u32t;

int main(){
      unsigned char * a = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
      u32t * H = sha256(a);
      for (int i = 0 ; i < 8 ; i++){
            printf("%08x",H[i]);
      }
      printf("\n");
      
}
