#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "pass2.y"
#include "functions.h"
FILE *op,*intr;
extern FILE *yyin;
char *c,h[14],h1[14];
int f=0,locctr=0,mod=0,lineno=1,s=0;
int err[20],front=0;
extern struct instrn t;
int yyerrstatus,errf=0;
SYMBOL *temp;
#line 13 "pass2.y"
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
#line 41 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,   13,   13,   13,   13,   14,   16,   16,   16,
    9,    9,   10,   10,   15,   15,   15,   15,    1,    1,
    1,    1,    2,    2,    2,    8,    8,    3,    3,    4,
    4,    6,    6,    6,    6,    7,    7,   12,   12,   12,
   12,   12,   12,   12,   12,    5,    5,   11,   11,
};
static const short yylen[] = {                            2,
    2,    0,    2,    2,    3,    1,    2,    2,    2,    1,
    3,    1,    3,    1,    1,    1,    1,    1,    2,    2,
    2,    1,    4,    4,    2,    1,    1,    2,    2,    2,
    2,    3,    3,    3,    3,    1,    1,    2,    1,    3,
    1,    1,    1,    1,    1,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    6,    0,   15,   16,   17,
   18,    0,    0,    0,   10,    0,    0,    0,    7,   41,
   42,   43,   44,   45,   48,   49,    0,   47,   46,    0,
   20,   19,   21,    0,    0,   25,    0,    0,   28,   29,
   30,   31,    1,    3,    4,    5,    0,    9,    0,    8,
   38,    0,    0,    0,    0,    0,    0,    0,   40,   34,
   32,   33,   35,   26,   27,   23,   24,   13,   11,
};
static const short yydgoto[] = {                          7,
    8,    9,   10,   11,   31,   32,   33,   66,   50,   48,
   34,   35,   12,   13,   14,   19,
};
static const short yysindex[] = {                      -250,
 -253,  -89,  -77,  -77, -251,    0,    0,    0,    0,    0,
    0, -250, -259, -257,    0, -243, -248, -238,    0,    0,
    0,    0,    0,    0,    0,    0, -244,    0,    0, -244,
    0,    0,    0,  -13,  -12,    0,  -11,  -10,    0,    0,
    0,    0,    0,    0,    0,    0,   -9,    0,   -8,    0,
    0,  -56,  -77,  -77,  -48,  -48, -248, -238,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yyrindex[] = {                        38,
    0, -233,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   38,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -44,    0,    0,    0,
    0,    0,    0, -232, -231,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -230,    0, -228,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                        33,
    0,    0,    0,    0,   -2,   23,   42,   -7,   -6,   -4,
    1,    5,    0,    0,    0,    0,
};
#define YYTABLESIZE 228
static const short yytable[] = {                         39,
   65,   30,   42,   37,   15,   41,    1,   38,    2,    3,
    4,    5,   44,   30,   45,   28,   29,   16,   47,   17,
   18,    6,   28,   29,   51,   36,   39,   52,   46,   49,
   53,   54,   55,   56,   57,   58,   59,    2,   22,   36,
   37,   14,   30,   12,   43,   40,    0,    0,   67,    0,
    0,   69,   68,   60,   62,   60,   62,   61,   63,   61,
   63,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   20,    0,   21,
   22,   23,   24,    0,   25,   26,   27,   28,   29,   20,
    0,   21,   22,   23,   24,    0,   25,   26,   27,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   20,    0,
   21,   22,   23,   24,    0,   25,   26,   27,    0,    0,
   64,    0,    0,    0,    0,    0,    0,   39,
};
static const short yycheck[] = {                         44,
   49,   91,    5,    3,  258,  257,  257,    3,  259,  260,
  261,  262,  272,   91,  272,  267,  268,  271,  267,  273,
  274,  272,  267,  268,   27,    3,    4,   30,  272,  268,
   44,   44,   44,   44,   44,   44,   93,    0,  272,  272,
  272,  272,   91,  272,   12,    4,   -1,   -1,   56,   -1,
   -1,   58,   57,   53,   54,   55,   56,   53,   54,   55,
   56,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,  259,
  260,  261,  262,   -1,  264,  265,  266,  267,  268,  257,
   -1,  259,  260,  261,  262,   -1,  264,  265,  266,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,
  259,  260,  261,  262,   -1,  264,  265,  266,   -1,   -1,
  269,   -1,   -1,   -1,   -1,   -1,   -1,  272,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 274
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"','",0,0,0,0,"'1'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"LABEL","STR",
"ARITH","LOG","DTTF","CTTF","IO","REG8","REG16","MEM","IBYTE","IWORD","CL",
"CON","COLON","E","DB","DW","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : S",
"S : N S",
"S :",
"N : VAR E",
"N : INSTR E",
"N : LABEL COLON E",
"N : E",
"VAR : LABEL VAL",
"VAL : DW NWORDS",
"VAL : DB NBYTES",
"VAL : STR",
"NWORDS : IWORD ',' NWORDS",
"NWORDS : IWORD",
"NBYTES : IBYTE ',' NBYTES",
"NBYTES : IBYTE",
"INSTR : ARITHMETIC",
"INSTR : LOGICAL",
"INSTR : DATATRANS",
"INSTR : CTRLTRANS",
"ARITHMETIC : ARITH REGMEM",
"ARITHMETIC : ARITH CONST",
"ARITHMETIC : ARITH RM",
"ARITHMETIC : ARITH",
"LOGICAL : LOG REG ',' STEP",
"LOGICAL : LOG MEMORY ',' STEP",
"LOGICAL : LOG REGMEM",
"STEP : CL",
"STEP : '1'",
"DATATRANS : DTTF REGMEM",
"DATATRANS : DTTF RM",
"CTRLTRANS : CTTF LABEL",
"CTRLTRANS : CTTF CONST",
"REGMEM : REG ',' MEMORY",
"REGMEM : MEMORY ',' REG",
"REGMEM : REG ',' REG",
"REGMEM : MEMORY ',' MEMORY",
"RM : REG",
"RM : MEMORY",
"MEMORY : MEM CONST",
"MEMORY : MEM",
"MEMORY : '[' CONST ']'",
"MEMORY : LABEL",
"MEMORY : ARITH",
"MEMORY : LOG",
"MEMORY : DTTF",
"MEMORY : CTTF",
"CONST : IWORD",
"CONST : IBYTE",
"REG : REG8",
"REG : REG16",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 179 "pass2.y"

int yyerror(int errcode)
{
  if(!errf)
   err[front++]=errcode+(lineno<<3);
  errf=1;
  return 0;
}

void disperr()
{
  int i=0;
  if(front) printf("\n\n%d errors found!!",front);
  for(;i<front;i++)
   switch(err[i]%8)
   {
     case 0:printf("\nError %d:Invalid operand",err[i]/8);break;
     case 1:printf("\nError %d:Missmatch in size of operands",err[i]/8);break;
     case 2:printf("\nError %d:Label not defined",err[i]/8);break;
     case 3:printf("\nError %d:Atleast 1 operand must be a register",err[i]/8);break;
     default:printf("\nFatal Error %d:Unable to parse",err[i]/8);break;
   }
}

int main()
{
  read_symtab();
  print_symtab();
  printf("\n\nLineNum LOCCTR  INSTRUCTION      OPCODE\n\n");
  initopcodes();
  intr=fopen("inter.txt","r");
  fscanf(intr," %s ",h);
  locctr=toint(h,4);
  printf("%4d\t0000\t",lineno);
  op=fopen("opcode.obj","w");
  //yyin=fopen("prog.aaa","r");
  yyparse();
  disperr();
  printf("\n\n");
}
#line 340 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 53 "pass2.y"
	{printf("\n PASS 2 complete.....");}
break;
case 3:
#line 56 "pass2.y"
	{tohex(locctr,h,4);printf("%4d\t%s\t",++lineno,h);fscanf(intr," %s ",h);locctr=toint(h,4);}
break;
case 4:
#line 57 "pass2.y"
	{tohex(locctr,h,4);printf("%4d\t%s\t",++lineno,h);fscanf(intr," %s ",h);locctr=toint(h,4);}
break;
case 5:
#line 58 "pass2.y"
	{ if((temp =search_symbol(yystack.l_mark[-2].str))!=NULL&& temp->flag!=0)
					printf("\t Symbol declared/repeated error\n");
					
					tohex(locctr,h,4);
					printf("%4d\t%s\t",++lineno,h);
					fscanf(intr," %s ",h);
					locctr=toint(h,4);
			    }
break;
case 6:
#line 66 "pass2.y"
	{printf("%4d\t",++lineno);}
break;
case 7:
#line 68 "pass2.y"
	{if((temp =search_symbol(yystack.l_mark[-1].str))!=NULL&& temp->flag!=0)
                    printf("\n Symbol repeated here error\n");
			   }
break;
case 8:
#line 72 "pass2.y"
	{convert(yystack.l_mark[0].str,h);printf("\t%s\n",h);fprintf(op,"%s\n",h);}
break;
case 9:
#line 73 "pass2.y"
	{convert(yystack.l_mark[0].str,h);printf("\t%s\n",h);fprintf(op,"%s\n",h);}
break;
case 10:
#line 74 "pass2.y"
	{convert(yystack.l_mark[0].str,h);printf("\t%s\n",h);fprintf(op,"%s\n",h);}
break;
case 11:
#line 76 "pass2.y"
	{yystack.l_mark[-2].str[4]='\0';strcat(yystack.l_mark[-2].str,yystack.l_mark[0].str);strcpy(yyval.str,yystack.l_mark[-2].str);}
break;
case 12:
#line 77 "pass2.y"
	{yystack.l_mark[0].str[4]='\0'; strcpy(yyval.str,yystack.l_mark[0].str);}
break;
case 13:
#line 79 "pass2.y"
	{yystack.l_mark[-2].str[2]='\0';strcat(yystack.l_mark[-2].str,yystack.l_mark[0].str);strcpy(yyval.str,yystack.l_mark[-2].str);}
break;
case 14:
#line 80 "pass2.y"
	{yystack.l_mark[0].str[2]='\0';strcpy(yyval.str,yystack.l_mark[0].str);}
break;
case 15:
#line 82 "pass2.y"
	{if(!errf) printf("\t%s\n",yystack.l_mark[0].str);
					   else printf("\tERROR\n");
		 			 fprintf(op,"%s\n",yystack.l_mark[0].str);mod=f=s=errf=0; }
break;
case 16:
#line 85 "pass2.y"
	{if(!errf) printf("\t%s\n",yystack.l_mark[0].str);
				 else printf("\tERROR\n");
		 		 fprintf(op,"%s\n",yystack.l_mark[0].str);mod=f=s=errf=0;}
break;
case 17:
#line 88 "pass2.y"
	{if(!errf) printf("\t%s\n",yystack.l_mark[0].str);
			 else printf("\tERROR\n");
		 	 fprintf(op,"%s\n",yystack.l_mark[0].str);mod=f=s=errf=0;}
break;
case 18:
#line 91 "pass2.y"
	{if(!errf) printf("\t%s\n",yystack.l_mark[0].str);
			 else printf("\tERROR\n");
		 	 fprintf(op,"%s\n",yystack.l_mark[0].str);mod=f=s=errf=0;}
break;
case 19:
#line 95 "pass2.y"
	{get_code(yystack.l_mark[-1].str,h,0+(f==2));addhex(h,yystack.l_mark[0].str,yyval.str);}
break;
case 20:
#line 96 "pass2.y"
	{get_code(yystack.l_mark[-1].str,h,2);addhex(h,yystack.l_mark[0].str,yyval.str);}
break;
case 21:
#line 97 "pass2.y"
	{get_code(yystack.l_mark[-1].str,h,0);addhex(h,yystack.l_mark[0].str,yyval.str);}
break;
case 22:
#line 98 "pass2.y"
	{get_code(yystack.l_mark[0].str,h,0);strcpy(yyval.str,h);printf("\t");}
break;
case 23:
#line 100 "pass2.y"
	{getrm(yystack.l_mark[-2].num,0,3,h);addhex(h,yystack.l_mark[0].str,h);get_code(yystack.l_mark[-3].str,h1,0);addhex(h,h1,yyval.str);}
break;
case 24:
#line 101 "pass2.y"
	{getrm(yystack.l_mark[-2].num,0,mod,h);addhex(h,yystack.l_mark[0].str,h);get_code(yystack.l_mark[-3].str,h1,0);addhex(h,h1,yyval.str);}
break;
case 25:
#line 102 "pass2.y"
	{get_code(yystack.l_mark[-1].str,h,0+(f==2));addhex(h,yystack.l_mark[0].str,yyval.str);}
break;
case 26:
#line 105 "pass2.y"
	{strcpy(yyval.str,"02");}
break;
case 27:
#line 106 "pass2.y"
	{strcpy(yyval.str,"00");}
break;
case 28:
#line 108 "pass2.y"
	{get_code(yystack.l_mark[-1].str,h,0+(f==2));addhex(h,yystack.l_mark[0].str,yyval.str);}
break;
case 29:
#line 109 "pass2.y"
	{get_code(yystack.l_mark[-1].str,h,2);addhex(h,yystack.l_mark[0].str,yyval.str);}
break;
case 30:
#line 112 "pass2.y"
	{get_code(yystack.l_mark[-1].str,h,0);
			 Symbol *temp=search_symbol(yystack.l_mark[0].str);
			 if(temp==NULL)
		  	  {strcpy(h1,"");yyerror(2);}
			 else
			  { tohex(locctr-temp->addrs,h1,4); /*find out the difference*/
			    if(h1[0] =='F' && h1[1]=='F')  /*in case of forward jump, addrs= FFF... so the first 2F get added with opcode ***/
			   	{ h1[0]='0'; h1[1]='0'; }   /*so make them 00 so that 0+*=**/
			   }
			   addhex(h,h1,yyval.str);  /*concatenating the hex values here */
			  }
break;
case 31:
#line 123 "pass2.y"
	{get_code(yystack.l_mark[-1].str,h,0);addhex(h,yystack.l_mark[0].str,yyval.str);}
break;
case 32:
#line 125 "pass2.y"
	{if(f%10==2)
			 {getrm(yystack.l_mark[-2].num,0,3,yyval.str);
			  tohex(yystack.l_mark[0].num,h,4-f/5-s);
			  strcat(yyval.str,h);
			  if((f/5==0)&&((yystack.l_mark[-2].num<8&&s==0)||(yystack.l_mark[-2].num>=8&&s==2))) yyerror(2);}
			 else
			  {getrm(((f%10==1)? 6:yystack.l_mark[0].num%8),yystack.l_mark[-2].num,mod,yyval.str);
			   if(f/10==1) 
			    {tohex(yystack.l_mark[0].num/8,h,4-s);strcat(yyval.str,h);}
			   }
			 mod=0;
 			}
break;
case 33:
#line 137 "pass2.y"
	{getrm(((f%10==1)? yystack.l_mark[-2].num%8:6),yystack.l_mark[0].num,mod,h);addhex(h,"02",yyval.str); 
			 if(f/10==1) 
			  {tohex(yystack.l_mark[-2].num/8,h,4-s);strcat(yyval.str,h);}
			 mod=0;f=0;
			 }
break;
case 34:
#line 142 "pass2.y"
	{getrm(yystack.l_mark[0].num,yystack.l_mark[-2].num,3,h);strcpy(yyval.str,h);
			   if(f<=1&&((yystack.l_mark[-2].num<8&&yystack.l_mark[0].num>=8)||(yystack.l_mark[0].num<8&&yystack.l_mark[-2].num>=8))) 
			   		yyerror(1);
			  }
break;
case 35:
#line 146 "pass2.y"
	{if(f!=2) yyerror(3);}
break;
case 36:
#line 148 "pass2.y"
	{getrm(yystack.l_mark[0].num,0,3,h);strcpy(yyval.str,h);}
break;
case 37:
#line 149 "pass2.y"
	{getrm(yystack.l_mark[0].num,0,mod,h);
						 strcpy(yyval.str,h);
						 mod=0;}
break;
case 38:
#line 153 "pass2.y"
	{yyval.num=yystack.l_mark[-1].num+(toint(yystack.l_mark[0].str,strlen(yystack.l_mark[0].str)-1)<<3);
						mod=(strlen(yystack.l_mark[0].str)-1)/2;
						f=10;}
break;
case 39:
#line 156 "pass2.y"
	{yyval.num=yystack.l_mark[0].num;}
break;
case 40:
#line 157 "pass2.y"
	{yyval.num=toint(yystack.l_mark[-1].str,strlen(yystack.l_mark[-1].str)-1)<<3;
						  f=11;}
break;
case 41:
#line 159 "pass2.y"
	{Symbol *temp=search_symbol(yystack.l_mark[0].str);
			 if(temp==NULL)
		  	  {yyval.num=0;yyerror(2);}
			else
			  yyval.num=locctr-temp->addrs;
			 f=12;
			}
break;
case 42:
#line 166 "pass2.y"
	{yyerror(0);}
break;
case 43:
#line 167 "pass2.y"
	{yyerror(0);}
break;
case 44:
#line 168 "pass2.y"
	{yyerror(0);}
break;
case 45:
#line 169 "pass2.y"
	{yyerror(0);}
break;
case 46:
#line 172 "pass2.y"
	{strcpy(yyval.str,yystack.l_mark[0].str);s=0;}
break;
case 47:
#line 173 "pass2.y"
	{strcpy(yyval.str,yystack.l_mark[0].str);s=2;}
break;
case 48:
#line 175 "pass2.y"
	{yyval.num=yystack.l_mark[0].num;}
break;
case 49:
#line 176 "pass2.y"
	{yyval.num=yystack.l_mark[0].num;}
break;
#line 790 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
