#include <stdio.h>
#include "Chlara_oldersister.h"

int main(int argc, char *argv[])
{
      DDD dinar1 = {0,0,0};
      append('a', &dinar1);
      append('b', &dinar1);
      append('c', &dinar1);
      printAL2(&dinar1);


      DDD dinar2 = {0,0,0};
      append('b', &dinar2);
      append('3', &dinar2);
      append('2', &dinar2);
      append('1', &dinar2);
      printAL2(&dinar2);

      DDD *D12 = Womb(&dinar1, &dinar2);
      printAL2(D12);

}
