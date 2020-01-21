#pragma once

#include <Controller/IController.hpp>

class KorytkoMagControllerNull : public IController
{
public:
   KorytkoMagControllerNull();
   virtual ~KorytkoMagControllerNull();

   void addCommands(const StringsMatrix& validatedUserInput) final override;
   bool executeCommand() final override;
   void handleCommandsResult() final override;
   std::string getFinalResultCode() final override;
};

