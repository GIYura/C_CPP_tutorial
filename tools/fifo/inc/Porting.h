#ifndef __PORT_H
#define __PORT_H

#ifdef __cplusplus
extern "C" {
#endif

// ANSI escape codes. May be used to make the console output more illustrative.
#define TEXT_DEFAULT            "\033[0m"
#define TEXT_BLACK              "\033[0;30m"
#define TEXT_BLACK_BOLD         "\033[1;30m"
#define TEXT_RED                "\033[0;31m"
#define TEXT_RED_BOLD           "\033[1;31m"
#define TEXT_GREEN              "\033[0;32m"
#define TEXT_GREEN_BOLD         "\033[1;32m"
#define TEXT_YELLOW             "\033[0;33m"
#define TEXT_YELLOW_BOLD        "\033[1;33m"
#define TEXT_BLUE               "\033[0;34m"
#define TEXT_BLUE_BOLD          "\033[1;34m"
#define TEXT_MAGENTA            "\033[0;35m"
#define TEXT_MAGENTA_BOLD       "\033[1;35m"
#define TEXT_CYAN               "\033[0;36m"
#define TEXT_CYAN_BOLD          "\033[1;36m"
#define TEXT_GREY               "\033[0;37m"
#define TEXT_GREY_BOLD          "\033[1;37m"
#define CURSOR_UP               "\033[1A" /* \e[#A Move cursor up on # rows */
#define CURSOR_DOWN             "\033[1B" /* \e[#A Move cursor down on # rows */
#define CURSOR_RIGHT            "\033[1C" /* \e[#A Move cursor right on # columns */
#define CURSOR_LEFT             "\033[1D" /* \e[#A Move cursor left on # columns */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
    
#define PRINTF(...)            printf(__VA_ARGS__)

#define ERROR_HANDLER()                                             \
		do{                                                         \
			PRINTF("ERROR in %s line %d!\r\n", __FILE__, __LINE__); \
			while(1){}                                              \
		} while(0)

#ifdef __cplusplus
}
#endif

#endif // __PORT_H
