/*
 * SCCSID=unix.c 3/15/83
 */

/*
 * loc_ - return the address of arg
 */
int
loc_( arg )
	int *arg;
{
	return( (int) arg );
}



/*
 * times_ - c routine to call library routine times
 */
times_( iarg )
	int *iarg ;
{
	times( iarg );
}


#include <time.h>

/*
 * xtime_ - fortran routine for character time
 */
xtime_( chr )
	char *chr;
{
	struct tm	*localtime();
	char		*asctime(),	*character;
	long		time();
	long		tloc,	scum;
	int		i;

        tloc = time( & scum );
        character = asctime( localtime(& tloc) );
        for( i = 11; i < 19; i++ )
                *chr++ = *( character + i );
}

/*
 * xdate_ - fortran routine for character date
 */
xdate_( chr )
	char	*chr;
{
	struct	tm	*localtime(),	*buffer;
	char		*asctime(),	*month,	*day,	*year,	*itoc();
	long		time();
	long		tloc,	scum;

        tloc = time( & scum );
        buffer = localtime( & tloc);
        month = itoc( buffer->tm_mon + 1 );   /* month is zero based */
        while( *month )
                *chr++ = *month++;
        *chr++ = '/';
        day = itoc( buffer->tm_mday );
        while( *day )
                *chr++ = *day++;
        *chr++ = '/';
        year = itoc( buffer->tm_year );
        while( *year )
                *chr++ = *year++;
}
/*
 * itoc
 */
char  *
itoc( number )
	int	number;
{
	char string[3];

	/*
	 * make a two digit string from the least significant digits of number
	 */
        string[2] = '\0';
        string[1] = number%10 + '0';
        number /= 10;
        string[0] = number%10 + '0';
        return( string );
}


/*
 * dblsgl - convert a complex double precision array into
 *  a single precision complex array.
 */
dblsgl_( cstar16, numwds )
	double	*cstar16;
	int	*numwds;
{
	float	*cstar8;
	int	i;

	return( 0 );
	cstar8 = (float *) cstar16;
	for ( i = 0; i < (*numwds)/4; i++ ) {
		cstar8[ i ] = cstar16[ 2*i ];
	}
}


#include <stdio.h>
static	FILE	*rawfile;	/* pointer to raw file  */
static	int	xargc;		/* number of arguments in UNIX command */
static	char	**xargv;	/* pointer to an array of pointers to
				arguments in UNIX command line  */
/*
 * Open raw data file.  Return 1 if file is opened,
 *  return 0 if file is not opened
 */
iopraw_()
{
	int	i;
	char	*filename = NULL;/* name of raw file */

	for ( i=1; i < xargc; i++ ) {
		if ( *xargv[i] == '-' )
			switch ( xargv[i][1] )  {
			case 'r':
				if ( ++i < xargc )
					filename = xargv[i];
				else
					filename = "rawspice";
				break;
			default:
				fprintf( stderr, "SPICE: illegal option -%c - ignored\n",
						xargv[i][1] );
				break;
			}
	}
	if ( filename == NULL )
		return( 0 );
	if  ( (rawfile=fopen( filename, "w" )) == NULL ) {
		fprintf( stderr, "SPICE: unable to open file %s\n", filename );
		fprintf( stderr, "SPICE:  *** program terminated ***\n" );
		exit( 1 );  /* terminate program */
	}
	return( 1 );  /* normal termination */
}
/*
 * Close raw file.
 */
clsraw_()
{
	fclose( rawfile );
}
/*
 * Write into raw file numwds 16 bit words starting
 *  at location data
 */
fwrite_( data, numwds )
	char	*data;
	int	*numwds;
{
	fflush( stderr );
	fwrite( data, 2, *numwds, rawfile );
	fflush( rawfile );
}

/*
 * Zero, copy and move for vax unix.
 */
move_( array1, index1, array2, index2, length )
	register char	*array1, *array2;
	register int	*length;
	int		*index1, *index2;
{
	array1 += *index1 - 1;
	array2 += *index2 - 1;
	mcopy( array2, array1, *length );
}


zero4_( array, length )
	char		*array;
	unsigned	*length;
{
	mclear( array, *length * 4 );
}


zero8_( array, length )
	char		*array;
	unsigned	*length;
{
	mclear( array, *length * 8 );
}


zero16_( array, length )
	char		*array;
	unsigned	*length;
{
	mclear( array, *length * 8 );
}


copy4_( from, to, length )
	char		*from, *to;
	int		*length;
{
	mcopy( from, to, *length * 4 );
}


copy8_( from, to, length )
	char		*from, *to;
	int		*length;
{
	mcopy( from, to, *length * 8 );
}


copy16_( from, to, length )
	char		*from, *to;
	int		*length;
{
	mcopy( from, to, *length * 8 );
}

/*
 * misc.c - miscellaneous utility routines.
 * sccsid @(#)unix.c	6.1	(Splice2/Berkeley) 3/15/83
 */

/*
 * mclear - clear memory.
 */
mclear( data, size )
	char		*data;
	int		size;
{
	for ( ; size > 0; size--, data++ ) {
		*data = '\0';
	}
}




/*
 * mcopy - copy memory.
 */
mcopy( from, to, size )
	char		*from,	*to;
	int		size;
{
	if ( from >= to ) {
		for ( ; size > 0; size-- ) {
			*to++ = *from++;
		}
	}
	else {
		to   += size;
		from += size;
		for ( ; size > 0; size-- ) {
			*--to = *--from;
		}
	}
}



/*
 * mcmp - compare memory.
 */
int
mcmp( from, to, size )
	char		*from,	*to;
	int		size;
{
	for ( ; size > 0; size-- ) {
		if ( *to++ != *from++ ) {
			return( 1 );
		}
	}
	return( 0 );
}
