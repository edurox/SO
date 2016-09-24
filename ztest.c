// Create a zombie process that
// must be reparented at exit.

#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  int n, p;
  for(n=0; n<10000; n++){
      printf (1,"WTF-%d\n", n);
      fork();
    for(p=0; p<10000; p++){
      if (n == 9999) {
        if(fork() > 0){
          printf(1, "HEY-%d\n", p);
        }
        exit();
      }
    }
  }
  return 0;
}
