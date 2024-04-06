/*--------------------------------------------------------------------*/
/* "Hello World" PPE Program                                          */
/*--------------------------------------------------------------------*/
/*                                                                    */
/*                                                                    */
/* Source from "Cell Programming Primer: Basics of SPE Programming"   */
/* found at http://www.kernel.org/pub/linux/kernel/people/geoff/cell/ */
/* ps3-linux-docs/ps3-linux-docs-08.06.09/CellProgrammingPrimer.html  */
/*--------------------------------------------------------------------*/
/*                                      Brandon Essler - 30 June 2010 */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <libspe2.h> /* Required for controlling the SPE. */
#include "/home/bessler/csci4440/misc/types.h"

int main ( s32 argc, s32 **argv )
{
    s32 ret; /* Return value used in error-checking. */

    spe_context_ptr_t spe;      /* SPE context pointer. */
    spe_program_handle_t *prog; /* SPE program pointer. */
    u32 entry;                  /* Where SPE prog. begins execution. */
    spe_stop_info_t stop_info;  /* SPE program interruption info. */

    /* Open the SPE program image stored in the ELF executable file. */
    prog = spe_image_open( "hello_spe.elf" );
    if ( !prog )
    {
        perror( "spe_image_open" );
        exit(1);
    }

    /* Create a new SPE context. */
    spe = spe_context_create( 0, NULL );
    if ( !spe )
    {
        perror( "spe_context_create" );
        exit(1);
    }
    
    /* Load SPE program into the LS prior to running the SPE context. */
    ret = spe_program_load( spe, prog );
    if ( ret )
    {
        perror( "spe_program_load" );
        exit(1);
    }

    entry = SPE_DEFAULT_ENTRY;
    /* Execute the loaded SPE program. */
    ret = spe_context_run( spe, &entry, 0, NULL, NULL, &stop_info );
    if ( ret < 0 )
    {
        perror( "spe_context_run" );
        exit(1);
    }

    /*------------------------------------------------------------------
       At this point, control is passed to the SPE program. Control will
       return to the PPE program when the SPE program is terminated.
     -----------------------------------------------------------------*/

    /* Destroy the SPE context as it is no longer needed. */
    ret = spe_context_destroy( spe );
    if ( ret )
    {
        perror( "spe_context_destroy" );
        exit(1);
    }
    
    /* Close SPE program image. */
    ret = spe_image_close( prog );
    if ( ret )
    {
        perror( "spe_image_close" );
        exit(1);
    }

    return 0;
}
