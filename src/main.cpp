#include <stdio.h> 
#include <iostream> 
#include <ctime> 
#include <vector> 
#include <string.h> 

#define N 100 

using namespace std; 

struct word { 
char engWord[N]; 
char rusWord[N]; 
}; 

int inputFile(char *nameFile, vector<word> &list) 
{ 
FILE *fp; 
fopen_s(&fp, nameFile, "r"); 
if (fp) { 
while (!feof(fp)) 
{ 
int i = 0; 
word temp; 
fscanf_s(fp, "%c", &temp.engWord[0]); 
for (i = 1; temp.engWord[i - 1] != '-'; i++) 
fscanf_s(fp, "%c", &temp.engWord[i]); 
temp.engWord[i - 1] = '\0'; 
fscanf_s(fp, "%c", &temp.rusWord[0]); 
for (i = 1; temp.rusWord[i - 1] != '\n' && !feof(fp); i++) 
fscanf_s(fp, "%c", &temp.rusWord[i]); 
temp.rusWord[i - 1] = '\0'; 
list.push_back(temp); 
} 
} 
else return 0; 
return 1; 
} 

void test(vector<word> list) 
{ 
int size = list.size(); 
printf("%d", size); 
system("pause"); 
system("cls"); 
while (1) 
{ 
system("cls"); 
srand(time(0)); 
int random = rand() % size; 
auto l = list.begin() + random; 
printf(" %s ", l->rusWord); 
char word[N]; 
scanf_s("%s", word, N); 
if (strcmp(word, l->engWord) == 0) printf("ПРАВИЛЬНО!!!!!!!!"); 
else printf("НЕПРАВИЛЬНО!!! А ПРАВИЛЬНО БУДЕТ - %s", l->engWord); 
system("pause"); 
} 
} 

int main() 
{ 
setlocale(LC_ALL, "Russian"); 
int nf; 
vector<word> list; 
printf("Выберите файл:\n 1) Еда\n 2) Комната\n 3) Город\n "); 
scanf_s("%d", &nf); 
switch (nf) 
{ 
case 1: 
{ 
char nameFile[N] = "food.txt"; 
if (!inputFile(nameFile, list)) { printf("Файл не найден :(\n"); system("pause"); return 1; } 
break; 
} 
case 2: 
{ 
char nameFile[N] = "room.txt"; 
if (!inputFile(nameFile, list)) { printf("Файл не найден :(\n"); system("pause"); return 1; } 
break; 
} 
case 3: 
{ 
char nameFile[N] = "city.txt"; 
if (!inputFile(nameFile, list)) { printf("Файл не найден :(\n"); system("pause"); return 1; } 
break; 
} 
} 
system("cls"); 
test(list); 
system("pause"); 
}
