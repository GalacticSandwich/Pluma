/**
	FILE: scanner.h
	AUTHOR: Aaron N. (GalacticSandwich)

	...
*/

#ifndef _SCANNER_H_
#define _SCANNER_H_

/**
    Struct representing a scanner, which uses a buffer to parse and separate strings.
*/
typedef struct {
    // the buffer containing characters to read
    char* buffer;
    // the number of lines and characters contained in the buffer
    int nlines, nchars;
    // the current line and current character being pointed to, to read from next
    int currln, currci;
    // the number of characters that came before the last newline
    int charsbl;
    // the end-of-scanner character
    char eosch;
} Scanner;

/*
    ==== SCANNING SEGMENTS OUT OF A BUFFER ====

    The Scanner struct can be used to scan out string segments of four types, consisting of
    different character types for each string type, and are identified by the first character
    that is being pointed to by the current character index:

    TYPE            FIRST CHARACTER                             CHARACTER CONTENT

    Whitespace      Any Whitespace (isspace( ch ))              Any Whitespace (isspace( ch ))
    Numeric         Any Digit (isdigit( ch ))                   Any Digit (isspace( ch ))
    Alphanumeric    Any Alphabetic Character (isalpha( ch ))    Any Alphanumeric Character (isalnum( ch ))
    Symbolic        Any ASCII Symbol (issymb( ch ))             Any ASCII Symbol (issymb( ch ))

    These strings are considered separators of each other from each other. String types can only 
    be consistent of a certain type of character in the ASCII Character Set. This is considered 
    a neutral splitting, from whence tokens can easily be made.

    Example Input:
    "This is an++-- example      123numbers numbers123\n"

    Example Strings From Output:
    - "This"
    - " "
    - "is"
    - " "
    - "an"
    - "++--"
    - "example"
    - "      "
    - "123"
    - "numbers"
    - "numbers123"
    - "\n"
*/

/**
    Returns the fields of an empty scanner.
*/
Scanner new_Scanner();

/**
    Initilizes the fields of a scanner using a content string. Allocates
    space for the scanner buffer contents on the heap.

    --- scanner - the scanner to initialize
    ---    cont - the string content to use
*/
void scanner_Init( Scanner* scanner, char const* cont );

/**
    Frees/clears the scanner buffer content. Reinitializes empty
    scanner fields.

    --- scanner - the scanner to clear
*/
void scanner_FreeBuf( Scanner* scanner );

/**
    Scans the next string from the scanner, separated by spaces. Memory
    for the returned string allocated on the heap.

    --- scanner - the scanner to scan from
*/
char* scanner_Next( Scanner* scanner );

#endif /* _SCANNER_H_ */
