/*
Copyright 2015 Ryan Moore
Contact: moorer@udel.edu

This file is part of seq_utils.

seq_utils is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

seq_utils is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with seq_utils.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>

int is_char_bad(int c) {
  if (c == '_' || c == '.' || c == ',' || c == '/' || c == '\\' || c == '|' || c == ' ' || c == '=' || c == '-') {
    return 1;
  } else {
    return 0;
  }
}

void print_clean_header(char* header, int length)
{
  int i = 0;
  int c = 0;
  int last_printed = 0;

  for (i = 0; i < length; i++) {
    c = header[i];

    if (is_char_bad(c) && last_printed != '_') {
      putchar('_');
      last_printed = '_';
    } else if (!is_char_bad(c)) {
      putchar(c);
      last_printed = c;
    }
  }

  putchar('\n');
}

void print_sequence(char* sequence, int seq_length, int wrap_length)
{
  int i = 0;

  for (i = 0; i < seq_length; i++) {
    if (i != 0 && i % wrap_length == 0) { /* wrap the lines every 70 chars */
      putchar('\n');
    }

    putchar(sequence[i]);
  }

  putchar('\n');
}
