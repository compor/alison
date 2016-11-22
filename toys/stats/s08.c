#include <stdio.h>
#include <stdlib.h>
#include <jemalloc/jemalloc.h>

const int N = 17;

int
main(int argc, char **argv) {
  char *ptr[ N ] = { NULL };

  for (int i = 0; i < N; i++) {
    ptr[i] = (char *) jemalloc_malloc(sizeof(char) * 512 * 1024);
    fprintf(stderr, "%p\n", ptr[i]);
  }

  for (int i = 0; i < N; i++)
    jemalloc_free(ptr[i]);

  jemalloc_malloc_stats_print(NULL, NULL, NULL);

  return 0;
}

