#pragma once

#include <Controller/Commands/HDLCCommand.hpp>

class Calibrate : public HDLCCommand
{
public:
   Calibrate(IHDLCFrameBodyFactoryPtr frameBodyFactoryPtr,
           IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput);
   virtual ~Calibrate() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;
   HDLCFrameBodyPtr getFrameBody() const override;

protected:
   void executeImpl();
};

