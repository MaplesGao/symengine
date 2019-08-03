/* Generated by re2c 1.1.1 */
#line 1 "tokenizer.re"
#include "tokenizer.h"

namespace SymEngine
{

void Tokenizer::set_string(std::string &str)
{
    // The input string must be NULL terminated, otherwise the tokenizer will
    // not detect the end of string. After C++11, the std::string is guaranteed
    // to end with \0, but we check this here just in case.
    SYMENGINE_ASSERT(str[str.size()] == '\0');
    cur = (unsigned char *)(&str[0]);
}

int Tokenizer::lex()
{
    for (;;) {
        tok = cur;

#line 21 "tokenizer.cpp"
        {
            unsigned char yych;
            static const unsigned char yybm[] = {
                0,   0,   0,   0,   0,   0,   0,   0,   0,   32,  32,  32,  0,
                32,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                0,   0,   0,   0,   0,   0,   32,  0,   0,   0,   0,   0,   0,
                0,   0,   0,   0,   0,   0,   0,   0,   0,   192, 192, 192, 192,
                192, 192, 192, 192, 192, 192, 0,   0,   0,   0,   0,   0,   0,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                0,   0,   0,   0,   128, 0,   128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 0,   0,   0,   0,   0,   128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128,
            };
            yych = *cur;
            if (yybm[0 + yych] & 32) {
                goto yy6;
            }
            if (yych <= '>') {
                if (yych <= '-') {
                    if (yych <= '&') {
                        if (yych <= 0x00)
                            goto yy2;
                        if (yych <= '%')
                            goto yy4;
                        goto yy9;
                    } else {
                        if (yych <= '\'')
                            goto yy4;
                        if (yych == '*')
                            goto yy11;
                        goto yy9;
                    }
                } else {
                    if (yych <= '9') {
                        if (yych <= '.')
                            goto yy12;
                        if (yych <= '/')
                            goto yy9;
                        goto yy13;
                    } else {
                        if (yych <= ';')
                            goto yy4;
                        if (yych <= '<')
                            goto yy16;
                        if (yych <= '=')
                            goto yy17;
                        goto yy18;
                    }
                }
            } else {
                if (yych <= '`') {
                    if (yych <= 'Z') {
                        if (yych <= '?')
                            goto yy4;
                        if (yych <= '@')
                            goto yy19;
                        goto yy21;
                    } else {
                        if (yych <= ']')
                            goto yy4;
                        if (yych <= '^')
                            goto yy9;
                        if (yych <= '_')
                            goto yy21;
                        goto yy4;
                    }
                } else {
                    if (yych <= '|') {
                        if (yych <= 'z')
                            goto yy21;
                        if (yych <= '{')
                            goto yy4;
                        goto yy9;
                    } else {
                        if (yych == '~')
                            goto yy9;
                        if (yych <= 0x7F)
                            goto yy4;
                        goto yy21;
                    }
                }
            }
        yy2:
            ++cur;
#line 38 "tokenizer.re"
            {
                return 0;
            }
#line 113 "tokenizer.cpp"
        yy4:
            ++cur;
        yy5 :
#line 37 "tokenizer.re"
        {
            throw SymEngine::ParseError("Unknown token: '" + token() + "'");
        }
#line 119 "tokenizer.cpp"
        yy6:
            yych = *++cur;
            if (yybm[0 + yych] & 32) {
                goto yy6;
            }
#line 39 "tokenizer.re"
            {
                continue;
            }
#line 127 "tokenizer.cpp"
        yy9:
            ++cur;
        yy10 :
#line 41 "tokenizer.re"
        {
            return tok[0];
        }
#line 133 "tokenizer.cpp"
        yy11:
            yych = *++cur;
            if (yych == '*')
                goto yy19;
            goto yy10;
        yy12:
            yych = *++cur;
            if (yych <= '/')
                goto yy5;
            if (yych <= '9')
                goto yy24;
            goto yy5;
        yy13:
            yych = *++cur;
            if (yybm[0 + yych] & 64) {
                goto yy13;
            }
            if (yych <= '^') {
                if (yych <= '@') {
                    if (yych == '.')
                        goto yy26;
                } else {
                    if (yych == 'E')
                        goto yy30;
                    if (yych <= 'Z')
                        goto yy27;
                }
            } else {
                if (yych <= 'd') {
                    if (yych != '`')
                        goto yy27;
                } else {
                    if (yych <= 'e')
                        goto yy30;
                    if (yych <= 'z')
                        goto yy27;
                    if (yych >= 0x80)
                        goto yy27;
                }
            }
        yy15 :
#line 47 "tokenizer.re"
        {
            *(val) = token();
            return Parser::NUMERIC;
        }
#line 167 "tokenizer.cpp"
        yy16:
            yych = *++cur;
            if (yych == '=')
                goto yy31;
            goto yy10;
        yy17:
            yych = *++cur;
            if (yych == '=')
                goto yy33;
            goto yy5;
        yy18:
            yych = *++cur;
            if (yych == '=')
                goto yy35;
            goto yy10;
        yy19:
            ++cur;
#line 42 "tokenizer.re"
            {
                return Parser::POW;
            }
#line 184 "tokenizer.cpp"
        yy21:
            yych = *++cur;
            if (yybm[0 + yych] & 128) {
                goto yy21;
            }
#line 46 "tokenizer.re"
            {
                *(val) = token();
                return Parser::IDENTIFIER;
            }
#line 192 "tokenizer.cpp"
        yy24:
            yych = *++cur;
        yy25:
            if (yych <= '^') {
                if (yych <= '@') {
                    if (yych <= '/')
                        goto yy15;
                    if (yych <= '9')
                        goto yy24;
                    goto yy15;
                } else {
                    if (yych == 'E')
                        goto yy30;
                    if (yych <= 'Z')
                        goto yy27;
                    goto yy15;
                }
            } else {
                if (yych <= 'd') {
                    if (yych == '`')
                        goto yy15;
                    goto yy27;
                } else {
                    if (yych <= 'e')
                        goto yy30;
                    if (yych <= 'z')
                        goto yy27;
                    if (yych <= 0x7F)
                        goto yy15;
                    goto yy27;
                }
            }
        yy26:
            yych = *++cur;
            if (yych == 'E')
                goto yy27;
            if (yych != 'e')
                goto yy25;
        yy27:
            yych = *++cur;
        yy28:
            if (yych <= '^') {
                if (yych <= '9') {
                    if (yych >= '0')
                        goto yy27;
                } else {
                    if (yych <= '@')
                        goto yy29;
                    if (yych <= 'Z')
                        goto yy27;
                }
            } else {
                if (yych <= '`') {
                    if (yych <= '_')
                        goto yy27;
                } else {
                    if (yych <= 'z')
                        goto yy27;
                    if (yych >= 0x80)
                        goto yy27;
                }
            }
        yy29 :
#line 48 "tokenizer.re"
        {
            *(val) = token();
            return Parser::IMPLICIT_MUL;
        }
#line 242 "tokenizer.cpp"
        yy30:
            yych = *(mar = ++cur);
            if (yych <= ',') {
                if (yych == '+')
                    goto yy37;
                goto yy28;
            } else {
                if (yych <= '-')
                    goto yy37;
                if (yych <= '/')
                    goto yy28;
                if (yych <= '9')
                    goto yy39;
                goto yy28;
            }
        yy31:
            ++cur;
#line 43 "tokenizer.re"
            {
                return Parser::LE;
            }
#line 258 "tokenizer.cpp"
        yy33:
            ++cur;
#line 45 "tokenizer.re"
            {
                return Parser::EQ;
            }
#line 263 "tokenizer.cpp"
        yy35:
            ++cur;
#line 44 "tokenizer.re"
            {
                return Parser::GE;
            }
#line 268 "tokenizer.cpp"
        yy37:
            yych = *++cur;
            if (yych <= '/')
                goto yy38;
            if (yych <= '9')
                goto yy39;
        yy38:
            cur = mar;
            goto yy29;
        yy39:
            yych = *++cur;
            if (yych <= '^') {
                if (yych <= '9') {
                    if (yych <= '/')
                        goto yy15;
                    goto yy39;
                } else {
                    if (yych <= '@')
                        goto yy15;
                    if (yych <= 'Z')
                        goto yy27;
                    goto yy15;
                }
            } else {
                if (yych <= '`') {
                    if (yych <= '_')
                        goto yy27;
                    goto yy15;
                } else {
                    if (yych <= 'z')
                        goto yy27;
                    if (yych <= 0x7F)
                        goto yy15;
                    goto yy27;
                }
            }
        }
#line 49 "tokenizer.re"
    }
}

std::string Tokenizer::token()
{
    return std::string((char *)tok, cur - tok);
}

} // namespace SymEngine