#ifndef LEXER_H
#define LEXER_H

#include <string>
//#include <conio.h>
#include <iostream>
#include <map>

#define Lexer_LPAR 0
#define Lexer_RPAR 1
#define Lexer_NOT 2
#define Lexer_DOT 3
#define Lexer_COMMA 4
#define Lexer_OR 5
#define Lexer_ID 6
#define Lexer_EOF 7


/*!
    \class Lexer

    \brief Класс лексического анализатора, отвечающего за распознавание лексем
*/
class Lexer
{
public:

    int line;
    int column;
    int sym;
    std::string value;

    void nextTok();

    Lexer();
    Lexer(std::string in);
    ~Lexer();

private:

    char ch;
    std::string in;
    int symbol;

    std::map<char, int> symbols;
    std::map<std::string, int> words;
    void error(std::string msg);
    void getc();

};

#endif // LEXER_H
