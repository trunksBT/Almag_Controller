#include <Controller/CmdValidationRules/ICommandValidationStrategy.hpp>

MaybeStrings ICommandValidationStrategy::execute(Strings userInput)
{
   if (auto successfulyValidatedInput = validateInputCorrectness(userInput))
   {
      return modifyIfRequired(*successfulyValidatedInput);
   }
   return boost::none;
}

