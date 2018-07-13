ROOT_DIR="$(dirname ${BASH_SOURCE[0]})/../"

block() {
  awk \
    -f ${ROOT_DIR}/lib/block_split.awk \
    block=$1 \
    ${INPUT_FILE}
}

block_count() {
  awk '
    BEGIN    { c=0 }
    /^[^\ ]/  { c+=1 }
    END      { print c }
  ' ${INPUT_FILE}
}

block_order() {
  block 0 \
    | sed '1d' \
    | awk '{ print $0,NR }' \
    | sort \
    | grep -E -o [0-9]+$ \
    | tr '\n' ' ' \
    | sed 's/\ $//g'
}
