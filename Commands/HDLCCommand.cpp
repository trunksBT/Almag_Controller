#include "HDLCCommand.hpp"
#include <Utils/Logger.hpp>

HDLCCommand::HDLCCommand(IHDLCFrameBodyFactoryPtr frameBodyFactoryPtr,
   IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
: ICommand()
, hdlcFrameBodyFactory_{frameBodyFactoryPtr}
, hdlcCommunicator_{hdlcCommunicator}
, validatedUserInput_{userInput}
, IDX_OF_ADDRESS_{1}
{
   LOG(trace);
}

HDLCCommand::~HDLCCommand()
{
   LOG(trace);
}
