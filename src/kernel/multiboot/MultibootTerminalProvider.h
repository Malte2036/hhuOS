/*
 * Copyright (C) 2018-2021 Heinrich-Heine-Universitaet Duesseldorf,
 * Institute of Computer Science, Department Operating Systems
 * Burak Akguel, Christian Gesse, Fabian Ruhland, Filip Krakowski, Michael Schoettner
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#ifndef HHUOS_MULTIBOOTTERMINALPROVIDER_H
#define HHUOS_MULTIBOOTTERMINALPROVIDER_H

#include <device/graphic/TerminalProvider.h>
#include "Constants.h"

namespace Kernel::Multiboot {

class MultibootTerminalProvider : public Device::Graphic::TerminalProvider {

public:
    /**
     * Default Constructor.
     */
    MultibootTerminalProvider();

    /**
     * Copy constructor.
     */
    MultibootTerminalProvider(const MultibootTerminalProvider &other) = delete;

    /**
     * Assignment operator.
     */
    MultibootTerminalProvider &operator=(const MultibootTerminalProvider &other) = delete;

    /**
     * Destructor.
     */
    ~MultibootTerminalProvider() override = default;

    /**
     * Check if the framebuffer, provided by the bootloader, has the correct type and this driver can be used.
     *
     * @return true, if this driver can be used
     */
    [[nodiscard]] static bool isAvailable();

    /**
 * Overriding function from TerminalProvider.
 */
    Util::Graphic::Terminal &initializeTerminal(ModeInfo &modeInfo) override;

    /**
     * Overriding function from TerminalProvider.
     */
    void destroyTerminal(Util::Graphic::Terminal &terminal) override;

    /**
     * Overriding function from TerminalProvider.
     */
    [[nodiscard]] Util::Data::Array<ModeInfo> getAvailableModes() const override;

    /**
     * Overriding function from TerminalProvider.
     */
    [[nodiscard]] Util::Memory::String getClassName() override;

private:

    FrameBufferInfo frameBufferInfo;
    Util::Data::Array<ModeInfo> supportedModes;
    static const constexpr char *CLASS_NAME = "Kernel::Multiboot::MultibootTerminalProvider";
};

}

#endif