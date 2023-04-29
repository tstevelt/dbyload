
#include	"dbyload.h"

/*---------------------------------------------------------------------------

load data local infile 'Arbys_Selected.csv'
 into table `food` 
 fields terminated by ','
 lines terminated by '\n'
 ignore 1 rows
 (`Fname`, `Fcalorie`, `Ffat`, `Fsodium`, `Fcarb`, `Ffiber`, `Fprotein`)
;

---------------------------------------------------------------------------*/
void insert ()
{
	printf ( "USE %s;\n\n", Database );

	printf ( "LOAD DATA LOCAL INFILE '%s'\n", Filename );

	printf ( " INTO TABLE `%s`\n", Table );

	printf ( " FIELDS TERMINATED BY '%c'\n", Separator );

	printf ( " LINES TERMINATED BY '\\n'\n" );

	for ( int xf = 0; xf < FieldCount; xf++ )
	{
		if ( xf == 0 )
		{
			printf ( " (" );
		}
		else
		{
			printf ( " ," );
		}

		printf ( "`%s`", FieldArray[xf] );
	}
	printf ( ");\n\n" );

	printf ( "SELECT 'Inserted', ROW_COUNT();\n\n" );
}
