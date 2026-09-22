#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>


void Checkpoint(){
      time_t local = time(NULL);
      int Fp = open("log.bin", O_WRONLY | O_CREAT);
      if (Fp == -1) {
            perror("An error encountered while trying to open the file");
      }
      write(Fp,&local, sizeof(local));
      close(Fp);
}

time_t readCheckpoint(){
      time_t readloc;
      int Fp = open("./log.bin" , O_RDONLY);
      if (Fp == -1) {
            perror("An error encountered while trying to open the file");
      }
      read(Fp, &readloc, sizeof(time_t));
      close(Fp);
      return readloc;
}
/*
int main(){
      Checkpoint();
}
*/
