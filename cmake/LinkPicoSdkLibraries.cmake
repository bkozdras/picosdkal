#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

function(link_pico_sdk_libraries projectName)
    target_link_libraries(${projectName}
        pico_stdlib
        hardware_gpio
        hardware_irq)
endfunction(link_pico_sdk_libraries)
