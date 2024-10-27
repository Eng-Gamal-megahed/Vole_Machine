#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CPU;
class Register;
class Memory;
class Machine;

class Register
{
private:
    int memory[16];
    int size = 16;

public:
    int get_cell(int);
    void set_cell_in_register(int, string);
};

class Memory
{
private:
    string memory[256];
    int size = 256;

public:
    string get_cell(int);
    void set_cell(int, int);
};

class CPU
{
private:
    Memory *ptr;
    int PC;
    string IR;
    Register reg;

public:
    CPU(Memory *memory) : ptr(memory), PC(0), IR("") {}
    string hexa_to_dec(string);
    string dec_to_hexa(string);
    int two_complement(int, int);
    bool is_valid();
    int floating_point_notation(int, int);
    void add5(int, int, int, Register &);
    void add6(int, int, int, Register &);
    void load(int, int , Register &, Memory &);
    void load(int, int, Register &);
    void store(int,int, Register &, Memory &);
    void move(int, int, Register &);
    void jump(int, int, Register &, int &);
    void halt();
    void runNextStep(Memory *);
    void fetch(Memory *);
    vector<int> decode();
    void excute(Register &, Memory *, vector<int>);
};

class Machine
{
private:
    Memory storage;
    CPU cpu(Memory *);

public:
};
