#include "HDLCCommand.hpp"
#include <Utils/Logger.hpp>

namespace
{
constexpr unsigned IDX_OF_ADDRESS=1;
}

HDLCCommand::HDLCCommand(IHDLCFrameBodyFactoryPtr frameBodyFactoryPtr,
   IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
: hdlcFrameBodyFactory_(frameBodyFactoryPtr)
, hdlcCommunicator_(hdlcCommunicator)
, validatedUserInput_(userInput)
{
   LOG(trace);
}

HDLCCommand::~HDLCCommand()
{
   LOG(trace);
}
