
#include	"dbyload.h"

void update ()
{
	int		xf;

	/*----------------------------------------------------------
		set database
	----------------------------------------------------------*/
	printf ( "USE %s;\n\n", Database );

	/*----------------------------------------------------------
		drop temp table
	----------------------------------------------------------*/
	printf ( "DROP TABLE IF EXISTS temp_%s;\n\n", Table );

	/*----------------------------------------------------------
		create temp table
	----------------------------------------------------------*/
	printf ( "CREATE TEMPORARY TABLE temp_%s SELECT ", Table );
	for ( xf = 0; xf < FieldCount; xf++ )
	{
		if ( xf > 0 )
		{
			printf ( ", " );
		}
		printf ( "`%s`", FieldArray[xf] );
	}
	printf ( " FROM %s LIMIT 0;\n\n", Table );

	/*----------------------------------------------------------
		load temp table
	----------------------------------------------------------*/
	printf ( "LOAD DATA LOCAL INFILE '%s'\n", Filename );
	printf ( " INTO TABLE temp_%s FIELDS TERMINATED BY '%c' (", Table, Separator );
	for ( xf = 0; xf < FieldCount; xf++ )
	{
		if ( xf > 0 )
		{
			printf ( ", " );
		}
		printf ( "`%s`", FieldArray[xf] );
	}
	printf ( ");\n\n" );

	/*----------------------------------------------------------
		update target table from temp table
	----------------------------------------------------------*/
	printf ( "UPDATE %s\n", Table );

	printf ( " INNER JOIN temp_%s on temp_%s.%s = %s.%s\n", 
		Table, Table, FieldArray[0], Table, FieldArray[0] );

	for ( xf = 1; xf < FieldCount; xf++ )
	{
		if ( xf == 1 )
		{
			printf ( " SET" );
		}
		else
		{
			printf ( ",\n" );
		}
		printf ( " %s.%s = temp_%s.%s",
			Table, FieldArray[xf], Table, FieldArray[xf] );
		
	}
	printf ( ";\n\n" );

	printf ( "SELECT 'Updated', ROW_COUNT();\n\n" );

	/*----------------------------------------------------------
		drop temp table
	----------------------------------------------------------*/
	printf ( "DROP TEMPORARY TABLE temp_%s;\n\n", Table );
}
