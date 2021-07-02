#include "init.h"

Widget        areaWidget, nameAreaWidget, buttonWidget[6];
//9 pixels to record
int        lifeGame[winWidth * 2 / sqarePixel + 6][winHeight / sqarePixel + 2];
int        dayAndNight[winWidth * 2 / sqarePixel + 6][winHeight / sqarePixel + 2];
int        ifStop = 0;
char nowString[105] = "";

/*
 Function: Calculate the digital of array(char).
 */
int myAtoi( const char s[], int num[] )
{
    int ntot = 0, i = 0; int len = strlen( s );
    while ( i < len )
    {
        num[ntot++] = atoi( s + i );
        while ( !isspace( s[i] ) )
            i++;
        while ( isspace( s[i] ) )
            i++;
    }
    return(ntot);
}

/*
 Function: Initial NameLabelStructure and Map.
 */
void initData( Widget w, void *data )
{
    
    FILE    * file;
    int    n;
    /* Read in StructureFiles */
    const char    *Name        = (const char *) data;
    char        tempString[105] = "Now display is ";
    strcat( tempString, Name );
    strcpy( nowStructure, tempString );
    
    /* Change the label to what is displaying now. */
    SetLabel( nameAreaWidget, nowStructure );

    if ( (file = fopen( Name, "r" ) ) == NULL )
    {
        perror( "error in open file" );
        exit( EXIT_FAILURE );
    }
    /* Show the Map corresponding */
    char    numX[305], numY[305];
    int    X[105], Y[105];
    
    if ( fgets( numX, sizeof(numX), file ) == NULL )
    {
        perror( "error in fgets the file\n" );
        exit(EXIT_FAILURE);
    }
    
    n = myAtoi( numX, X );
    
    if ( fgets( numY, sizeof(numX), file ) == NULL )
    {
        perror( "error in fgets the file\n" );
        exit(EXIT_FAILURE);
    }
    
    myAtoi( numY, Y );
    
    memset( lifeGame, 0, sizeof(lifeGame) );
    memset( dayAndNight, 0, sizeof(dayAndNight) );
    
    for ( int i = 0; i < n; i++ )
    {
        lifeGame[X[i]][Y[i]] = 1;
        dayAndNight[X[i]][Y[i]] = 1;
    }
    if ( fclose( file ) != 0 )
       { perror( "error in close file" );
           exit(EXIT_FAILURE);
       }
    return;
}
