#pragma once

#include <array>
#include <cstdint>

// https://gbdev.io/pandocs/Memory_Map.html
class Memory {
public:
    Memory();

    uint8_t at(uint16_t addr) const; // TODO throw exception when parameter attempts to access invalid memory
    void set(uint16_t addr, uint8 val);

private:
    std::array<uint8_t, 0x4000> m_cartridge_bank1; // 0x0000 - 0x3fff
    std::array<uint8_t, 0x4000> m_cartridge_bank2; // 0x4000 - 0x7fff
    std::array<uint8_t, 0x2000> m_vram;            // 0x8000 - 0x9fff
    std::array<uint8_t, 0x2000> m_external_ram;    // 0xa000 - 0xbfff
    std::array<uint8_t, 0x1000> m_wram1;           // 0xc000 - 0xcfff
    std::array<uint8_t, 0x1000> m_wram2;           // 0xd000 - 0xdfff
    std::array<uint8_t, 0xa0> m_oam;               // 0xfe00 - 0xfe9f
    std::array<uint8_t, 0x80> m_io_registers;      // 0xff00 - 0xff7f TODO
    std::array<uint8_t, 0x7f> m_hram;              // 0xff80 - 0xfffe
    uint8_t m_ie;                                  // 0xffff
};
