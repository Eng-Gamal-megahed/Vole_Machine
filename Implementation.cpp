#include "Vole_Machine.h"
#include<string>
#include <cmath>
#include <sstream>


void CPU::add5(int cellR, int cellS, int cellT, Register &reg)
{
    int vals = get_twos_comp(stoi(reg.get_cell(cellS) , nullptr , 16));
    int valt = get_twos_comp(stoi(reg.get_cell(cellT) , nullptr , 16));
    int result = vals + valt;
    reg.set_cell(cellR , dec_to_hexa(result));
    // reg.set_cell(cellR, (reg.get_cell(cellS)+reg.get_cell(cellT)));
}

void CPU::add6(int cellR, int cellS, int cellT, Register &reg)
{
    // reg.set_cell(cellR, reg.get_cell(cellS)+reg.get_cell(cellT));
}

// Load (1) to store the content of some cell in memory in the registre
void CPU::load(int cell_of_reg, int cell_of_memo , Register & reg, Memory & memo)
{
    // reg.set_cell(cell_of_reg, stoi(memo.get_cell(cell_of_memo)));
}

// Load (2) to store the input direct in register (done)
void CPU::load(int index_of_reg, int val, Register &reg)
{
    // reg.set_cell(index_of_reg, val);
}


void CPU::store(int cell_in_reg, int cell_in_memo, Register & reg, Memory & memo)
{
    // memo.set_cell(cell_in_memo, to_string(reg.get_cell(cell_in_reg)));
}


void CPU::move(int cell1, int cell2, Register & reg)
{
    //Move the content of cell1 to cell2 in register.
    // reg.set_cell(cell2, reg.get_cell(cell1));
}




// ==================================================== Gamal =================================================



string Memory::get_cell(int idx)
{
    return memory[idx];
}


void Memory::set_cell(int idx, string code)
{

    memory[idx] = code;
}


string Register::get_cell(int idx)
{
    return memory[idx];
}

void Register::set_cell(int index, string val)
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

string CPU::dec_to_hexa(int val)
{
    stringstream stream;
    stream << hex << uppercase << (val & 0xFF);
    return stream.str();
}


int CPU::get_twos_comp(int val)
{
    if (val & 0x80) {
        return val - 256;
    } else {
        return val;
    }
}

int CPU::convert_to_twos_comp(int val) {
    if (val >= 0) {
        return val;
    } else {
        return (val + 256) & 0xFF;
    }
}


