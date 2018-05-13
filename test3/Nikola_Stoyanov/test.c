#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

int done = 0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

enum {
	N = 10240,
	WORKERS = 10
};

typedef struct stack
{
	int data;
	struct stack *next;
} stack;

char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}

void push( stack **head, int value )
{
	stack* node = malloc( sizeof(stack) );

	if( node == NULL ) {
		fputs( "Error: Out of memory\n", stderr );
		exit( 1 );
	} else {
		node->data = value;
		node->next = *head;
		*head = node;
	}
}

int pop( stack **head )
{
	if( *head == NULL ) {
		fputs( "Error: bottom of stack!\n", stderr );
		exit( 1 );
	} else {
		stack* top = *head;
		int value = top->data;
		*head = top->next;
		free( top );
		return value;
	}
}

int eval( char op, stack** head )
{
	int temp;
	switch( op ) {
		case '+': return pop(head) + pop(head);
		case '*': return pop(head) * pop(head);
		case '-': temp = pop(head); return pop(head) - temp;
		case '/': temp = pop(head); return pop(head) / temp;
		case '^': return pop(head) ^ pop(head);
		case '|': return pop(head) | pop(head);
		case '&': return pop(head) & pop(head);
		case '~': return  ~ pop(head);
		case 'p': return pop(head);
	}
}

int need( char op )
{
	switch( op ) {
		case '+':
		case '*':
		case '-':
		case '/':
		case '|':
		case '&': 
		case '~':
		case 'p':
		case '^':
			return 2;
		default:
			fputs( "Invalid operand!", stderr );
			exit( 1 );
	}
}

int checknr( char* number )
{
	for( ; *number; number++ )
		if( *number < '0' || *number > '9' )
			return 0;

	return 1;
}

void *worker(void *_filename) {

	pthread_mutex_lock(&mtx);
	char *filename = (char*)_filename;
	stack *head = NULL;
	int i = 0;
	int j = 0;
	int stacksize = 0;
	char line[128];
	char filestring[2000];
	filestring[0] = '\0';
	char *fn = trimwhitespace(filename);
	int temp;
	FILE *file = fopen(fn, "r");
	while ( fgets ( line, 128, file) != NULL ) 
		strcat(filestring, line);
		
	char *tokenized[1000];

	tokenized[j] = strtok(filestring," \n");

	while(tokenized[j]!=NULL) {
 		tokenized[++j] = strtok(NULL," \n");
	}
	
	for( i = 0; i < j - 1; i++ ) {
		char* token = tokenized[i];
		char* endptr;
		char op;

		if( checknr( token ) ) {
			temp = atoi( token );
			push( &head, temp );
			++stacksize;
		} else {
			if( strlen( token ) != 1 ) {
				fprintf( stderr, "Error: Token '%s' too large.\n", token );
				exit( 1 );
			}

			op = token[0];
			
			push( &head, eval( op, &head ) );
			stacksize --;
		}
	}
	
	printf( "Result: %i\n", head->data );
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mtx);
	filestring[0] = '\0';
}


int main( int argc, char** argv )
{
	unsigned int len = 0;
	ssize_t read;
	char line [ 128 ]; /* or other suitable maximum line size */
	int i = 0, temp, stacksize = 0;
	stack *head[WORKERS];
	pthread_attr_t ta;
	pthread_t thr[WORKERS];
	
	
	if( argc == 1 )
	{
		printf("Not enought arguments \n");
		exit(1);
	}
	
	pthread_attr_init(&ta);
	
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
        	exit(EXIT_FAILURE);
	     
      	while ( fgets ( line, sizeof line, fp ) != NULL ) {
      		//printf("%s\n", line);
      		//worker(line);
      		pthread_create(&thr[i], &ta, &worker, line);
      		pthread_cond_wait(&cond, &mtx);
      		i++;
      	
      	}
      	fclose ( fp );
	
	for (; i > 0; i--) 
		pthread_join(thr[i], NULL);

	return 0;
}
