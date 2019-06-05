//
// Created by thejano on 03.06.19.
//
#include<stdio.h>

int main(int argc, const char* argv[]) {

    FILE* fd = fopen("student.dat", "w");
    int id = 1;
    fwrite(&id, sizeof(id), 1, fd);
    fclose(fd);
    return 0;
}
