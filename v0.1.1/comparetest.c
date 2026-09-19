#include "./new.c"
#include <time.h>

int main(){
      struct stat file;
      stat("./subject.txt", &file);
      time_t * tocheck = &file.st_mtim.tv_sec;
      time_t * point = readCheckpoint();
      printf("%ld %ld\n", *tocheck, *point);
      printf("last checked %s, file last modified %s\n", ctime(tocheck), ctime(point));
      
      if (*tocheck > *point){
            printf("SCAN");
      }
}
