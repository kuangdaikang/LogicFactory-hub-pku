# architectyre layer synthesis (RTL-level synthesis)
add_subdirectory(layer_arch)

# logic layer synthesis (logic optimization)
add_subdirectory(layer_logic)

# netlist layer synthesis (technology mapping)
add_subdirectory(layer_netlist)

# physical layer synthesis (physical design)
add_subdirectory(layer_phys)

# formal layer synthesis (formal verification)
add_subdirectory(layer_formal)

# utility
add_subdirectory(utility)