#include <Controller/Commands/HDLCParameters.hpp>

#include <HDLC/IHDLCCommunicator.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <PluginSpecifics/CmdConstraints/KorytkoMagConstraints.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace command;
using namespace defaultVals;

HDLCParameters::HDLCParameters(IHDLCFrameBodyFactoryPtr frameBodyFactoryPtr,
   IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
: HDLCCommand(frameBodyFactoryPtr, hdlcCommunicator, userInput)
{
   LOG(trace);
}

void HDLCParameters::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

HDLCFrameBodyPtr HDLCParameters::getFrameBody() const
{
   return hdlcFrameBodyFactory_->get_FrameXID_HDLCParameters();
}

void HDLCParameters::executeImpl()
{
   LOG(trace) << BEGIN;

   hdlcCommunicator_->communicate(validatedUserInput_[IDX_OF_ADDRESS_],
                           getFrameBody());

   LOG(trace) << MESSAGES_SEPARATOR;
   LOG(trace) << END;
}

std::string HDLCParameters::handleResponse()
{
   return constraints::korytkomag::L2::HDLC_PARAMETERS + DELIMITER;
}
