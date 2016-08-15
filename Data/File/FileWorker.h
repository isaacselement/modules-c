#ifndef FileWorker_h
#define FileWorker_h

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    int c_fileExists(const char *path);
    
    int c_fileCopy(const char *src, const char *des);
    
    int c_copyFile(const char *src, const char *des);

#ifdef __cplusplus
}
#endif

#endif /* FileWorker_h */
