//// burp.c --- send argv[1] bytes of random data to stdout
//// Copyright 2001 Evans Winner

//// compile with, eg. gcc burp.c -o burp.exe

#include <stdlib.h>
#include <time.h>

// This is a global counter to add to the random seed to help make it
// a bit more randomish.
int count=1;

// Help message if wrong syntax is used or if no sintax is used.
int help(void)
{
  printf("\n burp 0.1\n");
  printf(" Copyright 2001, thorne\n\n");
  printf(" PURPOSE: Generate an N-length stream of pseudo-random alpha-numeric\n");
  printf(" characters. Can be used with standard DOS redirection to fill test\n");
  printf(" files with data, generate random filenames from batch files, etc.\n\n");
  printf(" USAGE: burp N\n");
  printf(" --where N is an integer from from 1 to 65535, inclusive, representing the \n");
  printf(" number of bytes to output. Do not use commas in N (i.e. 4000, not 4,000).\n");
  printf(" WARNING: Results are only slightly pseudo-random. Long streams of output will\n");
  printf(" always contain many repeated strings. Also, if called twice in the same system\n");
  printf(" second, output will be identical for the length of output both calls have in\n");
  printf(" common. Output is 0-9 and A-Z (uppercase only).\n");
  return(0);
}

int main(int argc, char *argv[]) 
{
  unsigned int length;
  char random_num;
  char temp_rand;
  int seed;
  
  // Wrong number of args...
  if (argc != 2)
    {
      help();
      return(0);
    }
  
  // Either asked for 0 or atoi returned 0, which means text or other
  // garbage, or greater than int will hold.
  if (atol(argv[1]) < 1 || atol(argv[1]) > 65535)
    {
      help();
      return(0);
    }
  
  // Ok, so it looks like we have good data. We just do a loop the
  // number of times asked for, and every time, we pick a random ASCII
  // value and output it.
  length = atoi(argv[1]);
  srand(time(0));
  seed = rand();
  
  while (length > 0)
    {
      srand(seed);
      temp_rand = (rand() % 43) + 48;
      seed = temp_rand + ++count;
      if (temp_rand >= 58 && temp_rand <= 64) continue;
      random_num = temp_rand;
      printf("%c", random_num);
      length--;
    }
  return(0);
}

