#include <stdio.h>
#include <stdlib.h>

void sojourn(void *pt){
      if (pt == NULL){
            printf("Nothing in memory");
      }
}


int main(){
      char *pt = malloc(sizeof(char) * 10);
      sojourn(pt);

}


