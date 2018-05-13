int getline(char *s, int lim) {
    char *p, c;

    p = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';

    return s - p;
}

void reverse(char *s) {
    char c, *p;

    p = s + strlen(s) - 1;

    while (p > s) {
        c = *s;
        *s++ = *p;
        *p-- = c;

    }
    return;
}

int atoi(char *s) {
    int n, sign;
    while (isspace(*s))
        *s++;
    sign = (*s == '-') ? -1 : 1;
        if (*s == '+' || *s == '-') /* skip sign */
        *s++;
    for (n = 0; isdigit(*s); *s++)
        n = 10 * n + (*s - '0');

    return sign * n;
}

int getop(char *s) {
    char c;

    while ((*s = c = getch()) == ' ' || c == '\t');
    *++s = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    *--s;
    if (isdigit(c))
        while (isdigit(*++s = c = getch()));
    if (c == '.')
        while (isdigit(*++s = c = getch()));
    *s = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

int strindex(char *s, char *t) {
    int slen = strlen(s);
    int tlen = strlen(t);
    int i, j, k;

    for (i = slen - tlen; *(s + i) != '\0'; i--) {
        for (j = i, k = 0; *(t + k) != '\0' && *(s + j) == *(t + k); j++, k++)
            ;
        if (*(t + k) == '\0')
            return i;
    }
    return -1;
}
