#include <Controller/Commands/DeviceScan.hpp>

#include <filesystem>

#include <HDLC/IHDLCCommunicator.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace command;

DeviceScan::DeviceScan(IHDLCFrameBodyFactoryPtr frameBodyFactoryPtr,
        IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
: HDLCCommand(frameBodyFactoryPtr, hdlcCommunicator, userInput)
{
   LOG(trace);
}

void DeviceScan::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

HDLCFrameBodyPtr DeviceScan::getFrameBody() const
{
   return hdlcFrameBodyFactory_->get_FrameXID_DeviceScan();
}

void DeviceScan::executeImpl()
{
   LOG(trace) << "BEGIN";

   hdlcCommunicator_->communicate(validatedUserInput_[IDX_OF_ADDRESS_],
                           getFrameBody());

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string DeviceScan::handleResponse()
{
   return constraints::almag::L2::DEVICE_SCAN + DELIMITER;
}

