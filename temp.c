#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Ch_Kind_t
{
Ch_NoFlag,
Ch_Flag
};

struct List_t
{
struct List_t *next;
enum Ch_Kind_t kind;
int x;
int y;
char *str;
};

struct List_t *List_new(enum Ch_Kind_t kind, int x, int y, char* str, struct List_t *next)
{
struct List_t *p = malloc(sizeof (*p));
p->kind = kind;
p->next = next;
p->x = x;
p->y = y;
p->str = str;
return p;
}

void List_reverse_print(struct List_t *list);
void emit(enum Ch_Kind_t kind, int x, int y, char* str);
void Read_Str(char insert, FILE *File, char *data_str);

struct List_t *all = 0;


int main()
{
FILE *Read;
int x = 1, y = 1;
char str[32];
char data_ch;
char state;


Read = fopen("text2.txt", "r");
while (0 == feof(Read)){
data_ch = fgetc(Read);
state = 1;
switch (data_ch){
case 'i':
data_ch = fgetc(Read);
state++;
if (data_ch == 'f'){
data_ch = fgetc(Read);
state++;
if (data_ch == ' '){
emit(Ch_Flag, x++, y, "IF");
}
else if (data_ch != '\n'){
memset(str, '\0', sizeof(str));
Read_Str(state, Read, str);
emit(Ch_NoFlag, x++, y, str);
}
}
else if ((data_ch >= 'a') &&
(data_ch <= 'z') ||
(data_ch >= 'A') &&
(data_ch <= 'Z') ||
(data_ch >= '0') &&
(data_ch <= '9')){
memset(str, '\0', sizeof(str));
Read_Str(state, Read, str);
emit(Ch_NoFlag, x++, y, str);
}
break;
case '\n':
y++;
x = 1;
break;
case ' ':
break;
default:
if ((data_ch >= 'a') &&
(data_ch <= 'z') ){
memset(str, '\0', sizeof(str));
Read_Str(state, Read, str);
emit(Ch_NoFlag, x++, y, str);
}
break;
}
}
List_reverse_print(all);
while (1);
return 0;
}

void Read_Str(char insert, FILE *File, char *data_str)
{
char Inser = -1 * insert;
char i = 0;
char data;
fseek(File, Inser, SEEK_CUR);
data = fgetc(File);
while ((data != ' ')){
data_str[i++] = data;
data = fgetc(File);
}
}
void emit(enum Ch_Kind_t kind, int x, int y, char* str)
{
all = List_new(kind, x, y, str, all);
}

void List_reverse_print(struct List_t *list)
{
switch (list->kind){
case Ch_Flag:{
if ((list->next) != NULL){
List_reverse_print(list->next);	  
}
printf("IF  (%d,%d)\n", list->y, list->x);
break;
}
case Ch_NoFlag:{
  if ((list->next) != NULL){
  List_reverse_print(list->next);	  
  }
  printf("ID(%s)  (%d,%d)\n", list->str, list->y, list->x);
  break;
}
default:
break;
}
}
