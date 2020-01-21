#pragma once

#include <list>
#include <memory>
#include <vector>
#include <boost/optional.hpp>

#include <Database/Database.hpp>
#include <Controller/IController.hpp>
#include <Controller/ICommand.hpp>
#include <Controller/ICommandFactory.hpp>

#include <Utils/TypeAliases.hpp>

/*
 * This class by design accepts only validated userInput
 */

class KorytkoMagController final: public IController
{
public:
   KorytkoMagController(Database& db, ICommandFactoryPtr commandFactory);
   virtual ~KorytkoMagController();

   void addCommands(const StringsMatrix& validatedUserInput) final override;
   bool executeCommand() final override;
   void handleCommandsResult() final override;
   std::string getFinalResultCode() final override;

private:
   void addCommands(const std::vector<std::shared_ptr<ICommand>>& inCommand);
   void addCommand(const Strings& validatedUserInput);

   void executeNextCommand();

   Database& db_;
   ICommandFactoryPtr commandFactory_;
   std::list<std::shared_ptr<ICommand>> commands_;
   std::string finalResultCode_;
};
using KorytkoMagControllerPtr = std::shared_ptr<KorytkoMagController>;
