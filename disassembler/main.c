#include <elf.h>
#include <stdio.h>
#include <string.h>

#define MAGIC_BYTE_COUNT 4
const char* ELF_MAGIC = "\x7f""ELF";

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");

    if (file == NULL)
    {
        printf("Unable to access file\n");
        return 1;
    }

    fseek(file, 0, SEEK_SET);

    char magic_bytes[MAGIC_BYTE_COUNT];

    fread(magic_bytes, sizeof(char), MAGIC_BYTE_COUNT, file);

    if (!memcmp(magic_bytes, ELF_MAGIC, MAGIC_BYTE_COUNT) == 0)
    {
        printf("Not a valid elf file\n");
        fclose(file);
    }
}