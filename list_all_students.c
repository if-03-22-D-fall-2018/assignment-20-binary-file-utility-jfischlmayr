//
// Created by thejano on 05.06.19.
//

#include <stdio.h>

#define LENGTH 64

int main(int argc, const char *argv[]) {
    char first_name[LENGTH];
    char last_name[LENGTH];
    int age;

    FILE* fd = fopen("student.dat", "r");
    int id;

    fseek(fd, 0, SEEK_SET);
    fseek(fd, sizeof(int), SEEK_SET);
    int count = fread(&id, sizeof(int), 1, fd);

    while(count > 0) {
        fread(first_name, sizeof(first_name), 1, fd);
        fread(last_name, sizeof(last_name), 1, fd);
        fread(&age, sizeof(age), 1, fd);
        printf("%d %s %s %d\n", id, first_name, last_name, age);
        count = fread(&id, sizeof(int), 1, fd);
    }

    fclose(fd);
    return 0;
}