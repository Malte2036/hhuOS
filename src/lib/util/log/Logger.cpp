//
// Created by Malte Sehmer on 05.12.22.
//

#include "Logger.h"
#include "lib/util/stream/PrintWriter.h"
#include "lib/util/stream/FileOutputStream.h"
#include "lib/util/graphic/Ansi.h"

void Logger::logMessage(const Util::Memory::String &message) {
    auto stream = Util::Stream::FileOutputStream("/device/com1");
    auto writer = Util::Stream::PrintWriter(stream);

    const auto logMessage = Util::Memory::String::format("%s[UserSpace]%s %s\n",
                                                         Util::Graphic::Ansi::FOREGROUND_MAGENTA,
                                                         Util::Graphic::Ansi::FOREGROUND_DEFAULT,
                                                         message.operator char *());

    writer << logMessage << Util::Stream::PrintWriter::flush << Util::Stream::PrintWriter::flush;
}
