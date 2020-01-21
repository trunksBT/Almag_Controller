#include "KorytkoMagCommandValidationManager.hpp"
#include <memory>
#include <Controller/CmdValidationRules/ICommandValidationStrategy.hpp>
#include <Controller/CmdValidationRules/DummyScanValidationStrategy.hpp>
#include <Controller/CmdValidationRules/NullValidationStrategy.hpp>
#include <PluginSpecifics/CmdConstraints/KorytkoMagConstraints.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Functions.hpp>

using namespace constraints::korytkomag;

KorytkoMagCommandValidationManager::KorytkoMagCommandValidationManager(Database& db)
   : ICmdValidationManager{db} {}

MaybeStrings KorytkoMagCommandValidationManager::perform(const Strings& userInput)
{
   const auto& KORYTKOMAG_COMMAND_NAME = userInput[idx::COMMAND_OR_ACTION_NAME];
   LOG(trace) << "BEGIN " << KORYTKOMAG_COMMAND_NAME;

   std::unique_ptr<ICommandValidationStrategy> validationStrategy_;
   if (funs::anyOf({
      constraints::korytkomag::values.begin(), constraints::korytkomag::values.end()}, KORYTKOMAG_COMMAND_NAME))
   {
      validationStrategy_ = std::make_unique<DummyScanValidationStrategy>();
   }
   else if (command::START_POOLING == KORYTKOMAG_COMMAND_NAME)
   {
      validationStrategy_ = std::make_unique<NullValidationStrategy>();
   }

   if (validationStrategy_)
   {
      return validationStrategy_->execute(userInput);
   }
   else
   {
      LOG(warning) << "Unknown korytkomag command " << KORYTKOMAG_COMMAND_NAME;
      return boost::none;
   }
}
