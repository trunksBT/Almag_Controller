#pragma once

#include <Controller/Commands/HDLCCommand.hpp>

class HDLCParameters : public HDLCCommand
{
public:
   HDLCParameters(IHDLCFrameBodyFactoryPtr frameBodyFactoryPtr,
           IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput);
   virtual ~HDLCParameters() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;
   HDLCFrameBodyPtr getFrameBody() const override;

protected:
   void executeImpl();
};
