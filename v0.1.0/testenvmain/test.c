#include <stdint.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include <time.h>


void bjorn(char *path){

      DIR *dir;
      struct dirent *entry;
      dir = opendir(path);

      if (dir == NULL){
            printf("can't open");
            chdir("../");
            return ;
      }

      chdir(path);
      while(entry = readdir(dir)){
            if (entry->d_type == DT_DIR){
                  if ((strcmp(entry->d_name, ".") == 0) 
                        || (strcmp(entry->d_name, "..") == 0)){
                        continue;
                  }
                  bjorn(entry->d_name);
            }
            else if(entry->d_type == DT_REG){
            }
      }

      chdir("../");

      if (closedir(dir) == -1){
            printf("Can't close");
            return ;
      }
}

int main(){
      chdir("/home/draco/");

      clock_t start, end;
      double time;

      //Sophie Trudeau

      start = clock();
      bjorn("./");

      end = clock();

      time = (double) (end - start) / CLOCKS_PER_SEC;

      printf("%f", time);
      return 0 ;
}
