#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/asm.h"

int main() {
    LabelInfo label[MAX_LINES];
    FILE *file;
    char buffer[256];
    char token[8];
    char *chara;
    int line = 0;
    int row = 0;
    int addres = 0;
    const int MAX_WORDS = 256;
    const char *word[MAX_WORDS];
    char out[64];
    const char *pea_list[] = PEA_LIST;
	int pea_list_size = sizeof(pea_list) / sizeof(pea_list[0]);
	const char *move_list[] = MOVE_LIST;
	int move_list_size = sizeof(move_list) / sizeof(move_list[0]);
	const char *add_list[] = ADD_LIST;
	int add_list_size = sizeof(add_list) / sizeof(add_list[0]);
	const char *sub_list[] = SUB_LIST;
	int sub_list_size = sizeof(sub_list) / sizeof(sub_list[0]);
	const char *and_list[] = AND_LIST;
	int and_list_size = sizeof(and_list) / sizeof(and_list[0]);
	const char *or_list[] = OR_LIST;
	int or_list_size = sizeof(or_list) / sizeof(or_list[0]);
	const char *eor_list[] = EOR_LIST;
	int eor_list_size = sizeof(eor_list) / sizeof(eor_list[0]);
	const char *not_list[] = NOT_LIST;
	int not_list_size = sizeof(not_list) / sizeof(not_list[0]);
	const char *cmp_list[] = CMP_LIST;
	int cmp_list_size = sizeof(cmp_list) / sizeof(cmp_list[0]);
	const char *mul_list[] = MUL_LIST;
	int mul_list_size = sizeof(mul_list) / sizeof(mul_list[0]);
	const char *div_list[] = DIV_LIST;
	int div_list_size = sizeof(div_list) / sizeof(div_list[0]);
	const char *shift_list[] = SHIFT_LIST;
	int shift_list_size = sizeof(shift_list) / sizeof(shift_list[0]);
	const char *rotate_list[] = ROTATE_LIST;
	int rotate_list_size = sizeof(rotate_list) / sizeof(rotate_list[0]);
	const char *neg_list[] = NEG_LIST;
	int neg_list_size = sizeof(neg_list) / sizeof(neg_list[0]);
	const char *tst_list[] = TST_LIST;
	int tst_list_size = sizeof(tst_list) / sizeof(tst_list[0]);
	const char *bit_list[] = BIT_LIST;
	int bit_list_size = sizeof(bit_list) / sizeof(bit_list[0]);
	const char *lea_list[] = LEA_LIST;
	int lea_list_size = sizeof(lea_list) / sizeof(lea_list[0]);
	const char *ext_list[] = EXT_LIST;
	int ext_list_size = sizeof(ext_list) / sizeof(ext_list[0]);
	const char *swap_list[] = SWAP_LIST;
	int swap_list_size = sizeof(swap_list) / sizeof(swap_list[0]);
	const char *exg_list[] = EXG_LIST;
	int exg_list_size = sizeof(exg_list) / sizeof(exg_list[0]);
	const char *dbcc_list[] = DBCC_LIST;
	int dbcc_list_size = sizeof(dbcc_list) / sizeof(dbcc_list[0]);
	const char *scc_list[] = SCC_LIST;
	int scc_list_size = sizeof(scc_list) / sizeof(scc_list[0]);
	const char *bra_list[] = BRA_LIST;
	int bra_list_size = sizeof(bra_list) / sizeof(bra_list[0]);
	const char *jmp_list[] = JMP_LIST;
	int jmp_list_size = sizeof(jmp_list) / sizeof(jmp_list[0]);
	const char *return_list[] = RETURN_LIST;
	int return_list_size = sizeof(return_list) / sizeof(return_list[0]);
	const char *beq_list[] = BEQ_LIST;
	int beq_list_size = sizeof(beq_list) / sizeof(beq_list[0]);
	const char *bne_list[] = BNE_LIST;
	int bne_list_size = sizeof(bne_list) / sizeof(bne_list[0]);

    file = fopen("build/main.asm", "r");
    if (file == NULL) {
        perror("ファイルを開くことができません");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
        chara = strtok(buffer, " ");
        row = 0;

        while (chara != NULL) {
            char *semicolon = strchr(chara, ';');
            if (semicolon != NULL) {
                *semicolon = '\0';
            }

            word[row] = strdup(chara);
            if (word[row] == NULL) {
                perror("メモリ割り当てに失敗しました");
                fclose(file);
                return 1;
            }
            chara = strtok(NULL, " ");
            row++;

        }        
        for (int i = 0; i < row; i++) {
            if (word[i] == NULL) {
                printf("word[%d] is NULL (line %d)\n", i, line);
                continue;}

            strip_newline(word[i]);            
            

            printf("%s<%d>",word[i],i);
if (orderserch(word[i], move_list, move_list_size, "move", token)) ;
else if (orderserch(word[i], add_list, add_list_size, "add", token)) ;
else if (orderserch(word[i], sub_list, sub_list_size, "sub", token)) ;
else if (orderserch(word[i], and_list, and_list_size, "and", token)) ;
else if (orderserch(word[i], or_list, or_list_size, "or", token)) ;
else if (orderserch(word[i], eor_list, eor_list_size, "eor", token)) ;
else if (orderserch(word[i], not_list, not_list_size, "not", token)) ;
else if (orderserch(word[i], cmp_list, cmp_list_size, "cmp", token)) ;
else if (orderserch(word[i], mul_list, mul_list_size, "mul", token)) ;
else if (orderserch(word[i], div_list, div_list_size, "div", token)) ;
else if (orderserch(word[i], shift_list, shift_list_size, "shift", token)) ;
else if (orderserch(word[i], rotate_list, rotate_list_size, "rotate", token)) ;
else if (orderserch(word[i], neg_list, neg_list_size, "neg", token)) ;
else if (orderserch(word[i], tst_list, tst_list_size, "tst", token)) ;
else if (orderserch(word[i], bit_list, bit_list_size, "bit", token)) ;
else if (orderserch(word[i], lea_list, lea_list_size, "lea", token)) ;
else if (orderserch(word[i], ext_list, ext_list_size, "ext", token)) ;
else if (orderserch(word[i], swap_list, swap_list_size, "swap", token)) ;
else if (orderserch(word[i], exg_list, exg_list_size, "exg", token)) ;
else if (orderserch(word[i], dbcc_list, dbcc_list_size, "dbcc", token)) ;
else if (orderserch(word[i], scc_list, scc_list_size, "scc", token)) ;
else if (orderserch(word[i], bra_list, bra_list_size, "bra", token)) ;
else if (orderserch(word[i], jmp_list, jmp_list_size, "jmp", token)) ;
else if (orderserch(word[i], return_list, return_list_size, "rts", token)) ;
else if (orderserch(word[i], beq_list, beq_list_size, "beq", token)) ;
else if (orderserch(word[i], bne_list, bne_list_size, "bne", token)) ;
else if (orderserch(word[i], pea_list, pea_list_size, "pea", token)) ;

}
        //orderserch((char **)word,row,(char *)token);

        printf("order:%s,%s\n",token,word[1]);
        excelist((char **)word);
        orderlist(token,(char **)word,(char *)out);
        for (int i = 0; i < row; i++) {
            free((void *)word[i]);
        }
        line+=1;
        word[row+1] = NULL;

        memset(out, 0, sizeof(out));
        memset(token,0,sizeof(token));
    }
    
    fclose(file);
    deline();
    extract_labels(label);
    declon();
    replace_labels_with_lines(label);
    return 0;
}

void print(int row){
        FILE *file = fopen("lavel2.txt", "a");
        fprintf(file, "%d:",row);
        fclose(file);
}
void orderlist(char *token,  char **word,char *output){

        if (word[0] == NULL) {
        printf("Invalid keyword\n");
        return;
    }

    // 構文リスト　able to find there
    enum index {
        MOVE, LSR, ASL, ASR, ROL, ROR, RCL, RCR,
        ADD, SUBA, SUBS, OR, AND, NOT, XOR, XNOR,
        JMP, PUSH, POP, MOVEC, MOVNC, BEQ, BNE,BRA,
        RTS, CMP,PEA,
        TOK_UNKNOWN
    };
    enum index tokenn = TOK_UNKNOWN;
    if (strcmp(token, "move") == 0) {
        tokenn = MOVE;
    } else if (strcmp(token, "lsr") == 0) {
        tokenn = LSR;
    } else if (strcmp(token, "asl") == 0) {
        tokenn = ASL;
    } else if (strcmp(token, "asr") == 0) {
        tokenn = ASR;
    } else if (strcmp(token, "rol") == 0) {
        tokenn = ROL;
    } else if (strcmp(token, "ror") == 0) {
        tokenn = ROR;
    } else if (strcmp(token, "rcl") == 0) {
        tokenn = RCL;
    } else if (strcmp(token, "rcr") == 0) {
        tokenn = RCR;
    } else if (strcmp(token, "add") == 0) {
        tokenn = ADD;
    } else if (strcmp(token, "sub") == 0) {
        tokenn = SUBA;
    } else if (strcmp(token, "subs") == 0) {
        tokenn = SUBS;
    } else if (strcmp(token, "or") == 0) {
        tokenn = OR;
    } else if (strcmp(token, "and") == 0) {
        tokenn = AND;
    } else if (strcmp(token, "not") == 0) {
        tokenn = NOT;
    } else if (strcmp(token, "xor") == 0) {
        tokenn = XOR;
    } else if (strcmp(token, "xnor") == 0) {
        tokenn = XNOR;
    } else if (strcmp(token, "jmp") == 0) {
        tokenn = JMP;
    } else if (strcmp(token, "push") == 0) {
        tokenn = PUSH;
    } else if (strcmp(token, "pop") == 0) {
        tokenn = POP;
    } else if (strcmp(token, "movec") == 0) {
        tokenn = MOVEC;
    } else if (strcmp(token, "movnc") == 0) {
        tokenn = MOVNC;
    } else if (strcmp(token, "beq") == 0) {
        tokenn = BEQ;
    } else if (strcmp(token, "bne") == 0) {
        tokenn = BNE;
    }else if (strcmp(token, "bra") == 0) {
        tokenn = BRA;
    }else if (strcmp(token, "rts") == 0) {
        tokenn = RTS;
    }else if (strcmp(token, "cmp") == 0) {
        tokenn = CMP;
    }else if (strcmp(token, "pea") == 0) {
        tokenn = PEA;
    }


    switch (tokenn) {
        case MOVE:   MOVEn((char **)word,output);   break;
        case LSR:    LSRn((char **)word,output);    break;
        case ASL:    ASLn((char **)word,output);    break;
        case ASR:    ASRn((char **)word,output);    break;
        case ROL:    ROLn((char **)word,output);    break;
        case ROR:    RORn((char **)word,output);    break;
        case RCL:    RCLn((char **)word,output);    break;
        case RCR:    RCRn((char **)word,output);    break;
        case ADD:    ADDn((char **)word,output);    break;
        case SUBA:   SUBAn((char **)word,output);   break;
        case SUBS:   SUBSn((char **)word,output);   break;
        case OR:     ORn((char **)word,output);     break;
        case AND:    ANDn((char **)word,output);    break;
        case NOT:    NOTn((char **)word,output);    break;
        case XOR:    XORn((char **)word,output);    break;
        case XNOR:   XNORn((char **)word,output);   break;
        case PUSH:   PUSHn((char **)word,output);   break;
        case POP:    POPn((char **)word,output);    break;
        case MOVEC:  MOVECn((char **)word,output);  break;
        case MOVNC:  MOVNCn((char **)word,output);  break;
        case JMP:
        //PC → %d5    
        strcat(output,"\t000000 00011 10101\n\t0000000000000000\n");
        //%d5+6→ %d5
        strcat(output,"\t000000 01100 10101\n\t0000000000000110\n");
        //push %d5
        strcat(output,"\t000000 10101 01110\n\t0000000000000000\n");//000000 10101 01110
        case BRA:
            JMPn((char **)word,output);   
            break;
        case BEQ:    BEQn((char **)word,output);    break;
        case BNE:    BNEn((char **)word,output);    break;
        case RTS:    RTSn((char **)word,output);    break;
        case CMP:    CMPn((char **)word,output);    break;
        case PEA:    PEAn((char **)word,output);    break;
        default:
            printf("Keyword not found\n");
            FILE *file = fopen("want.txt", "a");
            fprintf(file, "%s %s\n", word[1], word[2]);  // ← ここで必ず改行を含める
            fclose(file);
            break;
    }
}

void strip_newline(char *str) {
    char *dst = str;
    while (*str != '\0') {
        if (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\r') {
            *dst++ = *str;
        }
        str++;
    }
    *dst = '\0';  // 終端
}

int orderserch(const char *word, const char **list, int list_size, const char *name, char *token_out) {
    for (int j = 0; j < list_size; j++) {
        if (strcmp(word, list[j]) == 0) {
            strcpy(token_out, name);
            return 1;  // 見つかった
        }
    }
    return 0;  // 見つからなかった
}

void excelist(char **word) {
    if (!word || !word[0] || !word[1]) {
        printf("Invalid keyword\n");
        return;
    }

    enum index {
        INT, TOK_UNKNOWN
    };
    enum index tokenn = TOK_UNKNOWN;
    if (strcmp(word[1], "file") == 0) {
        tokenn = INT;
    }
    switch (tokenn) {
        case INT:
            FILE *file = fopen("lavel2.txt", "w");
            fprintf(file, "%s\n", word[1]);  // ← ここで必ず改行を含める
            fclose(file);
            FILE *file2 = fopen("want.txt", "w");
            fprintf(file2, "未定義");  // ← ここで必ず改行を含める
            fclose(file2);
            break;
        default:
        if (angl(word[1]) != NULL){
            FILE *file = fopen("lavel2.txt", "a");
            fprintf(file, "%s %s\n", word[0],word[1]);  // ← ここで必ず改行を含める
            fclose(file);
        }
            break;
    }
}
