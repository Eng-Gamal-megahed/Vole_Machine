#include "Vole_Machine.h"
#include <cmath>

string Memory::get_cell(int idx)
{
    return memory[idx];
}

void Memory::set_cell(int idx , string code)
{
    memory[idx] = code;
}


int Register::get_cell(int idx)
{
    return memory[idx];
}

void Register::set_cell(int idx , int val)
{
    memory[idx] = val;
}

string CPU::hexa_to_dec(string num)
{
    int res = 0;
    for (int i = 0; i < num.size(); ++i) {
        int digit;
        if(num[i] >= 'A' && num[i] <= 'f'){
            digit = num[i] - 55;
        }
        else
        {
            digit = num[i] - '0';
        }
        res += digit * (pow(16 , i));

    }
    return to_string(res);
}

string CPU::dec_to_hexa(string num)
{
    string res = "";
    int inum = stoi(num);
    while(inum)
    {
        int reminder = inum % 16;
        if(reminder >= 10)
        {
            res += reminder + 55;
        }
        else
        {
            res += reminder + '0';
        }
        inum /= 16;
    }
    return res;
}


