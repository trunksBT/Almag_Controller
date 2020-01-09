#pragma once

#include <Controller/IController.hpp>

class AlmagControllerNull : public IController
{
public:
   AlmagControllerNull();
   virtual ~AlmagControllerNull();

   void addCommands(const StringsMatrix& validatedUserInput) final override;
   bool executeCommand() final override;
   void handleCommandsResult() final override;
   std::string getFinalResultCode() final override;
};

