#include "HDLCCommand.hpp"
#include <Utils/Logger.hpp>

HDLCCommand::HDLCCommand(IHDLCFrameBodyFactoryPtr frameBodyFactoryPtr,
   IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
: ICommand()
, hdlcFrameBodyFactory_(frameBodyFactoryPtr)
, hdlcCommunicator_(hdlcCommunicator)
, validatedUserInput_(userInput)
{
   LOG(trace);
}

HDLCCommand::~HDLCCommand()
{
   LOG(trace);
}
