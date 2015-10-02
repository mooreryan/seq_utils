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
#include <stdlib.h>
#include <assert.h>
#include "utilities.h"

int main(int argc, char* argv[])
{
  int wrap_length = atoi(argv[1]);
  assert(wrap_length > 0);

  int c = 0;
  int line_idx = 0;
  int first_char = 1;
  int in_header = 0;
  int line_size = 10000;

  char* line = malloc(sizeof(char) * line_size);

  while( (c = getchar()) ) {
    if (line_idx >= line_size) { /* check if line needs to expand */
      line_size *= 2;
      char* tmp = realloc(line, sizeof(char) * line_size);
      assert(tmp != NULL);

      line = tmp;
      assert(line != NULL);
    }

    if (first_char == 1) {
      if (c == '>') {
        first_char = 0;
        in_header = 1;
      } else {
        fputs("ERROR: data doesn't look like a fasta file!\n", stderr);

        return 1;
      }
    }

    if (c == EOF) {
      /* do the thing at the end */
      line[line_idx] = '\0';
      print_sequence(line, line_idx, wrap_length);

      free(line);
      return 0;
    }

    if (c == '\n' && in_header == 1) { /* end of a line, the header is now done */
      line[line_idx] = '\0';

      print_clean_header(line, line_idx);

      in_header = 0;
      line_idx = 0; /* reset the line_idx */
    } else if (c == '>' && in_header == 0) { /* start of line, start of new header */
      line[line_idx] = '\0';

      print_sequence(line, line_idx, wrap_length);

      in_header = 1;

      line[0] = '>';
      line_idx = 1;
    } else if (c != '\n') {
      line[line_idx] = c;
      line_idx += 1;
    }
  }
}
