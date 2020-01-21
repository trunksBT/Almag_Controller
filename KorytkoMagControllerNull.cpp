#include "KorytkoMagControllerNull.hpp"

#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

KorytkoMagControllerNull::KorytkoMagControllerNull()
{
   LOG(debug);
}

KorytkoMagControllerNull::~KorytkoMagControllerNull()
{
   LOG(debug);
}

void KorytkoMagControllerNull::addCommands(const StringsMatrix& validatedUserInput)
{
   LOG(debug);
}

bool KorytkoMagControllerNull::executeCommand()
{
   LOG(debug);
   return true;
}

void KorytkoMagControllerNull::handleCommandsResult()
{
   LOG(debug);
}

std::string KorytkoMagControllerNull::getFinalResultCode()
{
   return defaultVals::FOR_STRING;
}
