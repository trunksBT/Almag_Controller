#include "LinkEstablishment.hpp"
#include <HDLC/IHDLCCommunicator.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <PluginSpecifics/CmdConstraints/KorytkoMagConstraints.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace command;
using namespace defaultVals;

LinkEstablishment::LinkEstablishment(IHDLCFrameBodyFactoryPtr frameBodyFactoryPtr,
        IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
: HDLCCommand(frameBodyFactoryPtr, hdlcCommunicator, userInput)
{
   LOG(trace);
}

void LinkEstablishment::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

HDLCFrameBodyPtr LinkEstablishment::getFrameBody() const
{
   return hdlcFrameBodyFactory_->get_FrameU_LinkEstablishment();
}

void LinkEstablishment::executeImpl()
{
   LOG(trace) << BEGIN;

   hdlcCommunicator_->communicate(validatedUserInput_[IDX_OF_ADDRESS_],
                           getFrameBody());

   LOG(trace) << MESSAGES_SEPARATOR;
   LOG(trace) << END;
}

std::string LinkEstablishment::handleResponse()
{
   return constraints::korytkomag::L2::LINK_ESTABLISHMENT + DELIMITER;
}
