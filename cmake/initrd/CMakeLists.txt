# Copyright (C) 2018-2022 Heinrich-Heine-Universitaet Duesseldorf,
# Institute of Computer Science, Department Operating Systems
# Burak Akguel, Christian Gesse, Fabian Ruhland, Filip Krakowski, Michael Schoettner
#
#
# This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
# License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any
# later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>

cmake_minimum_required(VERSION 3.14)

project(initrd)
message(STATUS "Project " ${PROJECT_NAME})

if ($ENV{HHUOS_MINIMAL_INITRD})
    add_custom_command(OUTPUT "${CMAKE_BINARY_DIR}/hhuOS.initrd"
            COMMAND /bin/mkdir -p "${HHUOS_ROOT_DIR}/initrd/bin"
            COMMAND /bin/cp "$<TARGET_FILE:shell>" "${HHUOS_ROOT_DIR}/initrd/bin/shell"
            COMMAND /bin/tar -C "${HHUOS_ROOT_DIR}/initrd/" --xform s:'./':: -cf "${CMAKE_BINARY_DIR}/hhuOS.initrd" ./
            COMMAND /bin/rm -f "${HHUOS_ROOT_DIR}/hhuOS.img" "${HHUOS_ROOT_DIR}/hhuOS.iso"
            DEPENDS shell)

    add_custom_target(${PROJECT_NAME} DEPENDS shell "${CMAKE_BINARY_DIR}/hhuOS.initrd")
else()
    add_custom_command(OUTPUT "${CMAKE_BINARY_DIR}/hhuOS.initrd"
            COMMAND /bin/mkdir -p "${HHUOS_ROOT_DIR}/initrd/bin"
            COMMAND /bin/cp "$<TARGET_FILE:shell>" "${HHUOS_ROOT_DIR}/initrd/bin/shell"
            COMMAND /bin/cp "$<TARGET_FILE:ant>" "${HHUOS_ROOT_DIR}/initrd/bin/ant"
            COMMAND /bin/cp "$<TARGET_FILE:asciimate>" "${HHUOS_ROOT_DIR}/initrd/bin/asciimate"
            COMMAND /bin/cp "$<TARGET_FILE:beep>" "${HHUOS_ROOT_DIR}/initrd/bin/beep"
            COMMAND /bin/cp "$<TARGET_FILE:cat>" "${HHUOS_ROOT_DIR}/initrd/bin/cat"
            COMMAND /bin/cp "$<TARGET_FILE:color>" "${HHUOS_ROOT_DIR}/initrd/bin/color"
            COMMAND /bin/cp "$<TARGET_FILE:cp>" "${HHUOS_ROOT_DIR}/initrd/bin/cp"
            COMMAND /bin/cp "$<TARGET_FILE:cube>" "${HHUOS_ROOT_DIR}/initrd/bin/cube"
            COMMAND /bin/cp "$<TARGET_FILE:date>" "${HHUOS_ROOT_DIR}/initrd/bin/date"
            COMMAND /bin/cp "$<TARGET_FILE:echo>" "${HHUOS_ROOT_DIR}/initrd/bin/echo"
            COMMAND /bin/cp "$<TARGET_FILE:fault>" "${HHUOS_ROOT_DIR}/initrd/bin/fault"
            COMMAND /bin/cp "$<TARGET_FILE:head>" "${HHUOS_ROOT_DIR}/initrd/bin/head"
            COMMAND /bin/cp "$<TARGET_FILE:hello>" "${HHUOS_ROOT_DIR}/initrd/bin/hello"
            COMMAND /bin/cp "$<TARGET_FILE:test>" "${HHUOS_ROOT_DIR}/initrd/bin/test"
            COMMAND /bin/cp "$<TARGET_FILE:hexdump>" "${HHUOS_ROOT_DIR}/initrd/bin/hexdump"
            COMMAND /bin/cp "$<TARGET_FILE:kill>" "${HHUOS_ROOT_DIR}/initrd/bin/kill"
            COMMAND /bin/cp "$<TARGET_FILE:ls>" "${HHUOS_ROOT_DIR}/initrd/bin/ls"
            COMMAND /bin/cp "$<TARGET_FILE:lvgl_demo>" "${HHUOS_ROOT_DIR}/initrd/bin/lvgl"
            COMMAND /bin/cp "$<TARGET_FILE:platformer>" "${HHUOS_ROOT_DIR}/initrd/bin/platformer"
            COMMAND /bin/cp "$<TARGET_FILE:membench>" "${HHUOS_ROOT_DIR}/initrd/bin/membench"
            COMMAND /bin/cp "$<TARGET_FILE:mkdir>" "${HHUOS_ROOT_DIR}/initrd/bin/mkdir"
            COMMAND /bin/cp "$<TARGET_FILE:mount>" "${HHUOS_ROOT_DIR}/initrd/bin/mount"
            COMMAND /bin/cp "$<TARGET_FILE:mouse>" "${HHUOS_ROOT_DIR}/initrd/bin/mouse"
            COMMAND /bin/cp "$<TARGET_FILE:ping>" "${HHUOS_ROOT_DIR}/initrd/bin/ping"
            COMMAND /bin/cp "$<TARGET_FILE:polygon>" "${HHUOS_ROOT_DIR}/initrd/bin/polygon"
            COMMAND /bin/cp "$<TARGET_FILE:ps>" "${HHUOS_ROOT_DIR}/initrd/bin/ps"
            COMMAND /bin/cp "$<TARGET_FILE:pwd>" "${HHUOS_ROOT_DIR}/initrd/bin/pwd"
            COMMAND /bin/cp "$<TARGET_FILE:rm>" "${HHUOS_ROOT_DIR}/initrd/bin/rm"
            COMMAND /bin/cp "$<TARGET_FILE:rmdir>" "${HHUOS_ROOT_DIR}/initrd/bin/rmdir"
            COMMAND /bin/cp "$<TARGET_FILE:shutdown>" "${HHUOS_ROOT_DIR}/initrd/bin/shutdown"
            COMMAND /bin/cp "$<TARGET_FILE:snake>" "${HHUOS_ROOT_DIR}/initrd/bin/snake"
            COMMAND /bin/cp "$<TARGET_FILE:touch>" "${HHUOS_ROOT_DIR}/initrd/bin/touch"
            COMMAND /bin/cp "$<TARGET_FILE:tree>" "${HHUOS_ROOT_DIR}/initrd/bin/tree"
            COMMAND /bin/cp "$<TARGET_FILE:udp_echo>" "${HHUOS_ROOT_DIR}/initrd/bin/udp_echo"
            COMMAND /bin/cp "$<TARGET_FILE:unmount>" "${HHUOS_ROOT_DIR}/initrd/bin/unmount"
            COMMAND /bin/cp "$<TARGET_FILE:uptime>" "${HHUOS_ROOT_DIR}/initrd/bin/uptime"
            COMMAND /bin/cp -r "${CMAKE_BINARY_DIR}/beep" "${HHUOS_ROOT_DIR}/initrd"
            COMMAND /bin/cp -r "${CMAKE_BINARY_DIR}/asciimation" "${HHUOS_ROOT_DIR}/initrd"
            COMMAND /bin/tar -C "${HHUOS_ROOT_DIR}/initrd/" --xform s:'./':: -cf "${CMAKE_BINARY_DIR}/hhuOS.initrd" ./
            COMMAND /bin/rm -f "${HHUOS_ROOT_DIR}/hhuOS.img" "${HHUOS_ROOT_DIR}/hhuOS.iso"
            DEPENDS asciimation music shell ant beep cat color cp cube date echo fault hello test kill ls lvgl_demo platformer membench mkdir mount mouse polygon ps pwd rm rmdir shutdown snake touch tree unmount uptime)
            
    add_custom_target(${PROJECT_NAME} DEPENDS music asciimation shell ant beep cat color cp cube date echo fault hello test kill ls lvgl_demo platformer membench mkdir mount mouse polygon ps pwd rm rmdir shutdown snake touch tree unmount uptime music "${CMAKE_BINARY_DIR}/hhuOS.initrd")
         
   endif()