#pragma once
#ifndef _TESTS_READER_H_
#define _TESTS_READER_H_


int readFile(const char * name, char** buffer){
    std::ifstream file(name);

    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    char * buf = (char*)malloc(size + 1);

    file.seekg(0);
    file.read(buf, size);

    file.close();

    *buffer = buf;
    return size;
}


#endif
