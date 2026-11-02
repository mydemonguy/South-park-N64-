#include "ovl_patches.hpp"
#include "../../RecompiledFuncs/recomp_overlays.inl"

#include "librecomp/overlays.hpp"

void goemon64::register_overlays() {
    recomp::overlays::overlay_section_table_data_t sections {
        .code_sections = section_table,
        .num_code_sections = ARRLEN(section_table),
        .total_num_sections = num_sections,
    };

    recomp::overlays::overlays_by_index_t overlays {
        .table = overlay_sections_by_index,
        .len = ARRLEN(overlay_sections_by_index),
    };

    recomp::overlays::register_overlays(sections, overlays);
}

// South Park runs its code through TLB mappings: the main code at 0x00200000 + phys and
// a second block at 0x00400000. When the game DMAs that code from ROM, the runtime only
// learns the physical (KSEG0) destination, but every function pointer and jump in the
// game uses the mapped address. Register each mapped section at its linked address so
// indirect calls (LOOKUP_FUNC) resolve. Call after the runtime has initialized overlays.
void goemon64::register_tlb_code_aliases() {
    for (size_t i = 0; i < ARRLEN(section_table); i++) {
        const SectionTableEntry& section = section_table[i];
        if (section.ram_addr >= 0x80000000u) {
            continue;
        }
        for (size_t f = 0; f < section.num_funcs; f++) {
            recomp::overlays::add_loaded_function((int32_t)(section.ram_addr + section.funcs[f].offset), section.funcs[f].func);
        }
    }
}
