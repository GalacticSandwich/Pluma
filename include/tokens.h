/**
	FILE: tokens.h
	AUTHOR: Aaron N. (GalacticSandwich)

	...
*/

#ifndef _TOKENS_H_
#define _TOKENS_H_

typedef enum {
    TK_EOF              = 0x0000,

    RS_BANG,            // '!'
    RS_OCTOTHORPE,      // '#'
    RS_DOLLARSIGN,      // '$'
    RS_MODULO,          // '%'
    RS_AMPERSAND,       // '&'
    RS_APOSTROPHE,      // '''
    RS_OPENPARENS,      // '('
    RS_OPENCOMM,        // '(*'
    RS_CLOSEPARENS,     // ')'
    RS_STAR,            // '*'
    RS_CLOSECOMM,       // '*)'
    RS_PLUS,            // '+'
    RS_COMMA,           // ','
    RS_DASH,            // '-'
    RS_RIGHTARROW,      // '->'
    RS_POINT,           // '.'
    RS_SLASH,           // '/'
    RS_COLON,           // ':'
    RS_COLONEQUALS,     // ':='
    RS_SEMICOLON,       // ';'
    RS_LEFTANGLE,       // '<'
    RS_LEFTEQUALS,      // '<='
    RS_EQUALSIGN,       // '='
    RS_DOUBLEQUALS,     // '=='
    RS_RIGHTANGLE,      // '>'
    RS_RIGHTEQUALS,     // '>='
    RS_DOUBLERIGHT,     // '>>'
    RS_QUESTION,        // '?'
    RS_ATSIGN,          // '@'
    RS_OPENBRACK,       // '['
    RS_BACKSLASH,       // '\'
    RS_CLOSEBRACK,      // ']'
    RS_CARAT,           // '^'
    RS_OPENBRACE,       // '{'
    RS_VERTICBAR,       // '|'
    RS_CLOSEBRACE,      // '}'
    RS_TILDE,           // '~'

    RW_AND,             // 'AND'
    RW_BEGIN,           // 'BEGIN'
    RW_CASE,            // 'CASE'
    RW_CONST,           // 'CONST'
    RW_DEFAULT,         // 'DEFAULT'
    RW_DO,              // 'DO'
    RW_DOWNTO,          // 'DOWNTO'
    RW_ELSE,            // 'ELSE'
    RW_ELSEIF,          // 'ELSEIF'
    RW_END,             // 'END'
    RW_FOR,             // 'FOR'
    RW_FOREACH,         // 'FOREACH'
    RW_FUNCTION,        // 'FUNCTION'
    RW_IF,              // 'IF'
    RW_IN,              // 'IN'
    RW_INTERFACE,       // 'INTERFACE'
    RW_ITEM,            // 'ITEM'
    RW_NOT,             // 'NOT'
    RW_OF,              // 'OF'
    RW_OR,              // 'OR'
    RW_RECORD,          // 'RECORD'
    RW_REPEAT,          // 'REPEAT'
    RW_ROUTINE,         // 'ROUTINE'
    RW_SELECT,          // 'SELECT'
    RW_STEP,            // 'STEP'
    RW_THEN,            // 'THEN'
    RW_TO,              // 'TO'
    RW_TYPE,            // 'TYPE'
    RW_UNTIL,           // 'UNTIL'
    RW_WHILE,           // 'WHILE'

    RT_BYTE,            // 'Byte'
    RT_FLOAT,           // 'Float'
    RT_FLOAT32,         // 'Float32'
    RT_FLOAT64,         // 'Float64'
    RT_FLOAT128,        // 'Float128'
    RT_INT,             // 'Int'
    RT_INT8,            // 'Int8'
    RT_INT16,           // 'Int16'
    RT_INT32,           // 'Int32'
    RT_INT64,           // 'Int64'
    RT_LOGIC,           // 'Logic'
    RT_RUNE,            // 'Rune'
    RT_STRING,          // 'String'
    RT_UINT,            // 'UInt'
    RT_UINT8,           // 'UInt8'
    RT_UINT16,          // 'UInt16'
    RT_UINT32,          // 'UInt32'
    RT_UINT64,          // 'UInt64'
    RT_WORD,            // 'Word'

    TK_NUMERICLIT,
    TK_STRINGLIT,
    TK_IDENTIFIER,

    TK_UNKNOWN
} ETokenType;

/**
    Struct representing a high-level language token.
*/
typedef struct {
    // the buffer containing the token text content
    char* cont;
    // the length of the content buffer
    int len;
    // the type of the token
    ETokenType type;
} Token;

#endif /* _TOKENS_H_ */
