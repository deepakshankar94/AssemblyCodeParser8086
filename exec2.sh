#!/bin/bash
clear
cc functions.h
yacc -d pass2.y
lex assemble.l
cc lex.yy.c y.tab.c -ll -o PASS2
clear
