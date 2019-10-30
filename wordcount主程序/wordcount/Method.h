#pragma once
#include<queue>
#include"phrasetable.h"
using namespace std;
void get_cmd(int argc, char *argv[]);
int turn_lowercase_and_WordLine_count(char *);
char *Get_phrase(char *str, int pos, int len);
void pos_word(char *str,queue<int>&);
int Get_end(char *str, int i);
void Data_output(phrasetable);