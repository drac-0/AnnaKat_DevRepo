#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

/*
# if a file hasn't modified since the last scan, then it's a waste of time to check it

That's it fella. That's the whole thing in this patch.
*/

//do i really need to box a function for this?. We'll see about that later
//
//


// this is for today, let's see if i can push more 
//
// What happen (Etherane):
// 1. Struct tm checkpoint write
// 2. Struct tm checkpoint read
//
// What's need to be changed:
// 1. time_t instead of struct tm stored


struct tm * tmNow(){
      struct tm * now;
      time_t t = time(NULL);
      now = localtime(&t);

      printf("%s \n", asctime(now));
}

struct time {
      short sec;
      short min;
      short ho;
      short day;
      int month;
      int year;
};

void Checkpoint(){
      struct tm * point;
      time_t t = time(NULL);

      point = localtime(&t);
      int Fp = open("log.bin", O_WRONLY | O_APPEND);
      write(Fp, point, sizeof(int) * 9);
      close(Fp);
}

struct tm * readCheckpoint(){
      struct tm * pointfile = malloc(sizeof(int) * 9);
      int Fp = open("log.bin", O_RDONLY);
      read(Fp,pointfile,sizeof(int) * 9);
      return pointfile;
}

int main(){
      Checkpoint();

      struct tm * readpoint;
      readpoint = readCheckpoint();

      printf("%s", asctime(readpoint));
}
