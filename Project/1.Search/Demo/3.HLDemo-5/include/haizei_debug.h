/*************************************************************************
	> File Name: haizei_debug.h
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三 12/ 6 20:20:26 2017
 ************************************************************************/

#ifndef _HAIZEI_DEBUG_H
#define _HAIZEI_DEBUG_H

#ifdef DEBUG
#define P(frm, arg...) { \
    printf("[%s(%s:%d)] ", __FILE__, __func__, __LINE__); \
    printf(frm, ##arg); \
    printf("\n"); \
    fflush(stdout); \
}
#else
#define P(frm, arg...) {}
#endif
#endif
