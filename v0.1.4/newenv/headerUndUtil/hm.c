#include "sha.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

typedef struct{
      u32t sha[8];
      char * name;
}hashed;

hashed * hashtable[SL] ;
uint Ihash(u32t sha[8]){
      uint hashval = 0;
      for (int i = 0; i < 8; i++){
            hashval += (sha[i] * 3);
      }
      return hashval;
}

void insertToHm(u32t sha[8], char *name){
      hashed * data = malloc(sizeof(hashed));
      uint index,counter;
      data->name = name;
      index = Ihash(sha) % SL;
      for (int i = 0 ; i < 8 ; i++){
            data->sha[i] = sha[i];
      }

      check:

      if (counter == SL){
            printf("ALERT:HASHMAP IS FULL\n");
            goto end;
      }
      if (hashtable[index] != NULL){
            index+= 1;
            if (index >= SL){
                  index = 0;
            }
            counter += 1;
            goto check;
      }

      hashtable[index] = data;

      end:
}

hashed * get(u32t sha[8]){
      hashed * target = malloc(sizeof(hashed));
      uint t = Ihash(sha) % SL;
      uint count = 0;
      //verify
      while(count < SL ){
            if (hashtable[t] != NULL){
                  printf("%d | sha of %s  = " , t, hashtable[t]->name);
                  for (int i = 0; i < 8; i++ ){
                        printf("%08x", hashtable[t]->sha[i]);
                  }
            }

            else{
                  printf("%d | UNALLOCATED", t);
            }

            printf("\n");
            t++;

            if (t >= SL) t = 0;
            count++;
      }
      return target;
}

//named this main function to hmload later
int main(){
      u32t sha[8];
      DIR *dir;
      struct dirent *entry;
      dir = opendir("/home/draco/vode/AnnaKav/db/");

      while(entry = readdir(dir)){
            chdir("/home/draco/vode/AnnaKav/db/");
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
                  continue;
            }
            printf("opening file %s\n", entry->d_name);

            int Fp = open(entry->d_name, O_RDONLY);
            if (Fp == -1 ){
                  printf("ERROR");
            }

            ssize_t n = read(Fp, &sha[0], sizeof(u32t));
            int i = 1;
            while (n > 0){
                  n = read(Fp, &sha[i++],sizeof(u32t));
            }

            insertToHm(sha, "sarah keylogger");

            /*
            for (int j = 0 ; j < SL; j++){
                  if (hashtable[j] != NULL){
                        printf("%d | sha of %s  = " , j, hashtable[j]->name);
                        for (int i = 0; i < 8; i++ ){
                              printf("%08x", hashtable[j]->sha[i]);
                        }
                  }

                  else{
                        printf("%d | UNALLOCATED", j);
                  }
                  printf("\n");
            }
            */
            hashed * data = get(sha);
      }
}
