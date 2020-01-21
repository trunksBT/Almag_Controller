#include "ThreeGPPReleaseID.hpp"
#include <HDLC/IHDLCCommunicator.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <PluginSpecifics/CmdConstraints/KorytkoMagConstraints.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace command;
using namespace defaultVals;

ThreeGPPReleaseID::ThreeGPPReleaseID(IHDLCFrameBodyFactoryPtr frameBodyFactoryPtr,
        IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
: HDLCCommand(frameBodyFactoryPtr, hdlcCommunicator, userInput)
{
   LOG(trace);
}

void ThreeGPPReleaseID::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

HDLCFrameBodyPtr ThreeGPPReleaseID::getFrameBody() const
{
   return hdlcFrameBodyFactory_->get_FrameXID_3GPPReleaseId();
}

void ThreeGPPReleaseID::executeImpl()
{
   LOG(trace) << BEGIN;

   hdlcCommunicator_->communicate(validatedUserInput_[IDX_OF_ADDRESS_],
                           getFrameBody());

   LOG(trace) << MESSAGES_SEPARATOR;
   LOG(trace) << END;
}

std::string ThreeGPPReleaseID::handleResponse()
{
   return constraints::korytkomag::L2::THREEGPP_RELEASE_ID + DELIMITER;
}
