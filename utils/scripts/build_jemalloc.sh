#!/usr/bin/env bash

# initialize configuration vars

SRC_DIR=""
INSTALL_PREFIX=""


# set configuration vars

if [ -z "$1" ]; then 
  echo "error: source directory was not provided" 

  exit 1
fi

SRC_DIR=$1

if [ -z "$2" ]; then 
  INSTALL_PREFIX="${SRC_DIR}/../install/"
else
  INSTALL_PREFIX="$2"
fi


# print configuration vars

echo "info: printing configuation vars"
echo "info: source dir: ${SRC_DIR}"
echo "info: install dir: ${INSTALL_PREFIX}"
echo ""


pushd "$SRC_DIR"
./autogen.sh
popd


CC=clang \
  $SRC_DIR/configure \
  --enable-prof \
  --enable-debug \
  --with-jemalloc-prefix="jemalloc_" \
  --prefix="$INSTALL_PREFIX"

RC=$?
[ "$RC" -ne 0 ] && exit $RC


make && make install

RC=$?
exit $RC

