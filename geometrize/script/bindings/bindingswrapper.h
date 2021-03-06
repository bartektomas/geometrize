#pragma once

#include <string>
#include <vector>

#include <QImage>

#include "geometrize/shaperesult.h"

#include "common/util.h"

class QObject;

namespace geometrize
{

namespace script
{

namespace bindings
{

std::string getApplicationDirectoryPath();

void printToConsole(const std::string& str);

void messageBox(const std::string& str);

void debugBreak();

void processApplicationEvents();

bool fileExists(const std::string& filePath);

bool directoryExists(const std::string& dirPath);

bool directoryContainsFile(const std::string& dirPath, const std::string& fileName);

std::string readFileAsString(const std::string& filePath);

std::vector<std::string> getFilePathsForDirectory(const std::string& dirPath);

std::vector<std::string> getScriptSearchPaths();

std::vector<std::string> getTemplateSearchPaths();

std::string getFirstFileWithExtension(const std::string& dirPath, const std::string& extension);

std::string getFirstFileWithExtensions(const std::string& dirPath, const std::vector<std::string>& extensions);

std::vector<std::string> getFilesWithExtension(const std::string& dirPath, const std::string& extension);

std::vector<std::string> getFilesWithExtensions(const std::string& dirPath, const std::vector<std::string>& extensions);

std::vector<std::string> getSupportedImageFileExtensions();

std::vector<std::string> getScriptsForPath(const std::string& dirPath);

void openTask(const std::string& url, bool addToRecents);

bool openInDefaultApplication(const std::string& path);

bool revealInDefaultApplication(const std::string& path);

void clearGlobalClipboard();

std::string getGlobalClipboardText();

void setGlobalClipboardText(const std::string& text);

bool stringBeginsWith(const std::string& str, const std::string& prefix);

bool stringEndsWith(const std::string& str, const std::string& suffix);

std::string getApplicationDirectoryLocation();

std::string getAppDataLocation();

std::string getHomeDirectoryLocation();

bool writeStringToFile(const std::string& str, const std::string& path);

std::string percentEncode(const std::string& str);

template<typename T, typename U, typename V>
T randomInRange(U lower, V upper)
{
    return static_cast<T>(geometrize::util::randomInRange(static_cast<int>(lower), static_cast<int>(upper)));
}

int randomIntInRange(int lower, int upper);

float randomFloatInRange(float lower, float upper);

template<typename T> T randomInVector(const std::vector<T>& v)
{
    assert(!v.empty());
    return v[randomInRange<int, std::size_t, std::size_t>(0, v.size() - 1)];
}

template<typename T, typename U, typename V>
T clamp(T value, U lower, V upper)
{
    assert(lower <= upper);
    if (value < lower) {
        value = lower;
    }
    if (value > upper) {
        value = upper;
    }
    return value;
}

int clampInt(int value, int lower, int upper);

float clampFloat(float value, float lower, float upper);

template<typename T>
bool vectorContains(const std::vector<T>& v, const T& t)
{
    return (std::find(v.begin(), v.end(), t) != v.end());
}

std::vector<std::string> split(const std::string& s, const char delimiter);

std::string getOperatingSystemProductType();

int getCursorX();

int getCursorY();

void setCursorPos(int x, int y);

void setTranslatorsForLocale(const std::string& locale);

bool exportGIF(const std::vector<geometrize::ShapeResult>& data,
        std::uint32_t inputWidth,
        std::uint32_t inputHeight,
        std::uint32_t outputWidth,
        std::uint32_t outputHeight,
        std::size_t frameSkip,
        const std::string& filePath);

bool saveDesktopScreenshot(const std::string& path);

bool saveWidgetScreenshot(const std::string& path, QObject* widget);

}

}

}
