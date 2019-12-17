#pragma once

#include <Controller/Commands/HDLCCommand.hpp>

class IHDLCCommunicator;

class AISGProtocolVersion : public HDLCCommand
{
public:
   AISGProtocolVersion(IHDLCFrameBodyFactoryPtr frameBodyFactoryPtr,
           IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput);
   virtual ~AISGProtocolVersion() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;
   HDLCFrameBodyPtr getFrameBody() const override;

protected:
   void executeImpl();
};

