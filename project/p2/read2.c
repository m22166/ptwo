#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/asm.h"

int is_blank_line(const char *line) {
    for (int i = 0; line[i] != '\0'; i++) {
        if (!isspace((unsigned char)line[i])) {
            return 0; 
        }
    }
    return 1;
}

void deline() {
    FILE *file = fopen("lavel2.txt", "r");
    if (file == NULL) {
        perror("ファイルを開けません（読み込み）");
        return;
    }
    char buffer[8192] = "";
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (!is_blank_line(line)) {
            strcat(buffer, line);
        }
    }
    fclose(file);
    file = fopen("lavel2.txt", "w");
    if (file == NULL) {
        perror("ファイルを開けません（書き込み）");
        return;
    }
    fputs(buffer, file);
    fclose(file);
}




void extract_labels(LabelInfo labels[MAX_LINES]) {
    FILE *file = fopen("lavel2.txt", "r");
    if (!file) {
        perror("ファイルを開けません");
        return;
    }

    char line[256];
    int line_count = 0;
    
    int label_count = 0;

    while (fgets(line, sizeof(line), file)) {
        char *colon = strchr(line, ':');
        if (colon) {
            char *start = strchr(line, '<');
            char *end = strchr(line, '>');

            if (start && end && end > start) {
                size_t len = end - start - 1;
                if (len >= MAX_LABEL) len = MAX_LABEL - 1;

                strncpy(labels[label_count].label, start + 1, len);
                labels[label_count].label[len] = '\0';
                labels[label_count].line_number = line_count -1 -label_count;
                label_count++;
            }
        }
        line_count++;
    }

    fclose(file);

    // 出力
    printf("抽出されたラベル:\n");
    for (int i = 0; i < label_count; ++i) {
        printf("行 %d: <%s>\n", labels[i].line_number, labels[i].label);
    }
}
int hex_to_int(const char *hex) {
    int result = 0;
    sscanf(hex, "%x", &result);
    return result;
}
void replace_labels_with_lines(LabelInfo labels[]) {
    FILE *file = fopen("lavel2.txt", "r");
    if (!file) {
        perror("ファイルを開けません（読み込み）");
        return;
    }

    char output[MAX_LINES * 256] = "";  // 全体の出力
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        char *start = strchr(line, '<');
        char *end = strchr(line, '>');

        if (start && end && end > start) {
            char label[MAX_LABEL];
            size_t len = end - start - 1;
            if (len >= MAX_LABEL) len = MAX_LABEL - 1;

            strncpy(label, start + 1, len);
            label[len] = '\0';
            // "+" の位置を探す
            char *plus = strchr(label, '+');
            char base_label[MAX_LABEL] = "";
            int offset = 0;

            if (plus) {
                strcpy(base_label, label);
                *plus = '\0';  // base_label 部分を切り出し
                offset = hex_to_int(plus + 1);
            } else {
            }
            // ラベルを探して数値に変換
            int found = 0;
            
            for (int i = 0; i < MAX_LINES; i++) {
                if (strcmp(label, labels[i].label) == 0) {
                    char replaced_line[256];
                    int value = labels[i].line_number + offset;
                    *start = '\0';  // ラベル前の部分を切り出す
    strcat(output,"\t");
                    	
                    for (int i = 15; i >= 0; i--) {
		                    sprintf(replaced_line, "%d", (value >> i) & 1);
		                    strcat(output, replaced_line);
	                    }      
                    strcat(output,"\n");              
                    found = 1;
                    break;
                }
            }

            if (!found) {
                // 一致しないラベル → そのまま追加
                strcat(output, line);
                printf("%s",label);

            }

        } else {
            // ラベルなし → そのまま追加
            strcat(output, line);
        }
    }

    fclose(file);

    // 書き戻し
    file = fopen("lavel2.txt", "w");
    if (!file) {
        perror("ファイルを開けません（書き込み）");
        return;
    }

    fputs(output, file);
    fclose(file);
    printf("ラベルを行番号に置き換えました。\n");
}


void declon() {
    FILE *file = fopen("lavel2.txt", "r");
    if (file == NULL) {
        perror("ファイルを開けません（読み込み）");
        return;
    }

    char buffer[8192] = "";
    char line[256];

    while (fgets(line, sizeof(line), file) != NULL) {
        // 空白行または : を含むラベル行をスキップ
        if (is_blank_line(line) || strchr(line, ':') != NULL) {
            continue;
        }
        strcat(buffer, line);
    }
    fclose(file);

    // 上書き保存
    file = fopen("lavel2.txt", "w");
    if (file == NULL) {
        perror("ファイルを開けません（書き込み）");
        return;
    }
    fputs(buffer, file);
    fclose(file);
}