#include <stdlib.h>
#include <jemalloc/jemalloc.h>


int
main(int argc, char **argv) {
  jemalloc_malloc_stats_print(NULL, NULL, NULL);

  return 0;
}

