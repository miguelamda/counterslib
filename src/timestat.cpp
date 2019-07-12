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


#include "timestat.h"

/* For print_time */
struct timeval __tv__;
suseconds_t __usec__;
time_t __sec__;

/* For get_seconds */
time_t __total_sec__;
suseconds_t __total_usec__;

/* For timer */
struct timeval __timer__;

/* Initializates the relative values for next print_time */
/* The call to this function is mandatory before the first PRINT_TIME */
void init_time() {
        if (gettimeofday(&__tv__,NULL)==-1) {
                perror("Cannot use time stat");
        }
        else {
                __usec__=__tv__.tv_usec;
                __sec__=__tv__.tv_sec;
                __total_sec__=__sec__;
                __total_usec__=__usec__;
                __timer__.tv_usec=__tv__.tv_usec;
                __timer__.tv_sec=__tv__.tv_sec;
        }
}

/* Prints the time since last call to PRINT_TIME or INIT_TIME */
void print_time(FILE* file_out) {
        time_t sec=0;
        suseconds_t usec=0;
        double time_ms=0.0,time_s;

	if (gettimeofday(&__tv__,NULL)==-1) {
		perror("Cannot use time stat");
        }
        else {
                sec=__tv__.tv_sec - __sec__;
                usec=__tv__.tv_usec - __usec__;
                time_ms = sec*1000 + usec/1000.0;
                time_s = sec + usec/1000000.0;
                if (sec==0) {
	                fprintf(file_out,"TIME: %f s (%f milliseconds)\n",time_s,time_ms);
                }
                else if (sec >= 60) {
	                fprintf(file_out,"TIME: %f s (%d minutes)\n",time_s,(int)sec/60);
	        }
	        else if (sec >= 60*60) {
		        fprintf(file_out,"TIME: %f s (%d hours, %d minutes)\n",time_s,(int)sec/(60*60),(int)((sec%(60*60)/60)));
		}
                else {
	                fprintf(file_out,"TIME: %f s\n",time_s);
	        }
	        fflush(stdout);
                __usec__=__tv__.tv_usec;
                __sec__=__tv__.tv_sec;
	}
}

/* Returns the amount of seconds since the last call to init_time() */
time_t get_seconds() {
	if (gettimeofday(&__tv__,NULL)==-1) {
		return 0;
	}
	else {
	        return __tv__.tv_sec - __total_sec__;
	}
}

/* Returns the amount of useconds since the last call to init_time() */
suseconds_t get_useconds() {
	if (gettimeofday(&__tv__,NULL)==-1) {
		return 0;
	}
	else {
		return __tv__.tv_usec - __total_usec__;
	}
}

/* Initializates the timer */
void start_timer() {
        if (gettimeofday(&__tv__,NULL)==-1) {
                return;
        }
        else {
                __timer__.tv_usec=__tv__.tv_usec;
                __timer__.tv_sec=__tv__.tv_sec;
        }
}

/* Get the number of miliseconds since the last call to start_timer or init_time */
double end_timer() {
        if (gettimeofday(&__tv__,NULL)==-1) {
                return -1;
        }
        else {
                return (__tv__.tv_sec - __timer__.tv_sec)*1000 + (__tv__.tv_usec - __timer__.tv_usec)/1000.0;
        }
}

/*$Id: timestat.cpp 2009-03-17 10:57:44 mdelamor $*/

