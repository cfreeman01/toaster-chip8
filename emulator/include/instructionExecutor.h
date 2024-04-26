#pragma once
#include <cstdint>
#include <map>
#include "chipInstruction.h"
#include "emulatorState.h"

class InstructionExecutor
{
    public:
        static void execute(uint16_t opcode, EmulatorState & state);

    private:
        typedef void (*InsPtr)();

        static std::map<CHIPInstruction, InsPtr> instructionMap;

        static uint16_t args[3];

        static EmulatorState *state;

        static void ex_00E0();
        static void ex_00EE();
        static void ex_1NNN();
        static void ex_2NNN();
        static void ex_3XNN();
        static void ex_4XNN();
        static void ex_5XY0();
        static void ex_6XNN();
        static void ex_7XNN();
        static void ex_8XY0();
        static void ex_8XY1();
        static void ex_8XY2();
        static void ex_8XY3();
        static void ex_8XY4();
        static void ex_8XY5();
        static void ex_8XY6();
        static void ex_8XY7();
        static void ex_8XYE();
        static void ex_9XY0();
        static void ex_ANNN();
        static void ex_BNNN();
        static void ex_CXNN();
        static void ex_DXYN();
        static void ex_EX9E();
        static void ex_EXA1();
        static void ex_FX07();
        static void ex_FX0A();
        static void ex_FX15();
        static void ex_FX18();
        static void ex_FX1E();
        static void ex_FX29();
        static void ex_FX33();
        static void ex_FX55();
        static void ex_FX65();
};