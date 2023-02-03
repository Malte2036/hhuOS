//
// Created by Malte Sehmer on 09.01.23.
//
#include "GameManager.h"
#include "lib/util/stream/FileReader.h"
#include "lib/util/stream/BufferedReader.h"
#include "lib/util/stream/FileOutputStream.h"
#include "lib/util/stream/PrintWriter.h"
#include "lib/util/system/System.h"
#include "lib/util/async/Thread.h"
#include "lib/util/file/File.h"
#include "lib/util/graphic/Ansi.h"

namespace Util::Game {
    void GameManager::playSound(const Memory::String &soundFileName) {
        Util::Async::Thread::createThread("SoundRunnable", new SoundRunnable(soundFileName));
    }

    Vector2 GameManager::getResolution() {
        return *resolution;
    }

    void GameManager::setResolution(Vector2 *vector2) {
        delete resolution;
        resolution = vector2;
    }

    double GameManager::getTransformation() {
        return transformation;
    }

    void GameManager::setTransformation(int value) {
        transformation = value;
    }

    void SoundRunnable::run() {
        auto beepFile = Util::File::File(soundFileName);
        if (!beepFile.exists() || beepFile.isDirectory()) {
            Util::System::error << "beep: '" << soundFileName << "' could not be opened!"
                                << Util::Stream::PrintWriter::endl << Util::Stream::PrintWriter::flush;
            Exception::throwException(Exception::INVALID_ARGUMENT, "soundfile could not be opened!");
        }

        auto speakerFile = Util::File::File("/device/speaker");
        auto fileReader = Util::Stream::FileReader(beepFile);
        auto reader = Util::Stream::BufferedReader(fileReader);
        auto outputStream = Util::Stream::FileOutputStream(speakerFile);
        auto writer = Util::Stream::PrintWriter(outputStream);
        auto line = reader.readLine();
        while (!line.isEmpty()) {
            auto split = line.split(",");
            auto length = Util::Memory::String::parseInt(split[1]);

            writer << split[0] << Util::Stream::PrintWriter::flush;

            Util::Async::Thread::sleep(Util::Time::Timestamp::ofMilliseconds(length));
            Util::Graphic::Ansi::clearLineToCursor();
            Util::Graphic::Ansi::moveCursorToBeginningOfPreviousLine(0);
            line = reader.readLine();
        }
    }

    SoundRunnable::SoundRunnable(const Memory::String &soundFileName) : soundFileName{soundFileName} {

    }
}
