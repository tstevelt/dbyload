
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"shslib.h"

#ifdef MAIN
#define		TYPE	/* */
#else
#define		TYPE	extern
#endif

#define		MAXBUFF		1024
#define		MAXFIELDS	24
#define		MODE_INSERT		1
#define		MODE_UPDATE		2

TYPE	int		RunMode;
TYPE	char	*Filename;
TYPE	char	Separator;
TYPE	char	*Database;
TYPE	char	*Table;
TYPE	char	*Specfile;
TYPE	char	Buffer[MAXBUFF];
TYPE	char	*FieldArray[MAXFIELDS];
TYPE	int		FieldCount;

/*----------------------------
:.,$d
:r ! mkproto -p *.c
----------------------------*/

/* dbyload.c */
int main ( int argc , char *argv []);

/* getargs.c */
void getargs ( int argc , char *argv []);

/* getspec.c */
void getspec ( void );

/* insert.c */
void insert ( void );

/* update.c */
void update ( void );
