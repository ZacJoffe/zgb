#include "memory.h"

#include <exception>

Memory::Memory();

uint8_t Memory::at(uint16_t addr) const {
    if (addr <= 0x3fff) { return m_cartridge_bank1[addr]; }
    if (addr <= 0x7fff) { return m_cartridge_bank2[addr - 0x4000]; }
    if (addr <= 0x9fff) { return m_vram[addr - 0x8000]; }
    if (addr <= 0xbfff) { return m_external_ram[addr - 0xa000]; }
    if (addr <= 0xcfff) { return m_wram1[addr - 0xc000]; }
    if (addr <= 0xdfff) { return m_wram2[addr - 0xd000]; }
    // TODO this region is supposedly prohibited, but it mirrors wram1/2. let's
    // see if any games use this memory region and adjust the code accordingly
    if (addr <= 0xfdff) { throw std::runtime_error("Invalid memory access. Address: " + addr); }
    if (addr <= 0xfe9f) { return m_oam[addr - 0xfe00]; }
    if (addr <= 0xfeff) { throw std::runtime_error("Invalid memory access. Address: " + addr); }
    if (addr <= 0xff7f) { return m_io_registers[addr - 0xff00]; }
    if (addr <= 0xfffe) { return m_hram[addr - 0xff80]; }

    return m_ie;
}

void Memory::set(uint16_t addr, uint8 val) {
    // TODO
}
