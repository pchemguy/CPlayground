#!/bin/bash
#
set -euo pipefail
IFS=$'\n\t'

cleanup_EXIT() { 
  echo "EXIT clean up: $?" 
}
trap cleanup_EXIT EXIT

cleanup_TERM() {
  echo "TERM clean up: $?"
}
trap cleanup_TERM TERM

cleanup_ERR() {
  echo "ERR clean up: $?"
}
trap cleanup_ERR ERR


main() {
  readonly SOURCE="memcpydemo"
  if [[ "${MSYSTEM}" == "MINGW64" ]]; then
    readonly ARCH="x64"
  else
    readonly ARCH="x32"
  fi

  rm -rf "./${ARCH}"
  mkdir -p "./${ARCH}"
  
  gcc -E ${SOURCE}.c -o ${SOURCE}_pp.c
  # DO NOT ENABLE OPTIMIZATION for memcpy test
  gcc -Wall ${SOURCE}_pp.c -o ${SOURCE}.exe
  mv ${SOURCE}.exe "./${ARCH}"
  mv ${SOURCE}_pp.c "./${ARCH}"

  return 0
}


main "$@"
exit 0