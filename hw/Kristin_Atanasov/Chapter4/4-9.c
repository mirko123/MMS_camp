#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define VAR 26
#define SIN '1'
#define COS '2'
#define EXP '3'
#define POW '4'
#define VSET '5'
#define VGET '6'
#define EMPTY -2
int getop(char []);
void push(double);
double pop(void);
double top(void);
void swap(void);
void duplicate(void);
void clear(void);
double var[VAR];
/* reverse Polish calculator */
int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                push ((int) pop() % (int) op2);
                break;
            case '\n':
                printf("\t%.8g\n", op2 = pop());
                var['R' - 'A'] = op2;
                break;
            case '?':
                top();
                break;
            case '#':
                swap();
                break;
            case '$':
                duplicate();
                break;
            case '^':
                clear();
                break;
            case SIN:
                push(sin(pop()));
                break;
            case COS:
                push(cos(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case VSET:
                var[s[0] - 'A'] = top();
                break;
            case VGET:
                push(var[s[0] - 'a']);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
    return;
}
/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
#include <ctype.h>

int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[]){
    int c, next, i;

    while ((s[0] = c = getch()) == ' ' || c == '\t') ;
    if (c == '\n' || c == EOF)
        return c;
    next = getch();
    ungetch(next);
    if (isdigit(c) || (( c == '+' || c == '-') && isdigit(next))){
        s[i = 0] = c;
        while (isdigit(s[++i] = c = getch())) ;
        if (c == '.'){
            while (isdigit(s[++i] = c = getch())) ;
        } else {
            ungetch(c);
        }
        s[i] = '\0';
        c = NUMBER;
    } else if (isalpha(c)){
        i = 0;
        while (isalpha(s[++i] = c = getch()))
            ;
        ungetch(c);
        s[i] = '\0';
        if (i > 1){
            if (!strcmp(s, "SIN")){
                return SIN;
            } else if (!strcmp(s, "COS")){
                return COS;
            } else if (!strcmp(s, "EXP")){
                return EXP;
            } else if (!strcmp(s, "POW")){
                return POW;
            } /* else {
                printf("error: unknown functions %s\n", s);
            } */
        } else {
            if  (islower(s[0]))
                return VGET;
            else
                return VSET;
            }
        } else {
            s[0] = c;
            s[1] = '\0';
    }
    return c;
}
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */

int bufp = 0; /* next free position in buf */
int bufi[BUFSIZE];
int getch(void) { /* get a (possibly pushed-back) character */
    return (bufi > 0) ? bufi[--bufp] : getchar();
}
void ungetch(int c) {  /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        bufi[bufp++] = c;
}
double top(void){
    if (sp > 0)
        return val[sp - 1];
    else
        printf("error: stack empty\n");
}

void duplicate(void){
    int i;
    i = sp - 1;
    val[sp++] = val[i];

    return;
}

void swap(void){
    int aux = val[sp - 2];
    val[sp - 2] = val[sp - 1];
    val[sp - 1] = aux;

    return;
}

void clear(void){
    sp = 0;

    return;
}
