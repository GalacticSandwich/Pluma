/**
	FILE: scanner.c
	AUTHOR: Aaron N. (GalacticSandwich)

	...
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

Scanner new_Scanner()
{
    Scanner scanner;

    scanner->buffer = NULL;
    scanner->nlines = 0;
    scanner->nchars = 0;
    scanner->currln = 0;
    scanner->currci = 0;
    scanner->charsbl = 0;

    return scanner;
}

void scanner_Init( Scanner* scanner, char const* cont )
{
    if ( scanner->buffer )
        scanner_FreeBuf( scanner );

    int len = strlen( cont );
    scanner->buffer = ( char* ) malloc( ( len + 1 ) * sizeof( char ) );

    for ( int i = 0; cont[ i ]; i++ ) {
        scanner->buffer[ i ] = cont[ i ];
        scanner->nchars++;

        if ( cont[ i ] == '\n' )
            scanner->nlines++;
    }

    scanner->buffer[ len ] = '\0';
}

void scanner_FreeBuf( Scanner* scanner )
{
    free( scanner->buffer );
    *scanner = new_Scanner();
}

/**
    Helper function, fetches the next character pointed to
    in a scanner by the current character index, then increments the index.

    --- scanner - the scanner to fetch from
*/
static char scanner_NextCh( Scanner* scanner )
{
    if ( scanner->currci == scanner->nchars )
        return '\0';

    char ch = scanner->buffer[ scanner->currci++ ];

    if ( ch == '\n' ) {
        scanner->currln++;
        scanner->charsbl = scanner->currci - 1;
    }

    return ch;
}

/**
    Helper function, fetches the next string of alphanumeric characters pointed to by
    the scanner's current character index. Allocates memory for the resulting string
    in the heap.

    --- scanner - the scanner to read from
*/
static char* scanner_NextStr( Scanner* scanner )
{
    char* str = ( char* ) malloc( sizeof( char ) );

    int i = 0; char ch;
    while ( isalnum( ch = scanner_NextCh( scanner ) ) ) {
        str[ i++ ] = ch;
        str = ( char* ) realloc( ( i + 1 ) * sizeof( char ) );
    }

    str[ i ] = '\0';
    return str;
}

/**
    Helper function, fetches the next string of whitespace characters pointed to by
    the scanner's current character index. Allocates memory for the resulting string
    in the heap.

    --- scanner - the scanner to read from
*/
static char* scanner_NextSpace( Scanner* scanner )
{
    char* str = ( char* ) malloc( sizeof( char ) );

    int i = 0; char ch;
    while ( isspace( ch = scanner_NextCh( scanner ) ) ) {
        str[ i++ ] = ch;
        str = ( char* ) realloc( ( i + 1 ) * sizeof( char ) );
    }

    str[ i ] = '\0';
    return str;
}

/**
    Helper function, fetches the next string of numeric digit characters pointed to by
    the scanner's current character index. Allocates memory for the resulting string
    in the heap.

    --- scanner - the scanner to read from
*/
static char* scanner_NextNum( Scanner* scanner )
{
    char* str = ( char* ) malloc( sizeof( char ) );

    int i = 0; char ch;
    while ( isdigit( ch = scanner_NextCh( scanner ) ) ) {
        str[ i++ ] = ch;
        str = ( char* ) realloc( ( i + 1 ) * sizeof( char ) );
    }

    str[ i ] = '\0';
    return str;
}

/**
    Helper function, tests and returns true if a character is a valid ASCII symbol.

    --- ch - the character to test
*/
static bool issymb( char ch )
{
    return ch >= '!' && ch <= '~' && !isdigit( ch ) && !isalnum( ch ) && !isspace( ch );
}

/**
    Helper function, fetches the next string of symbol characters pointed to by
    the scanner's current character index. Allocates memory for the resulting string
    in the heap.

    --- scanner - the scanner to read from
*/
static char* scanner_NextSymb( Scanner* scanner )
{
    char* str = ( char* ) malloc( sizeof( char ) );

    int i = 0; char ch;
    while ( issymb( ch = scanner_NextCh( scanner ) ) ) {
        str[ i++ ] = ch;
        str = ( char* ) realloc( ( i + 1 ) * sizeof( char ) );
    }

    str[ i ] = '\0';
    return str;
}

char* scanner_Next( Scanner* scanner )
{
    if ( isspace( scanner->buffer[ scanner->currci ] ) )
        return scanner_NextSpace( scanner );
    if ( isdigit( scanner->buffer[ scanner->currci ] ) )
        return scanner_NextNum( scanner );
    if ( isalpha( scanner->buffer[ scanner->currci ] ) )
        return scanner_NextStr( scanner );

    return scanner_NextSymb( scanner );
}
