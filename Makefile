all:
	gcc -Wall burp.c -o burp

check:
	cppcheck burp.c

