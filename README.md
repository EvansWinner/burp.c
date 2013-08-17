# burp.c

## Installation

Compile with `cc burp.c -o burp` or some equivalent.  Then perhaps
`sudo cp burp /usr/local/bin` and `sudo chmod a+x /usr/local/bin/burp`.

## Purpose

From the help text: "Generate an N-length stream of pseudo-random
alpha-numeric characters. Can be used with standard DOS redirection to
fill test files with data, generate random filenames from batch files,
etc."

`burp` is a tiny utility (which I originally used for MS-DOS batch
scripting) that outputs pseudo-random text, basically for two
purposes: filling up test files with test data, and creating random
file names, again usually for testing purposes.  I have no doubt that
there are many much better ways to do this, but this seemed quick and
easy it has the virtue of being simple, tiny, stand-alone, portable,
and it requires nothing but a C compiler.

## Use

> $ burp N

--where N is an integer from from 1 to 65535, inclusive, representing
the number of bytes to output. Do not use commas in N (i.e. 4000, not
4,000). 

WARNING: Results are only slightly pseudo-random. Long streams of
output will always contain many repeated strings.

WARNING: Uses the time() as a random seed, and will therefore output
the same results if used more than once in the same clock second.  You
get what you pay for.

Output is 0-9 and A-Z (uppercase only).
