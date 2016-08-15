#include "FileWorker.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int c_fileExists(const char *path)
{
    if (access(path, 0) != -1) {
        return 1;
    } else {
        return 0;
    }
}

int c_fileCopy(const char *src, const char *des)
{
    FILE * fSrc = fopen(src, "rb");
    if(!fSrc) {
        printf("Open file `%s` failed", src);
        return 0;
    }
    FILE * fDes = fopen(des, "wb");
    if(!fDes) {
        printf("Create file `%s` failed", des);
        return 0;
    }
    
    fseek(fSrc, 0, SEEK_END);
    long length = ftell(fSrc);
    unsigned char *buf = malloc(length + 1);
    
    memset(buf, 0, length + 1);
    fseek(fSrc, 0, SEEK_SET);
    
    fread(buf, length, 1, fSrc);
    fwrite(buf, length, 1, fDes);
    
    fclose(fSrc);
    fclose(fDes);
    free(buf);
    return 1;
}


int c_copyFile(const char *src, const char *des)
{
    FILE *fpSrc, *fpDest;
    fpSrc = fopen(src, "rb");
    if(fpSrc == NULL) {
        printf( "Source file `%s` open failure.", src);
        return 0;
    }
    fpDest = fopen(des, "wb");
    if(fpDest == NULL) {
        printf("Destination file `%s` open failure.", des);
        return 0;
    }
    int c;
    while((c = fgetc(fpSrc)) != EOF) {
        fputc(c, fpDest);
    }
    fclose(fpSrc);
    fclose(fpDest);
    return 1;
}