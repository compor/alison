#include <stdlib.h>
#include <jemalloc/jemalloc.h>


int
main(int argc, char **argv) {
  jemalloc_malloc(sizeof(char) * 10);
  jemalloc_malloc(sizeof(char) * 10);

  return 0;
}

