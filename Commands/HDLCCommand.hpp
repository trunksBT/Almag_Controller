#pragma once

#include <Controller/ICommand.hpp>
#include <Controller/IHDLCFrameBodyFactory.hpp>
#include <HDLC/IHDLCCommunicator.hpp>

class HDLCCommand : public ICommand
{
public:
   HDLCCommand(IHDLCFrameBodyFactoryPtr frameBodyFactoryPtr,
      IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput);
   virtual ~HDLCCommand();
   virtual void execute() = 0;
   virtual std::string handleResponse() = 0;
   virtual HDLCFrameBodyPtr getFrameBody() const = 0;

protected:
   IHDLCFrameBodyFactoryPtr hdlcFrameBodyFactory_;
   IHDLCCommunicatorPtr hdlcCommunicator_;
   Strings validatedUserInput_;
};

using HDLCCommandPtr = std::shared_ptr<HDLCCommand>;
