#include "Vole_Machine.h"
#include <iostream>
#include<string>
#include <cmath>


void CPU::add5(int cellR, int cellS, int cellT, Register &reg)
{
    reg.set_cell_in_register(cellR, (reg.get_cell(cellS)+reg.get_cell(cellT)));
}

void CPU::add6(int cellR, int cellS, int cellT, Register &reg)
{
    CPU temp;
    reg.set_cell(cellR, temp.floating_point_notation(cellS, cellT));
}

// Load (1) to store the content of some cell in memory in the registre
void CPU::load(int cell_of_reg, int cell_of_memo , Register & reg, Memory & memo)
{
    reg.set_cell(cell_of_reg, memo.get_cell(cell_of_memo));
}

// Load (2) to store the input direct in register (done)
void CPU::load(int index_of_reg, int val, Register &reg)
{
    reg.set_cell(index_of_reg, val);
}


void CPU::store(int cell_in_reg, int cell_in_memo, Register & reg, Memory & memo)
{
    memo.set_cell(cell_in_memo, reg.get_cell(cell_in_reg));
}


void CPU::move(int cell1, int cell2, Register & reg)
{
    //Move the content of cell1 to cell2 in register.
    reg.set_cell(cell2, reg.get_cell(cell1));
}

int CPU::floating_point_notation(int, int)
{
    return 0;
}


string Memory::get_cell(int idx)
{
    return memory[idx];
}


void Memory::set_cell(int idx, string code)
{

    memory[idx] = code;
}


int Register::get_cell(int idx)
{
    return memory[idx];
}

void Register::set_cell(int index, int val)
{
    memory[index] = val;
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


