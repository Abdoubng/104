
#ifndef iec60870_shared_EXPORT_H
#define iec60870_shared_EXPORT_H

#ifdef iec60870_shared_BUILT_AS_STATIC
#  define iec60870_shared_EXPORT
#  define IEC60870_SHARED_NO_EXPORT
#else
#  ifndef iec60870_shared_EXPORT
#    ifdef iec60870_shared_EXPORTS
        /* We are building this library */
#      define iec60870_shared_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define iec60870_shared_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef IEC60870_SHARED_NO_EXPORT
#    define IEC60870_SHARED_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef IEC60870_SHARED_DEPRECATED
#  define IEC60870_SHARED_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef IEC60870_SHARED_DEPRECATED_EXPORT
#  define IEC60870_SHARED_DEPRECATED_EXPORT iec60870_shared_EXPORT IEC60870_SHARED_DEPRECATED
#endif

#ifndef IEC60870_SHARED_DEPRECATED_NO_EXPORT
#  define IEC60870_SHARED_DEPRECATED_NO_EXPORT IEC60870_SHARED_NO_EXPORT IEC60870_SHARED_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define IEC60870_SHARED_NO_DEPRECATED
#endif

#endif
