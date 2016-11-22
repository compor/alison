#include <stdlib.h>
#include <jemalloc/jemalloc.h>


int
main(int argc, char **argv) {
  char *ptr = (char *) jemalloc_malloc(sizeof(char) * 16 * 1024);
  jemalloc_free(ptr);

  jemalloc_malloc_stats_print(NULL, NULL, NULL);

  return 0;
}

