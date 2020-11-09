// burp.c --- send argv[1] bytes of random ascii data to stdout
// Copyright 2001 Evans Winner

// compile with, eg. gcc burp.c -o burp.exe

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Help message if wrong syntax is used or if no syntax is used.
int help(void) {
  printf("\n burp\n");
  printf(" Copyright 2001, Evans Winner\n\n");
  printf(
      " PURPOSE: Generate an N-length stream of pseudo-random alpha-numeric\n");
  printf(
      " characters. Can be used with standard DOS redirection to fill test\n");
  printf(
      " files with data, generate random filenames from batch files, etc.\n\n");
  printf(" USAGE: burp N\n");
  printf(" --where N is an integer from from 1 to 65535, inclusive, "
         "representing the \n");
  printf(" number of bytes to output. Do not use commas in N (i.e. 4000, not "
         "4,000).\n");
  printf(" WARNING: Results are only slightly pseudo-random. Long streams of "
         "output will\n");
  printf(" always contain many repeated strings. Also, if called twice in the "
         "same system\n");
  printf(" second, output will be identical for the length of output both "
         "calls have in\n");
  printf(" common. Output is 0-9 and A-Z (uppercase only).\n");
  return (0);
}

int main(int argc, char *argv[]) 
{
  unsigned int len;
  char n;
  srand(time(NULL));

  if (argc != 2)
  { // wrong number of args
    help();
    return (1);
  }

  // args out of bounds
  if (atol(argv[1]) < 1 || atol(argv[1]) > 65535)
  {
    help();
    return (1);
  }
 
  // Loop argv[1] times; each time pick
  // a random ASCII value and output it
  len = atoi(argv[1]);
  while (len > 0) {
    n = (rand() % 43) + 48;
    if (n >= 58 && n <= 64)
      continue;
    printf("%c", n);
    len--;
  }

  return (0);

}
