#include <Controller/Commands/Calibrate.hpp>
#include <HDLC/IHDLCCommunicator.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

#include <thread>

using namespace command;

namespace
{
constexpr int IDX_OF_ADDRESS = 1;
}

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
   LOG(trace) << "BEGIN";
   const auto address = validatedUserInput_[IDX_OF_ADDRESS];
   LOG(debug) << address;

   std::this_thread::sleep_for(std::chrono::seconds(1));

   hdlcCommunicator_->send(address, getFrameBody());

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string Calibrate::handleResponse()
{
   return constraints::almag::L7::CALIBRATE + DELIMITER;
}

