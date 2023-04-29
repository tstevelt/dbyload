
#include    "dbyload.h"

void getspec ()
{
	FILE	*fp;
	char	Delimeters[4];

	if (( fp = fopen ( Specfile, "r" )) == NULL )
	{
		printf ( "Cannot open specfile for reading\n" );
		exit ( 1 );
	}

	fgets ( Buffer, sizeof(Buffer), fp );

	nsFclose ( fp );

	sprintf ( Delimeters, "%c\n\r", Separator );

	FieldCount = GetTokensD ( Buffer, Delimeters, FieldArray, MAXFIELDS );

	if ( FieldCount <= 1 )
	{
		printf ( "Field count is %d\n", FieldCount );
		printf ( "Are your data and spec files '%c' delimited?\n", Separator );
		exit ( 1 );
	}
}
