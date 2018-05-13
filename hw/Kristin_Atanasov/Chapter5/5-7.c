int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(lineptr[nlines++], line);
    }
    return nlines;
}
