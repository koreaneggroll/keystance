#ifndef KEYSTANCER_H
#define KEYSTANCER_H


#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE



#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>


#include "../analyzer/include/analyzer.h"


//DEFINES
#define CTRL_KEY(k) ((k) & 0x1f)

#define FIND 'f'
#define SAVE 's'
#define QUIT 'q'
#define HELP 'h'
#define DEL_LINE_L 'd'
#define DEL_LINE_R 'e'
#define RUN_CMD 'r'
#define INSERT_END 'a'

#define KEYSTANCE_VERSION "0.0.1"
#define KEYSTANCE_TAB_STOP 8
#define KEYSTANCE_QUIT_TIMES 3
#define HL_HIGHLIGHT_NUMBERS (1<<0)
#define HLDB_ENTRIES (sizeof(HLDB) / sizeof(HLDB[0]))
#define HL_HIGHLIGHT_STRINGS (1<<1)


//COLORS
#define ML_COMMENT_COLOR 37
#define KEYWORD1_COLOR 33
#define KEYWORD2_COLOR 32
#define STRING_COLOR 34
#define NUMBER_COLOR 31
#define MATCH_COLOR 34
#define DEFAULT_COLOR 37

//true and false
#define true 1
#define false 0


enum editorKey {
  BACKSPACE = 127,
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN,
  DEL_KEY,
  HOME_KEY,
  END_KEY,
  PAGE_UP,
  PAGE_DOWN
};

enum editorHighlight {
    HL_NORMAL = 0,
    HL_COMMENT,
    HL_MLCOMMENT,
    HL_KEYWORD1,
    HL_KEYWORD2,
    HL_STRING,
    HL_NUMBER,
    HL_MATCH
};


//DATA





struct editorSyntax {
  char *filetype;
  char **filematch;
  char **keywords;
  char *singleline_comment_start;
  char *multiline_comment_start;
  char *multiline_comment_end;
  int flags;
};


typedef struct erow {
  int idx;
  int size;
  int rsize;
  char *chars;
  char *render;
  unsigned char *hl;
  int hl_open_comment;
} erow;


struct editorConfig {
    int cx, cy;
    int rx;
    int rowoff;
    int coloff;
    int screenrows;
    int screencols;
    int numrows;
    erow *row;
    int dirty;
    char *filename;
    char statusmsg[80];
    time_t statusmsg_time;
    struct editorSyntax *syntax;
    struct termios orig_termios;
};






//PROTOTYPES


void editorSetStatusMessage(const char *fmt, ...);
void editorRefreshScreen();
char *editorPrompt(char *prompt, void (*callback)(char *, int));







#endif
