function _exec() {
  i=`expr $i + 1`
  echo "$i: Starting $1 $2"
  $1 $2
  if test $? -ne 0; then
    echo "$1 $2 Failed."
    exit $i
  fi
}

i=0

_exec "aclocal" ""
_exec "autoreconf" "-i"
_exec "automake" "-a"
_exec "autoconf" ""
_exec "automake" "--add-missing"
_exec "autoreconf" "-v"

echo
echo "autogen.sh Successfully finished."
exit 0
