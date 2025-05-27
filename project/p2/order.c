#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/asm.h"

void MOVEn(char **word, char *out) {
    FILE *file;
    file = fopen("lavel2.txt", "a");
    strcat(out, "\t000000");
    int i = 0;
    char *comma;
    fclose(file);
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');  // カンマを探す
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
    // soures(word[i]);
}
void LSRn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t000001");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void ASLn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t000010");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void ASRn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t000011");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void ROLn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t000100");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void RORn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t000101");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void RCLn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t000110");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void RCRn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t000111");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void ADDn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t001000");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void SUBAn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t001001");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void SUBSn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t001010");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void ORn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t001011");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void ANDn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t001100");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void NOTn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t001101");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void XORn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t001110");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void XNORn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t001111");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void JMPn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t000000");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        // printf("%d",i);
        comma = strchr(word[i], '<');
        // printf("word[%d]: %s\n", i, word[i]);
        if (comma != NULL) {
            // printf("word[%d]: %s\n", i, comma);
            JMP(word[i], out);
            break;
        }
        i++;
    }
}

void PUSHn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t000000 XXXXX 01110");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void POPn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t000000 01110 YYYYY");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void MOVECn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t011FFF XXXXX YYYYY");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void MOVNCn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t010FFF XXXXX YYYYY");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void BEQn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t011011");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        // printf("%d",i);
        comma = strchr(word[i], '<');
        // printf("word[%d]: %s\n", i, word[i]);
        if (comma != NULL) {
            // printf("word[%d]: %s\n", i, comma);
            JMP(word[i], out);
            break;
        }
        i++;
    }
}
void BNEn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t010FFF XXXXX 00011");
    fclose(file);
    int i = 0;
    char *comma;
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            soures(word[i], out);
            break;
        }
        i++;
    }
}

void RTSn(char **word, char *out) {
    FILE *file = fopen("lavel2.txt", "a");
    strcat(out, "\t000000 01110 11110\n\t0000000000000000\n");
    fprintf(file, "%s", out);
    fclose(file);
}

void CMPn(char **word, char *out) {
    // cmpl X,Y
    char out2[64] = "";
    char out3[64] = "";
    int i = 0;
    char *comma;
    char *word2[36];
    char word_copy[256];
    char move_cmd[128];
    char sub_cmd[128];
    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            break;
        }
        i++;
    }
    strncpy(word_copy, word[i], sizeof(word_copy) - 1);
    word_copy[sizeof(word_copy) - 1] = '\0';
    char *sou = strtok(word_copy, ",");  // X
    char *dis = strtok(NULL, ",");       // Y
    if (strcmp(sou, "%%sp") == 0) {
        strcat(sou, "@");
    }
    if (strcmp(dis, "%%sp") == 0) {
        strcat(dis, "@");
    }
    word2[0] = "MOVE";
    snprintf(move_cmd, sizeof(move_cmd), "%s,%%d7",
             sou);  // %% → %を文字として出力
    word2[1] = move_cmd;
    MOVEn(word2, out);  // X → %d7
    snprintf(move_cmd, sizeof(move_cmd), "%s,%%d6",
             dis);  // %% → %を文字として出力
    word2[1] = move_cmd;
    MOVEn(word2, out2);  // Y → %d6
    word2[0] = "SUB";
    snprintf(sub_cmd, sizeof(sub_cmd), "%%d6,%%d7");
    word2[1] = sub_cmd;
    SUBSn(word, out3);
    // 次の命令でzフラグを比較する
}

void PEAn(char **word, char *out) {
    int i = 0;
    char *comma;
    char move_cmd[128];

    while (word[i] != NULL) {
        comma = strchr(word[i], ',');
        // printf("word[%d]: %s", i, word[i]);
        if (comma != NULL) {
            break;
        }
        i++;
    }
    // printf("\n%s\n",word[i-2]);
    pea(word[i - 2], out);
}