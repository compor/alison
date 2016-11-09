
CC=clang \
  $1/configure \
  --enable-prof \
  --enable-debug \
  --with-jemalloc-prefix="jemalloc_" \
  --prefix="$1/install-jemalloc/"

