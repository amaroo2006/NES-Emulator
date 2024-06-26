#include "bus.h"
#include <stdint.h>

#ifndef MAPPER_H
#define MAPPER_H
// mapper interface
typedef struct MapperInterface {

    // number
    uint16_t mapper_number;

    // rom buffer
    uint8_t *buffer;

    // write status
    bool allow_cpu_writes;

    // initialize address space
    void (*initialize) (struct MapperInterface *mapper, Bus *bus);

    // dynamic bank switching
    void (*switch_prg_banks) (struct MapperInterface *mapper, Bus *bus, uint16_t current_address, uint8_t prg_bank);
    void (*switch_chr_banks) (struct MapperInterface *mapper, Bus *bus, uint16_t current_address, uint8_t chr_bank);
    

} MapperInterface;
#endif

MapperInterface *InitMapper();