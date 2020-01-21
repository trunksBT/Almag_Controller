#include "KorytkoMagController.hpp"

#include <Controller/ICommand.hpp>

#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace command;
using namespace defaultVals;

KorytkoMagController::KorytkoMagController(Database& db, ICommandFactoryPtr commandFactory)
    : db_(db)
    , commandFactory_(commandFactory)
    , finalResultCode_("")
{
    LOG(trace);
}

KorytkoMagController::~KorytkoMagController()
{
    LOG(trace);
}

std::string KorytkoMagController::getFinalResultCode()
{
   return finalResultCode_;
}

void KorytkoMagController::addCommand(const Strings& validatedUserInput)
{
   LOG(debug);
   std::shared_ptr<ICommand> receivedCmd{
      commandFactory_->interpretAndCreateCommand(validatedUserInput) };

   if (receivedCmd)
   {
      addCommands({receivedCmd});
   }
}

void KorytkoMagController::addCommands(const StringsMatrix& validatedUserInputs)
{
   for (const auto& validatedUserInput : validatedUserInputs)
   {
      addCommand(validatedUserInput);
   }
}

void KorytkoMagController::addCommands(const std::vector<std::shared_ptr<ICommand>>& inCommands)
{
    for (const auto& inCommand : inCommands)
    {
        inCommand->registerResponseHandler([&](){
            this->handleCommandsResult();
        });
        commands_.push_back(inCommand);
    }
}

bool KorytkoMagController::executeCommand()
{
    LOG(debug);
    if (not commands_.empty())
    {
        commands_.front()->execute();
    }
    return true;
}

void KorytkoMagController::executeNextCommand()
{
   while (not commands_.empty())
   {
      commands_.pop_front();
      LOG(debug) << "Number of commands on queue " << commands_.size();
      executeCommand();    
   }
}

void KorytkoMagController::handleCommandsResult()
{
    while (not commands_.empty())
    {
        const std::shared_ptr<ICommand> currentCommand = commands_.front();
        finalResultCode_ += currentCommand->handleResponse();
        executeNextCommand();
    }
}
