#include "ICommand.hpp"

#include <HDLC/IHDLCCommunicator.hpp>

ICommand::ICommand()
{
   LOG(trace);
}

ICommand::~ICommand()
{
   LOG(trace);
}

void ICommand::registerResponseHandler(std::function<void(void)> responseHandler)
{
    informControllerAboutResult_.connect(responseHandler);
}
