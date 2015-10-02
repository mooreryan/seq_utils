#!/bin/bash

DIR="`dirname \"$0\"`"
DIR="`cd \"$DIR\" && pwd`"

ruby "$DIR/wrap.rb" 3 "$DIR/small.fa" > "$DIR/r.wrap.fa"
"$DIR/../bin/clean_and_flatten" 3 < "$DIR/small.fa" > "$DIR/c.wrap.fa"

diff -s "$DIR/r.wrap.fa" "$DIR/c.wrap.fa"

rm "$DIR/r.wrap.fa" "$DIR/c.wrap.fa"
