#include "lexer.h"

Lexer::Lexer()
{
    line = 1;
    column = 0;
    sym = -1;
    ch = ' ';
    in = "";
    symbol = 0;

    symbols = { {'(', Lexer_LPAR},
                {')', Lexer_RPAR},
                {',', Lexer_COMMA},
                {'.', Lexer_DOT},
                {'!', Lexer_NOT},
                {'-', Lexer_NOT},
                {'~', Lexer_NOT },
                {'|', Lexer_OR }, };

    words = { { "v", Lexer_OR },
                { "or", Lexer_OR },
                { "not", Lexer_NOT }};
}

inline Lexer::Lexer(std::string in)
{
    this->in = in;
    line = 1;
    column = 0;
    sym = -1;
    ch = ' ';
    symbol = 0;

    symbols = { { '(', Lexer_LPAR },
    { ')', Lexer_RPAR },
    { ',', Lexer_COMMA },
    { '.', Lexer_DOT },
    { '!', Lexer_NOT },
    { '-', Lexer_NOT } };

    words = { { "v", Lexer_OR },
    { "or", Lexer_OR },
    { "not", Lexer_NOT } };
}

Lexer::~Lexer()
{
}

inline void Lexer::error(std::string msg)
{
    std::cout << "Lexer error: " << msg << " at line " << line << " column " << column << std::endl;
    exit(1);
}

inline void Lexer::getc()
{
    if (in == "") {
        std::cin.read(&ch, 1);
    }
    else {
        ch = in[symbol];
        symbol++;
    }

    if (ch == '\n') {
        line++;
        column = 0;
    }
    else {
        column++;
    }
}

inline void Lexer::nextTok()
{
    sym = -1;
    value = "";

    while (sym < 0) {
        if (ch < 1) {
            sym = Lexer_EOF;
        }
        else if (isspace(ch)) {
            getc();
        }
        else if (ch == '#') {
            while ( (ch != '\n') && (ch != '\0') ) {
                getc();
            }
        }
        else if (symbols.find(ch) != symbols.end()) {
            sym = symbols.find(ch)->second;
            getc();
        }
        else if (isalpha(ch)) {
            std::string ident = "";

            while (isalpha(ch) || isdigit(ch)) {
                ident += ch;
                getc();
            }

            if (words.find(ident) != words.end()) {
                sym = words.find(ident)->second;
            }
            else {
                sym = Lexer_ID;
                value = ident;
            }
        }
        else {
            std::string msg = "unexpected symbol \"";
            msg += ch;
            msg += "\"";
            error(msg);
            return;
        }
    }
}
