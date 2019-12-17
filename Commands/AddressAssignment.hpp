#pragma once

#include <Controller/Commands/HDLCCommand.hpp>

class AddressAssignment : public HDLCCommand
{
public:
   AddressAssignment(IHDLCFrameBodyFactoryPtr frameBodyFactoryPtr,
      IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput);
   virtual ~AddressAssignment() = default;

   virtual void execute() override;
   virtual std::string handleResponse() override;
   HDLCFrameBodyPtr getFrameBody() const override;

protected:
   void executeImpl();
};
