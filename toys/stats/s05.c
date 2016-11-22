#include <stdio.h>
#include <stdlib.h>
#include <jemalloc/jemalloc.h>


int
main(int argc, char **argv) {
  char *ptr = NULL;
  char *ptr2 = NULL;

  ptr = (char *) jemalloc_malloc(sizeof(char) * 16 * 1024);
  fprintf(stderr, "%p\n", ptr);
  jemalloc_free(ptr);
  ptr2 = (char *) jemalloc_malloc(sizeof(char) * 4 * 1024 * 1024);
  fprintf(stderr, "%p\n", ptr2);
  jemalloc_free(ptr2);

  jemalloc_malloc_stats_print(NULL, NULL, NULL);

  return 0;
}

