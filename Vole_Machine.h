#include <iostream>
#include <vector>
using namespace std;


class CPU;
class CU;
class Register;
class ALU;
class Memory;
class Machine;


class Register
{
private:
    int memory[16];
    int size = 16;

public:
    int get_cell(int*);
    void set_cell(int* , int);
};

class ALU{

};

class CU{
public:
    void load(int , int , Register& , Memory&);
    void load(int , int , Register&);
    void store(int , int , Register& , )
};
class Memory{
private:
    string memory[256];
    int size = 256;
public:
    string get_cell(int*);
    void set_cell(int* , string);
};

class CPU{
private:
    Memory *ptr;
    int PC;
    string IR;
    Register reg;
    CU cu;
    ALU alu;
public:
    CPU(Memory*);
    void runNextStep(Memory*);
    void fetch(Memory*);
    vector<int> decode();
    void excute(Register& , Memory* , vector<int>);
};




class Machine{
private:
    Memory storage;
    CPU cpu;
public:

};

