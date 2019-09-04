set_global_assignment -entity "Qsys" -library "lib_Qsys" -name IP_TOOL_NAME "Qsys"
set_global_assignment -entity "Qsys" -library "lib_Qsys" -name IP_TOOL_VERSION "18.1"
set_global_assignment -entity "Qsys" -library "lib_Qsys" -name IP_TOOL_ENV "Qsys"
set_global_assignment -library "lib_Qsys" -name SPD_FILE [file join $::quartus(sip_path) "../Qsys.spd"]
set_global_assignment -library "lib_Qsys" -name MISC_FILE [file join $::quartus(sip_path) "../../Qsys.qsys"]

set_global_assignment -library "lib_Qsys" -name MISC_FILE [file join $::quartus(sip_path) "Qsys.v"]
set_global_assignment -library "lib_Qsys" -name MISC_FILE [file join $::quartus(sip_path) "submodules/Qsys_LED.v"]
