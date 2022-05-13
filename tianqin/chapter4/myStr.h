typedef struct myStr* string;
typedef struct myStr{
    char* s;
    int length;
}myStr;

string initMyStr(char*);
int strAssign(string, char*);
int strLen(string);
int strCmp(string, string);
string concat(string, string);
int subStr(string, string, int, int);
int clearString(string);
int print(string);