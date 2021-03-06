#include <Controller/Commands/Calibrate.hpp>
#include <HDLC/IHDLCCommunicator.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <PluginSpecifics/CmdConstraints/KorytkoMagConstraints.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace command;
using namespace defaultVals;

Calibrate::Calibrate(IHDLCFrameBodyFactoryPtr frameBodyFactoryPtr,
        IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
   : HDLCCommand(frameBodyFactoryPtr, hdlcCommunicator, userInput)
{
   LOG(trace);
}

void Calibrate::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

HDLCFrameBodyPtr Calibrate::getFrameBody() const
{
   return hdlcFrameBodyFactory_->get_FrameI_Calibrate();
}

void Calibrate::executeImpl()
{
   LOG(trace) << BEGIN;
   const auto address = validatedUserInput_[IDX_OF_ADDRESS_];
   LOG(debug) << address;

   hdlcCommunicator_->communicate(address, getFrameBody());

   LOG(trace) << MESSAGES_SEPARATOR;
   LOG(trace) << END;
}

std::string Calibrate::handleResponse()
{
   return constraints::korytkomag::L7::CALIBRATE + DELIMITER;
}
