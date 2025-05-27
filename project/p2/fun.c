#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/asm.h"

int SP_offset = 0;

void soures(char *word, char *out) {
    printf("\n%s", word);
    FILE *file = fopen("lavel2.txt", "a");
    if (!file) {
        perror("fopen");
        return;
    }

    char word_copy[256];
    strncpy(word_copy, word, sizeof(word_copy) - 1);
    word_copy[sizeof(word_copy) - 1] = '\0';
    char temp[32];
    char *sou = strtok(word_copy, ",");
    char *dis = strtok(NULL, ",");

    int immidiate;
    int iflag = 0;
    //	strcat(out, " ");
    strcat(out, " ");

    if (sou[0] == '#') {
        strcat(out, "00011");
        immidiate = atoi(sou + 1);
        iflag = 1;
    } else if (sou[1] == 'd' && isdigit(sou[2])) {
        int reg = sou[2] - 0;
        strcat(out, " 1");
        for (int i = 3; i >= 0; i--) {
            sprintf(temp, "%d", (reg >> i) & 1);
            strcat(out, temp);
        }
    } else if (sou[1] == 's') {
        int address = SP + SP_offset;
        if (sou[3] = '@') {
            strcat(out, "00011");
            immidiate = address;
            iflag = 1;
        } else if (isdigit(sou[5])) {  //%sp@(n)
            int reg = pare(sou);
            address += reg;
            strcat(out, "00011");
            immidiate = address;
            iflag = 1;
        }
    } else if (sou[1] == 'a') {
        strcat(out, "01111");
        // case %a@(n)
        // add #n,%a@
        if (isdigit(sou[4])) {
            printf("\n%c", sou[4]);
            char buff[1024] = "";
            char buff2[1024] = "";
            int reg = pare(sou);
            strcat(buff, "\t001000 00011 01111\n\t");
            for (int i = 15; i >= 0; i--) {
                char bit = ((reg >> i) & 1) + '0';
                strncat(buff, &bit, 1);
            }
            strcat(buff2, buff);
            strcat(buff2, "\n");
            strcat(buff2, out);
            strcpy(out, buff2);
        } else if (sou[4] == '+') {
            char buff[1024] = "";
            char buff2[1024] = "";
            strcat(buff, "\t001000 00011 01111\n\t");
            int reg = 1;
            for (int i = 15; i >= 0; i--) {
                char bit = ((reg >> i) & 1) + '0';
                strncat(buff, &bit, 1);
            }
            strcat(buff2, buff);
            strcat(buff2, "\n");
            strcat(buff2, out);
            strcpy(out, buff2);
        }
    }

    strcpy(temp, "");
    strcat(out, " ");

    if (dis[0] == '#') {
        int num = atoi(dis + 1);
        strcat(out, " ");
        for (int i = 4; i >= 0; i--) {
            sprintf(temp, "%d", (num >> i) & 1);
            strcat(out, temp);
        }
    } else if (dis[1] == 'd' && isdigit(dis[2])) {
        int reg = dis[2] - 0;
        strcat(out, "1");
        for (int i = 3; i >= 0; i--) {
            sprintf(temp, "%d", (reg >> i) & 1);
            strcat(out, temp);
        }
    } else if (dis[1] == 's') {
        int address = SP + SP_offset;
        if (dis[3] == '@') {
            if (isdigit(dis[5])) {
                int reg = pare(dis);
                address += reg;
            }
            if (iflag != 0) {  // #
                char buff[1024] = "";
                strcat(buff, "\t000000 00011 10011\n\t");  // mov x %d3
                for (int i = 15; i >= 0; i--) {
                    sprintf(temp, "%d", (immidiate >> i) & 1);
                    strcat(buff, temp);
                }
                strcat(buff, "\n");
                fprintf(file, buff);
                char part1[16], part2[16];
                char result[64];
                sscanf(out, "\t%s %s", part1, part2);
                strcpy(part2, "10011");
                sprintf(result, "\t%s %s", part1, part2);
                strcat(result, " 00011");
                memset(out, 0, sizeof(out));
                strcpy(out, result);
                immidiate = address;
            } else {
                strcat(out, "00011");
                immidiate = address;
                iflag = 1;
            }
        } else {
            char part1[16], part2[16];
            sscanf(out, "\t%s %s", part1, part2);
            if (strcmp(part1, "001000") == 0) {
                SP_offset += immidiate;
            } else if (strcmp(part1, "001001") || strcmp(part1, "001010")) {
                SP_offset -= immidiate;
            }
            strcpy(out, "");
            iflag = 2;
        }

    } else if (dis[1] == 'a') {
        strcat(out, "01111");
        // case %a@(n)
        // add #n,%a@
        if (isdigit(dis[4])) {
            char buff3[1024] = "";
            char buff4[1024] = "";
            int reg = pare(dis);
            strcat(buff3, "\t001000 00011 01111\n\t");
            for (int i = 15; i >= 0; i--) {
                char bit = ((reg >> i) & 1) + '0';
                strncat(buff3, &bit, 1);
            }
            strcat(buff4, buff3);
            strcat(buff4, "\n");
            strcat(buff4, out);
            strcpy(out, buff4);
            printf("%s\n", out);
        }
    }
    strcat(out, "\n\t");
    if (iflag == 1) {
        for (int i = 15; i >= 0; i--) {
            sprintf(temp, "%d", (immidiate >> i) & 1);
            strcat(out, temp);
        }
    } else if (iflag == 0) {
        strcat(out, "0000000000000000");
    }
    strcat(out, "\n");
    fprintf(file, out);
    fclose(file);
}

int pare(const char *str) {
    int i = 0;
    int start = -1, end = -1;
    // () の位置を探す
    while (str[i] != '\0') {
        if (str[i] == '(') {
            start = i + 1;
        } else if (str[i] == ')' && start != -1) {
            end = i;
            break;
        }
        i++;
    }

    if (start != -1 && end != -1 && end > start) {
        char buffer[32] = {0};
        int len = end - start;
        if (len >= (int)sizeof(buffer)) len = sizeof(buffer) - 1;

        for (i = 0; i < len; i++) {
            buffer[i] = str[start + i];
        }
        buffer[len] = '\0';
        return atoi(buffer);
    }

    return -1;
}

char *angl(const char *str) {
    int i = 0;
    int start = -1, end = -1;

    while (str[i] != '\0') {
        if (str[i] == '<') {
            start = i + 1;
        } else if (str[i] == '>' && start != -1) {
            end = i;
            break;
        }
        i++;
    }

    if (start != -1 && end != -1 && end > start) {
        int len = end - start;
        char *result = (char *)malloc(len + 1);
        if (result == NULL) {
            perror("malloc failed");
            return NULL;
        }

        for (i = 0; i < len; i++) {
            result[i] = str[start + i];
        }
        result[len] = '\0';
        return result;
    }

    // 見つからなかった場合、NULLを返す
    return NULL;
}

void JMP(char *word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    if (!file) {
        perror("fopen");
        return;
    }
    char word_copy[256];
    strncpy(word_copy, word, sizeof(word_copy) - 1);
    word_copy[sizeof(word_copy) - 1] = '\0';
    char temp[100];
    strcpy(temp, angl(word));
    strcat(out, " 00011");
    strcat(out, " 00100\n\t");
    strcat(out, "<");
    strcat(out, temp);
    strcat(out, ">\n");
    fprintf(file, out);
    printf("\n%s\n", out);

    fclose(file);
}

void JSR(char *word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    if (!file) {
        perror("fopen");
        return;
    }
    char word_copy[256];
    strncpy(word_copy, word, sizeof(word_copy) - 1);
    word_copy[sizeof(word_copy) - 1] = '\0';
    char temp[100];
    strcpy(temp, angl(word));
    strcat(out, " <");
    strcat(out, temp);
    strcat(out, "> ");
    strcat(out, "00011\n");
    fprintf(file, out);
    printf("\n%s\n", out);

    fclose(file);
}

char *get_before_colon(const char *input) {
    const char *colon = strchr(input, ':');
    if (colon == NULL) {
        return NULL;  // コロンが見つからなかった
    }

    int len = colon - input;  // ':' までの長さ
    char *result = (char *)malloc(len + 1);
    if (result == NULL) {
        perror("malloc failed");
        return NULL;
    }

    strncpy(result, input, len);
    result[len] = '\0';  // 終端文字を追加

    return result;
}
void pea(char *word, char *out) {
    char temp[16] = "";
    FILE *file = fopen("lavel2.txt", "a");
    int address = SP + SP_offset;
    int immidiate = atoi(word);
    strcat(out, "\t000000 00011 01010\n\t");
    for (int i = 15; i >= 0; i--) {
        sprintf(temp, "%d", (immidiate >> i) & 1);
        strcat(out, temp);
    }

    strcat(out, "\n\t000000 01010 00011\n\t");
    for (int i = 15; i >= 0; i--) {
        sprintf(temp, "%d", (address >> i) & 1);
        strcat(out, temp);
    }
    SP_offset -= 2;
    strcat(out, "\n");
    fprintf(file, out);
    fclose(file);
}
