/*
    Counterslib is a library of PMCGPU (Parallel simulators for Membrane 
                                        Computing on the GPU)   
 
    Copyright (c) 2012 Miguel Á. Martínez-del-Amor (RGNC, University of Seville)
    
    This file is part of counterslib.
  
    counterslib is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    counterslib is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with counterslib.  If not, see <http://www.gnu.org/licenses/>. */


#ifndef __TIME_STAT__
#define __TIME_STAT__
#include <sys/time.h>
#include <stdio.h>

/* Initializates the relative values for next print_time */
/* The call to this function is mandatory before the first PRINT_TIME */
void init_time();

/* Prints the time since last call to PRINT_TIME or INIT_TIME */
void print_time(FILE* file_out);

/* Returns the amount of seconds since the last call to init_time() */
time_t get_seconds();

/* Returns the amount of useconds since the last call to init_time() */
suseconds_t get_useconds();

/* Initializates the timer */
void start_timer();

/* Get the number of miliseconds since the last call to start_timer or init_time */
double end_timer();

#endif

/*$Id: timestat.h 2008-06-07 11:12:44 mangel.martinez $
 *$Last update: 2009-03-17 mdelamor $*/
