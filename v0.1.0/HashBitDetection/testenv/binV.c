#include <stdio.h>
#include <stdlib.h>

void binV(char a){ 
      unsigned char bit[10] ;
      int i = 0 ;
      while (a != 0){
            if (a & 1 == 1){
                  bit[i++] = '1';
            }

            else{
                  bit[i++] = '0';
            }
            a /= 2;
      }
      while (i < 8){
            bit[i++] = '0';
      }
      bit[i] = '\0';
      
      for (int j = 0; j < i/2; j++ ){
            int temp = bit[j];
            bit[j] = bit[i - j - 1];
            bit[i - j -1 ] = temp;
      }
      printf("%s\t", bit);
}

void main(){
      char p[11] = "PRAY TO ME";
      for (int i = 0; i < 11; i++){
            binV(p[i]);
      }

}
