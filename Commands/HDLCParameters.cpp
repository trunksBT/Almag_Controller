#include <Controller/Commands/HDLCParameters.hpp>

#include <filesystem>

#include <HDLC/IHDLCCommunicator.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace command;

namespace
{
constexpr int IDX_OF_ADDRESS = 1;
}

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
   LOG(trace) << "BEGIN";

   hdlcCommunicator_->communicate(validatedUserInput_[IDX_OF_ADDRESS],
                           getFrameBody());

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string HDLCParameters::handleResponse()
{
   return constraints::almag::L2::HDLC_PARAMETERS + DELIMITER;
}
