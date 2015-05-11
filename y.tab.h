#define LABEL 257
#define STR 258
#define ARITH 259
#define LOG 260
#define DTTF 261
#define CTTF 262
#define IO 263
#define REG8 264
#define REG16 265
#define MEM 266
#define IBYTE 267
#define IWORD 268
#define CL 269
#define CON 270
#define COLON 271
#define E 272
#define DB 273
#define DW 274
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int num;
  char str[30];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
