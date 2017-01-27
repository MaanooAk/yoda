#pragma once

#define APP_NAME "Yoda"
#define APP_NAME_LC "yoda"
#define APP_NAME_UC "YODA"

#define APP_VERSION "0.2"


// File paths
#define PATH_PREFERENCES "./prefs.ini"


// Max values
#define LINE_SIZE 4096
#define ARGS_SIZE 4096


// Formating special characters
#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"


// Messages
#define MES_COMMAND_NOT_FOUND_1 "No command '"
#define MES_COMMAND_NOT_FOUND_2 "' found!"
#define MES_TEST_TRUE GREEN "Test passed" RESET
#define MES_TEST_SEMI YELLOW "Test failed (optional)" RESET
#define MES_TEST_FALSE RED "Test failed" RESET


// TODO move to preferences
#define PROMPT1 BOLDBLUE
#define PROMPT2 RESET "> "

