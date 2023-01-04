#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;
//////////////////converts the numbers on the file  from string to long ints///////////////////////////
uint32_t wordToInt(string word);


////////////////////////////////converts long int into hex string///////////////////////////////

string intToHexString(uint32_t number);

////////////////CHECKS IF THE WORD CONTAINS ANY OF THE ELEMENTS IN THE ARRAY DIGITS /////////////////////////
bool contain(string word, char digits[]);

////////////////////////////////ADD function///////////////////////////////
void add(string *registers, string r[]);
////////////////////////////////SUB function///////////////////////////////
void sub(string *registers, string r[]);

////////////////////////////////AND function///////////////////////////////
void bitAnd(string *registers, string r[]);
////////////////////////////////OR function///////////////////////////////
void bitOr(string *registers, string r[]);
////////////////////////////////XOR function///////////////////////////////
void bitXor(string *registers, string r[]);

////////////////////////////////LSL function///////////////////////////////
void lsl(uint32_t array[]);

////////////////////////////////LSR function///////////////////////////////
void lsr(uint32_t array[]);

////////////////////////////////ASR function///////////////////////////////
void asr(string *registers, string r[], int shifts);
////////////////////////////////LSL function///////////////////////////////
void lsl(string *registers, string r[], int shifts);;
////////////////////////////////LSR function///////////////////////////////
void lsr(string *registers, string r[], int shifts);
void mov(string *registers, uint32_t operands[], string r[]);