#pragma once

#define APP_NAME "Yoda"
#define APP_NAME_LC "yoda"
#define APP_NAME_UC "YODA"

#define APP_VERSION "0.1"

// TODO check if they are all working
#define RESET   "\033[0m"
#define BLACK   "\033[30m"             /* Black */
#define RED     "\033[31m"             /* Red */
#define GREEN   "\033[32m"             /* Green */
#define YELLOW  "\033[33m"             /* Yellow */
#define BLUE    "\033[34m"             /* Blue */
#define MAGENTA "\033[35m"             /* Magenta */
#define CYAN    "\033[36m"             /* Cyan */
#define WHITE   "\033[37m"             /* White */
#define BOLDBLACK   "\033[1m\033[30m"  /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"  /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"  /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"  /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"  /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"  /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"  /* Bold White */


#define MES_COMMAND_NOT_FOUND_1 "No command '"
#define MES_COMMAND_NOT_FOUND_2 "' found!"

#define MES_TEST_TRUE GREEN "Test passed" RESET
#define MES_TEST_SEMI YELLOW "Test failed (optional)" RESET
#define MES_TEST_FALSE RED "Test failed" RESET

#define PROMPT ">"