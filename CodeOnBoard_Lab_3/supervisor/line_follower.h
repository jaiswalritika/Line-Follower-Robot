/* --- Generated the 20/3/2025 at 1:17 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 10 16:17:35 CET 2025) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
typedef struct Line_follower__findpid_mem {
  long v_3;
  long v_1;
  long v;
  long error_1;
} Line_follower__findpid_mem;

typedef struct Line_follower__findpid_out {
  long pid;
} Line_follower__findpid_out;

void Line_follower__findpid_reset(Line_follower__findpid_mem* self);

void Line_follower__findpid_step(long sen3, long sen1,
                                 Line_follower__findpid_out* _out,
                                 Line_follower__findpid_mem* self);

typedef struct Line_follower__main_mem {
  Line_follower__st ck;
  long pnr;
  Line_follower__findpid_mem findpid;
} Line_follower__main_mem;

typedef struct Line_follower__main_out {
  long v_l;
  long v_r;
  long dir;
} Line_follower__main_out;

void Line_follower__main_reset(Line_follower__main_mem* self);

void Line_follower__main_step(long sen0, long sen1, long sen2, long sen3,
                              long sen4, Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
