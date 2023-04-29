
#include	"dbyload.h"

static void Usage ()
{
	printf ( "USAGE: dbyload {-n|-u} database table file specfile [options]\n" );
	printf ( "options:\n" );
	printf ( "  -s separator\n" );
	printf ( "  -l nolog (not used)\n" );
	printf ( "  -b binary (not used)\n" );
	exit ( 1 );
}

void getargs ( int argc, char *argv[] )
{
	int		xa;

	RunMode = 0;
	Separator = ',';

	if ( nsStrcmp ( argv[1], "-n" ) == 0 )
	{
		RunMode = MODE_INSERT;
	}
	else if ( nsStrcmp ( argv[1], "-u" ) == 0 )
	{
		RunMode = MODE_UPDATE;
	}
	else
	{
		Usage ();
	}

	if ( argc < 5 )
	{
		Usage ();
	}

	Database = argv[2];
	Table    = argv[3];
	Filename = argv[4];
	Specfile = argv[5];

	for ( xa = 6; xa < argc; xa++ )
	{
		if ( xa + 1 < argc && nsStrcmp ( argv[xa], "-s" ) == 0 )
		{
			xa++;
			Separator = argv[xa][0];
		}
		else
		{
			Usage ();
		}
	}

	if ( RunMode == 0 )
	{
		Usage ();
	}

	if ( access ( Filename, R_OK ) != 0 )
	{
		printf ( "FILENAME %s NOT FOUND\n", Filename );
		Usage ();
	}

	if ( access ( Specfile, R_OK ) != 0 )
	{
		printf ( "SPECFILE %s NOT FOUND\n", Specfile );
		Usage ();
	}
}
