#ifndef _TEST_H_
#define _TEST_H_
enum {
	BUFSIZE = 128
};

char *getstr(FILE *f, const char *delimiters) {
	char *buf, *t;
	int N, p;
	int c;
	
	N = BUFSIZE;
	p = 0;
	
	buf = (char *)malloc(N * sizeof (*buf));
	if (!buf) goto out;
	//|| strchr(delimiters, c)
	while (1) {
		c = fgetc(f);
		if ((c == EOF) || strchr(delimiters, c)) {
			buf[p] = '\0';
			goto out;
		} else {
			buf[p++] = (char)(c & 0xff);
			if (p == N) {
				N += BUFSIZE;
				t = (char *)realloc(buf, N);
				if (!t) {
					buf[p - 1] = '\0';
					goto out;
				} else buf = t;
			}
		}
	}
out:
	return buf;
}

void calc(FILE *in, FILE *out, queue_object *q)
{
	int i,j,k;
	void **obj;
	char *s,*cont,*comp;
	datum d;
	j = 0;
	k = 0;
	cont=strdup(" ");
	comp=strdup(" ");
	s = getstr(in, ".:;-!?()[]\n\t");
	for(i = 0;i < strlen(s); i++)
	{
		if(s[i] != ' ')
		{
			cont[j] = s[i];
			j++;
		}
		
	}
	printf("%s %s\n",s ,cont);
	if (cont[0] == '#')
	{
		for(i = 2;i < j; i++)
		{
			comp[k] = cont[i];
			k++;
		}
	}
			d.type = CHAR;
			d.data.i = cont[0];
			d.on_delete = NULL;
	q->addE(q, cont[1] , d);
	
	printf("%s %s\n",cont ,comp);
	obj=malloc(strlen(comp));
	if (cont[0] == '$')
	{
		for(i = 0;i < strlen(comp); i++)
		{	
			obj[i] = q->search(q, (int)comp[i], &d);
		}
		
		for(i = 0;i < strlen(comp); i++)
		{
			(*((int*)obj[i]))((int)cont[3]);
		}
	}
	return;	
}

#endif
