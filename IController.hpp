#pragma once

#include <memory>
#include <Utils/TypeAliases.hpp>

class IController
{
public:
   virtual ~IController() = default;

   virtual void addCommands(const StringsMatrix& validatedUserInput) = 0;
   virtual bool executeCommand() = 0;
   virtual void handleCommandsResult() = 0;
   virtual std::string getFinalResultCode() = 0;
};

using IKorytkoMagControllerPtr = std::shared_ptr<IController>;
