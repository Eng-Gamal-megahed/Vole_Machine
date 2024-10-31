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
     reg.set_cell(cellR, reg.get_cell(cellS) + reg.get_cell(cellT));
}

// Load (1) to store the content of some cell in memory in the registre
void CPU::load(int cell_of_reg, int cell_of_memo , Register & reg, Memory & memo)
{

    reg.set_cell(cell_of_reg, memo.get_cell(cell_of_memo) );
}

// Load (2) to store the input direct in register (done)
void CPU::load(int index_of_reg, int val, Register &reg)
{
    reg.set_cell(index_of_reg,to_string(val));
}


void CPU::store(int cell_in_reg, int cell_in_memo, Register & reg, Memory & memo)
{
    memo.set_cell(cell_in_memo, reg.get_cell(cell_in_reg) );
}


void CPU::move(int cell1, int cell2, Register & reg)
{
    //Move the content of cell1 to cell2 in register.
    reg.set_cell(cell2, reg.get_cell(cell1));
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

// ====================================== Mustafa =======================================================

void CPU::fetch(Memory *){

    if (PC > 255){
        cout << "Memory ended!" << endl;
        exit(0);
    }

    // Use PC as the address to fetch from memory
    IR = ptr->get_cell(PC);
    PC++; // Increment the Program Counter to the next instruction
    IR += ptr->get_cell(PC);
    PC++;

}

vector<int> CPU::decode(){

    vector<int> operation(3);
    if (IR.size() == 10 ){
        string newIR = to_string(IR[2]);
        newIR += to_string(IR[5]);
        newIR += to_string(IR[8]);
        newIR += to_string(IR[9]);
        IR = newIR;
    }

    if (IR.size() != 4 ){
        return operation;
    }

    operation[0]= IR[0] - '0';
    cout << stoi( string (1, IR[1])  , nullptr, 16) << endl;
    operation[1]= stoi( string (1, IR[1])  , nullptr, 16);
    cout << stoi( IR.substr(2, 2) , nullptr, 16) << endl;
    operation[2]= stoi( IR.substr(2, 2) , nullptr, 16);

    return operation;
}

void CPU::execute(Register &, Memory *, vector<int> vec){

    string reg_address = dec_to_hexa(vec[2]);

    if (vec[0] == 1)
    {
        load(vec[1], vec[2] , reg , * ptr); // the value is converted into decimal and stored ******* not hex
    }

    else if (vec[0] == 2)
    {
        load(vec[1], vec[2], reg);
    }

    else if (vec[0] == 3)
    {
        if (vec[2] == 0)
        {
            cout << reg.get_cell(vec[1]) << endl;
        }

        store(vec[1], vec[2],  reg, * ptr);
    }

    else if (vec[0] == 4)
    {
        move(stoi( string (1, reg_address[0])  , nullptr, 16), stoi( string (1, reg_address[1])  , nullptr, 16),  reg);
    }

    else if (vec[0] == 5)
    {
        add5(vec[1], stoi( string (1, reg_address[0])  , nullptr, 16), stoi( string (1, reg_address[1])  , nullptr, 16), reg);
    }

    else if (vec[0] == 6)
    {
        add6(vec[1], stoi( string (1, reg_address[0])  , nullptr, 16), stoi( string (1, reg_address[1])  , nullptr, 16), reg);
    }
    else if (vec[0] == 11)
    {
        // Jump ()
    }
    else if (vec[0] == 12 && vec[1] == 0 && vec[2] == 0)
    {
        exit(0); // Halt ()
    }

}

