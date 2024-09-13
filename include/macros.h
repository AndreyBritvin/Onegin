#ifndef MY_MACROS_H_
#define MY_MACROS_H_

#ifdef DEBUG_MODE
#define DEBUG_ON(...) __VA_ARGS__
#else
#define DEBUG_ON(...)
#endif

#endif //  MY_MACROS_H_
