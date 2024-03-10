#include <cstdint>

#define NUM_REGS 16

enum class Register 
{
    V0 = 0,
    V1,
    V2,
    V3,
    V4,
    V5,
    V6,
    V7,
    V8,
    V9,
    VA,
    VB,
    VC,
    VD,
    VE,
    VF
};

class RegisterFile
{
    public:
    uint8_t readReg(Register reg);
    void    writeReg(Register reg, uint8_t val);

    private:
    uint8_t registers[NUM_REGS] = {0};
};