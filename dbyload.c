/*----------------------------------------------------------------------------
	Program : dbyload.c
	Author  : Silver Hammer Software LLC
	Author  : Tom Stevelt
	Date    : Apr 2023
	Synopsis: Insert or Update mysql table from delimited file.
			  Modeled after Unify DBLOAD program:
			  usage: DBLOAD [ -n | -u ] [ -l ] [ -s<separator> ] [ -b ]
				  <database> <table> <file> <specfile> [ <comment> ]
	Return  : 0

	Copyright © 2023 Tom Stevelt and Silver Hammer Software LLC
	Tom Stevelt <tstevelt@silverhammersoftware.com>

	This software is free software; you can redistribute it and/or modify
	it under the terms of the MIT license. See LICENSE for details.

	Who		Date		Modification
	---------------------------------------------------------------------

----------------------------------------------------------------------------*/

#define		MAIN
#include	"dbyload.h"

int main ( int argc, char *argv[] )
{
	getargs ( argc, argv );

	getspec ();

	switch ( RunMode )
	{
		case MODE_INSERT:
			insert ();
			break;

		case MODE_UPDATE:
			update ();
			break;
	}

	return ( 0 );
}
