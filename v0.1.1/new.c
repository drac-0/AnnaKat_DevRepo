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
      write(Fp,&local, sizeof(local));
      close(Fp);
}

time_t * readCheckpoint(){
      time_t * readloc = malloc(sizeof(time_t));
      int Fp = open("./log.bin" , O_RDONLY);
      read(Fp, readloc, sizeof(time_t));
      close(Fp);
      return readloc;
}

