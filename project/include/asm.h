#ifndef ASM_H
#define ASM_H

#define SP 16384  // bin:0100000000000000,hex:4000

#define MOVE_LIST                                            \
    {"move",   "moveb", "movew", "movel", "movea", "moveal", \
     "moveaw", "movem", "movep", "movec", "moves", "moveq"}

#define ADD_LIST {"add", "adda", "addl", "addql", "addx", "addal"}
#define SUB_LIST {"sub", "suba", "subl", "subql", "subx", "subal"}
#define AND_LIST {"and", "andi"}
#define OR_LIST {"or", "ori"}
#define EOR_LIST {"eor", "eori"}
#define NOT_LIST {"not"}
#define CMP_LIST {"cmp", "cmpa", "cmpi", "cmpm", "cmpl"}

#define MUL_LIST {"muls", "mulu"}
#define DIV_LIST {"divs", "divu"}
#define SHIFT_LIST {"asl", "asr", "lsl", "lsr"}
#define ROTATE_LIST {"rol", "ror", "roxl", "roxr"}
#define NEG_LIST {"neg", "negx"}
#define TST_LIST {"tst"}
#define BIT_LIST {"btst", "bchg", "bclr", "bset"}
#define LEA_LIST {"lea"}
#define EXT_LIST {"ext", "extb"}
#define SWAP_LIST {"swap"}
#define EXG_LIST {"exg"}
#define BEQ_LIST {"beq", "dbeq", "seq", "beqw", "bges"}
#define BNE_LIST {"bne", "dbne", "sne"}
#define DBCC_LIST                                                    \
    {"dbcc", "dbcs", "dbeq", "dbge", "dbgt", "dbhi", "dble", "dbls", \
     "dblt", "dbmi", "dbne", "dbpl", "dbvc", "dbvs", "dbra"}
#define SCC_LIST                                             \
    {"scc", "scs", "seq", "sge", "sgt", "shi", "sle", "sls", \
     "slt", "smi", "sne", "spl", "svc", "svs", "st",  "sf"}
#define BRA_LIST {"bra", "bsr", "braw"}
#define JMP_LIST {"jmp", "jsr"}
#define RETURN_LIST {"rts", "rte", "rtr"}
#define PEA_LIST {"pea"}

int orderserch(const char *word, const char **list, int list_size,
               const char *name, char *token_out);
void orderlist(char *token, char **input, char *output);
void excelist(char **word);
void strip_newline(char *str);

int pare(const char *str);
char *angl(const char *str);

void print(int row);
char *get_before_colon(const char *input);

void soures(char *word, char *out);
void JMP(char *word, char *out);
void JSR(char *word, char *out);

void MOVEn(char **word, char *out);
void LSRn(char **word, char *out);
void ASLn(char **word, char *out);
void ASRn(char **word, char *out);
void ROLn(char **word, char *out);
void RORn(char **word, char *out);
void RCLn(char **word, char *out);
void RCRn(char **word, char *out);

void ADDn(char **word, char *out);
void SUBAn(char **word, char *out);
void SUBSn(char **word, char *out);
void ORn(char **word, char *out);
void ANDn(char **word, char *out);
void NOTn(char **word, char *out);
void XORn(char **word, char *out);
void XNORn(char **word, char *out);
void JMPn(char **word, char *out);
void PUSHn(char **word, char *out);
void POPn(char **word, char *out);
void MOVECn(char **word, char *out);
void MOVNCn(char **word, char *out);
void BEQn(char **word, char *out);
void BNEn(char **word, char *out);
void RTSn(char **word, char *out);
void CMPn(char **word, char *out);
void PEAn(char **word, char *out);
void pea(char *word, char *out);

#define MAX_LINES 1024
#define MAX_LABEL 128

typedef struct {
    int line_number;
    int add_offset;
    char label[MAX_LABEL];
} LabelInfo;

void deline();
void declon();
int is_blank_line(const char *line);
void extract_labels(LabelInfo labels[MAX_LINES]);
void replace_labels_with_lines(LabelInfo labels[]);
int hex_to_int(const char *hex);

#endif