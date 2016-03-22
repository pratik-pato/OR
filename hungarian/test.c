/*
 *  C Implementation of Kuhn's Hungarian Method
 *  Copyright (C) 2003  Brian Gerkey <gerkey@robotics.usc.edu>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/*
 * a test/example program for the C implementation of the Hungarian method
 */

#define USAGE "Usage: ./test [-m <m>] [-n <n>]"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#include "hungarian.h"

#define MAXUTIL 1000

#ifndef max
  #define max(a, b) ((a) > (b) ? (a) : (b))
#endif

// problem dimensions
int m,n;

void parse_args(int argc, char** argv);
int* make_random_r(size_t m, size_t n);

int
main(int argc, char** argv)
{
  hungarian_t prob;

  /*
  int r[4][4] =  {{  363, 626, 376,  46  },
                  {  802, 993, 784, 953  },
                  {  673,  23, 823, 207  },
                  {  380, 451, 520, 646  }};
                  */
  int* r;
  
  m = n = 4;

  parse_args(argc,argv);

  r = make_random_r(m,n);

  hungarian_init(&prob,(int*)r,m,n);
  hungarian_print_rating(&prob);
  hungarian_solve(&prob);
  hungarian_print_assignment(&prob);

  printf("\nfeasible? %s\n", 
         (hungarian_check_feasibility(&prob)) ? "yes" : "no");
  printf("benefit: %d\n\n", hungarian_benefit(&prob));

  hungarian_fini(&prob);
  free(r);
  return(0);
}

/*
 * makes and returns a pointer to an mXn rating matrix with values uniformly 
 * distributed between 1 and MAXUTIL
 *
 * allocates storage, which the caller should free().
 */
int*
make_random_r(size_t m, size_t n)
{
  int i,j;
  int* r;
  time_t curr;
  assert(r = malloc(sizeof(int)*m*n));
  curr = time(NULL);
  srand(curr);
  //puts("\nINPUT: ");
  for(i=0;i<m;i++)
  {
    //printf("  [ ");
    for(j=0;j<n;j++)
    {
      r[i*n+j] = 1+(rand() % MAXUTIL);
      //printf("%4d ", r[i*n+j]);
    }
    //puts(" ]");
  }
  return(r);
}

void
parse_args(int argc, char** argv)
{
  int i;
  // parse command-line args
  for(i=1; i<argc; i++)
  {
    if(!strcmp(argv[i],"-m"))
    {
      if(++i < argc)
      {
        m = atoi(argv[i]);
      }
      else
      {
        puts(USAGE);
        exit(-1);
      }
    }
    else if(!strcmp(argv[i],"-n"))
    {
      if(++i < argc)
      {
        n = atoi(argv[i]);
      }
      else
      {
        puts(USAGE);
        exit(-1);
      }
    }
    else
    {
      puts(USAGE);
      exit(-1);
    }
  }
}

