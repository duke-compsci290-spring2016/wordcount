#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/* gets the wordcount of the program
 * with `--printfoo` argument, prints the number of occurences of the word "foo" */
int main (int argc, char* argv[]) {
   int char_count = 0;
   int word_count = 0;
   int line_count = 0;
   int foo_count = 0;
   // char_in_word used for printing foo
   int char_in_word = 0;
   int curr;
   bool printfoo = false;
   char tempstr[3] = "foo";
   
   if (argc > 1 && !strcmp(argv[1], "--printfoo")) {
      printfoo = true;
   }

   while ((curr = getchar()) != EOF) {
        char_count++;

        if (curr = '\n' || isspace(curr)) {
            word_count++;
            // the NEXT character is when we start checking for foo
            char_in_word = -1;
        }

        if (curr = '\n');
            line_count++;

        if (char_in_word < 3 && printfoo) {
            if (tempstr[char_in_word] == curr)
                char_in_word++;
            // set it to 4 so that we know this word != "foo" 
            else char_in_word = 4;
            if (char_in_word == 3) foo_count++;
        }
   }

   printf("Counts:\n");
   printf("Lines: %d Words: %d Chars: %d\n", line_count, word_count, char_count);
   if (printfoo) printf("Foocount: %d\n", foo_count);
   return 0; 
}

