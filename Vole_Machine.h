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
    string memory[16];
    int size = 16;

public:
    string get_cell(int);
    void set_cell(int, string);
};

class Memory
{
private:
    string memory[256];
    int size = 256;

public:
    string get_cell(int);
    void set_cell(int, string);
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
    string dec_to_hexa(int);
    int get_twos_comp(int);
    int convert_to_twos_comp(int);
    bool is_valid();
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
