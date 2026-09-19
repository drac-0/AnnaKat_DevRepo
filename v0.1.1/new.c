#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

/*
# if a file hasn't modified since the last scan, then it's a waste of time to check it

That's it fella. That's the whole thing in this patch.
*/

//do i really need to box a function for this?. We'll see about that later
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


int main(){
      struct stat file;
      stat("./Readme.md", &file);
      struct tm * now;
      struct tm * fltm;


      fltm = localtime(&file.st_mtim.tv_sec);
      printf("%s", ctime(&file.st_mtim.tv_sec));

      //printf("%d\n", ctime(file.st_mtim));

      /*
      time_t t = time(NULL);
      now = localtime(&t);


      // strip down the struct. I'll do it later

      int len ;
      int Fp = open("log.bin", O_WRONLY | O_APPEND);
      write(Fp, &len, strlen(wtest));

      close(Fp);
      */
}
