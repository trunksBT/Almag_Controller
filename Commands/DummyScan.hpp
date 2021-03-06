#pragma once

#include <Controller/Commands/HDLCCommand.hpp>

class DummyScan : public HDLCCommand
{
public:
   DummyScan(IHDLCFrameBodyFactoryPtr frameBodyFactoryPtr,
           IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput, uint8_t numberOfExecutions);
   virtual ~DummyScan() = default;

   void execute() override;
   std::string handleResponse() override;
   HDLCFrameBodyPtr getFrameBody() const override;

protected:
   void executeImpl();

private:
   std::string responseMessage_;
   uint8_t numberOfExecutions_;
};

