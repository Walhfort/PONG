#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#include "grille.h"
#include "routine.h"

#define VERSION "0.1.0"

typedef enum {VOID, BORDER, BALL, PADDLE} construct;

//Size
#define LENGHT_PADDLE 5

//System Color
#define color(param) printf("\033[%sm",param)
#define reset "0"
#define black "30"
#define red "31"
#define green "32"
#define yellow "33"
#define blue "34"
#define magenta "35"
#define white "37"
#define invert "7"
#define back_red "41"
#define back_green "42"




