//
// Created by thejano on 05.06.19.
//

#include <stdio.h>

#define LENGTH 64

int main(int argc, const char *argv[]) {
    char first_name[LENGTH];
    char last_name[LENGTH];
    int age;

    printf("First Name: ");
    scanf("%s", first_name);

    printf("Last Name: ");
    scanf("%s", last_name);

    printf("Age: ");
    scanf("%d", &age);

    FILE* fd = fopen("student.dat", "r+");
    int id;
    fseek(fd, 0, SEEK_SET);
    fread(&id, sizeof(id), 1, fd);

    fseek(fd, 0, SEEK_END);
    fwrite(&id, sizeof(id), 1, fd);
    fwrite(first_name, sizeof(first_name), 1, fd);
    fwrite(last_name, sizeof(last_name), 1, fd);
    fwrite(&age, sizeof(age), 1, fd);

    fseek(fd, 0, SEEK_SET);
    id++;
    fwrite(&id, sizeof(id), 1, fd);

    printf("Stored succesfully\n");

    fclose(fd);
    return 0;
}