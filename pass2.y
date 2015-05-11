%{
#include "functions.h"
FILE *op,*intr;
extern FILE *yyin;
char *c,h[14],h1[14];
int f=0,locctr=0,mod=0,lineno=1,s=0;
int err[20],front=0;
extern struct instrn t;
int yyerrstatus,errf=0;
SYMBOL *temp;
%}

%union {
  int num;
  char str[30];
}

%token LABEL STR ARITH LOG DTTF CTTF IO REG8 REG16 MEM IBYTE IWORD CL
%start S
%nonassoc CON
%nonassoc ','
%type <str>LABEL
%type <str>STR
%type <str>ARITH
%type <str>LOG
%type <str>DTTF
%type <str>CTTF
%type <str>IO
%type <num> REG8
%type <num>REG16
%type <num> MEM
%type <str>IBYTE
%type <str>IWORD
%type <num>CL
%token COLON E DB DW


%type <str> ARITHMETIC
%type <str> LOGICAL
%type <str>DATATRANS
%type <str> CTRLTRANS
%type <str> CONST
%type <str> REGMEM
%type <str> RM
%type <str> STEP
%type <str> NWORDS
%type <str> NBYTES
%type <num>REG
%type <num>MEMORY

%%
S: N S 
|  {printf("\n PASS 2 complete.....");}
;

N: VAR E	{tohex(locctr,h,4);printf("%4d\t%s\t",++lineno,h);fscanf(intr," %s ",h);locctr=toint(h,4);}
| INSTR E	{tohex(locctr,h,4);printf("%4d\t%s\t",++lineno,h);fscanf(intr," %s ",h);locctr=toint(h,4);}
| LABEL COLON E	{ if((temp =search_symbol($1))!=NULL&& temp->flag!=0)
					printf("\t Symbol declared/repeated error\n");
					
					tohex(locctr,h,4);
					printf("%4d\t%s\t",++lineno,h);
					fscanf(intr," %s ",h);
					locctr=toint(h,4);
			    }
| E		{printf("%4d\t",++lineno);}

VAR: LABEL VAL {if((temp =search_symbol($1))!=NULL&& temp->flag!=0)
                    printf("\n Symbol repeated here error\n");
			   }

VAL: DW NWORDS   {convert($2,h);printf("\t%s\n",h);fprintf(op,"%s\n",h);}
| DB NBYTES      {convert($2,h);printf("\t%s\n",h);fprintf(op,"%s\n",h);}
| STR        	{convert($1,h);printf("\t%s\n",h);fprintf(op,"%s\n",h);}

NWORDS: IWORD',' NWORDS {$1[4]='\0';strcat($1,$3);strcpy($$,$1);}
| IWORD 		{$1[4]='\0'; strcpy($$,$1);}

NBYTES: IBYTE ',' NBYTES {$1[2]='\0';strcat($1,$3);strcpy($$,$1);}
| IBYTE 		{$1[2]='\0';strcpy($$,$1);}

INSTR: ARITHMETIC	{if(!errf) printf("\t%s\n",$1);
					   else printf("\tERROR\n");
		 			 fprintf(op,"%s\n",$1);mod=f=s=errf=0; }
| LOGICAL		{if(!errf) printf("\t%s\n",$1);
				 else printf("\tERROR\n");
		 		 fprintf(op,"%s\n",$1);mod=f=s=errf=0;}
| DATATRANS	{if(!errf) printf("\t%s\n",$1);
			 else printf("\tERROR\n");
		 	 fprintf(op,"%s\n",$1);mod=f=s=errf=0;}
| CTRLTRANS	{if(!errf) printf("\t%s\n",$1);
			 else printf("\tERROR\n");
		 	 fprintf(op,"%s\n",$1);mod=f=s=errf=0;}
;
ARITHMETIC: ARITH REGMEM	{get_code($1,h,0+(f==2));addhex(h,$2,$$);}
| ARITH CONST		{get_code($1,h,2);addhex(h,$2,$$);}
| ARITH RM		{get_code($1,h,0);addhex(h,$2,$$);}
| ARITH			{get_code($1,h,0);strcpy($$,h);printf("\t");}
;
LOGICAL: LOG REG ',' STEP	{getrm($2,0,3,h);addhex(h,$4,h);get_code($1,h1,0);addhex(h,h1,$$);}
| LOG MEMORY ',' STEP	{getrm($2,0,mod,h);addhex(h,$4,h);get_code($1,h1,0);addhex(h,h1,$$);}
| LOG REGMEM 		{get_code($1,h,0+(f==2));addhex(h,$2,$$);}

;
STEP: CL	{strcpy($$,"02");}
| '1'		{strcpy($$,"00");}
;
DATATRANS: DTTF REGMEM	{get_code($1,h,0+(f==2));addhex(h,$2,$$);}
| DTTF RM		{get_code($1,h,2);addhex(h,$2,$$);}
;

CTRLTRANS: CTTF LABEL	{get_code($1,h,0);
			 Symbol *temp=search_symbol($2);
			 if(temp==NULL)
		  	  {strcpy(h1,"");yyerror(2);}
			 else
			  { tohex(locctr-temp->addrs,h1,4); //find out the difference
			    if(h1[0] =='F' && h1[1]=='F')  //in case of forward jump, addrs= FFF... so the first 2F get added with opcode **
			   	{ h1[0]='0'; h1[1]='0'; }   //so make them 00 so that 0+*=*
			   }
			   addhex(h,h1,$$);  //concatenating the hex values here 
			  }
| CTTF CONST		{get_code($1,h,0);addhex(h,$2,$$);}
;
REGMEM: REG ',' MEMORY  	{if(f%10==2)
			 {getrm($1,0,3,$$);
			  tohex($3,h,4-f/5-s);
			  strcat($$,h);
			  if((f/5==0)&&(($1<8&&s==0)||($1>=8&&s==2))) yyerror(2);}
			 else
			  {getrm(((f%10==1)? 6:$3%8),$1,mod,$$);
			   if(f/10==1) 
			    {tohex($3/8,h,4-s);strcat($$,h);}
			   }
			 mod=0;
 			}
| MEMORY ',' REG   {getrm(((f%10==1)? $1%8:6),$3,mod,h);addhex(h,"02",$$); 
			 if(f/10==1) 
			  {tohex($1/8,h,4-s);strcat($$,h);}
			 mod=0;f=0;
			 }
| REG ',' REG {getrm($3,$1,3,h);strcpy($$,h);
			   if(f<=1&&(($1<8&&$3>=8)||($3<8&&$1>=8))) 
			   		yyerror(1);
			  }
| MEMORY ',' MEMORY {if(f!=2) yyerror(3);}
;
RM: REG	 %prec CON	{getrm($1,0,3,h);strcpy($$,h);}
| MEMORY	 %prec CON	{getrm($1,0,mod,h);
						 strcpy($$,h);
						 mod=0;}

MEMORY: MEM CONST	{$$=$1+(toint($2,strlen($2)-1)<<3);
						mod=(strlen($2)-1)/2;
						f=10;}
| MEM		{$$=$1;}
| '[' CONST ']'		{$$=toint($2,strlen($2)-1)<<3;
						  f=11;}
| LABEL			{Symbol *temp=search_symbol($1);
			 if(temp==NULL)
		  	  {$$=0;yyerror(2);}
			else
			  $$=locctr-temp->addrs;
			 f=12;
			}
| ARITH	{yyerror(0);}
| LOG	{yyerror(0);}
| DTTF	{yyerror(0);}
| CTTF	{yyerror(0);}
;

CONST: IWORD %prec CON	{strcpy($$,$1);s=0;}
| IBYTE     %prec CON {strcpy($$,$1);s=2;}
;
REG: REG8	{$$=$1;}
| REG16 	{$$=$1;}
;
%%

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
