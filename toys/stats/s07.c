#include <stdio.h>
#include <stdlib.h>
#include <jemalloc/jemalloc.h>

#include <unistd.h>


int
main(int argc, char **argv) {
  char *ptr = NULL;
  char *ptr2 = NULL;

  fprintf(stderr, "pid = %d\n", getpid());

  ptr = (char *) jemalloc_malloc(sizeof(char) * 16 * 1024);
  fprintf(stderr, "%p\n", ptr);
  sleep(15);

  fprintf(stderr, "post free\n");
  jemalloc_free(ptr);
  sleep(15);

  ptr2 = (char *) jemalloc_malloc(sizeof(char) * 4 * 1024 * 1024);
  fprintf(stderr, "%p\n", ptr2);
  jemalloc_free(ptr);
  sleep(15);

  jemalloc_malloc_stats_print(NULL, NULL, NULL);

  return 0;
}

