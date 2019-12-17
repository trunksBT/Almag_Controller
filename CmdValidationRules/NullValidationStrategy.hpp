#pragma once

#include <Controller/CmdValidationRules/ICommandValidationStrategy.hpp>
#include <Utils/TypeAliases.hpp>

class NullValidationStrategy : public ICommandValidationStrategy
{
public:
   virtual ~NullValidationStrategy() = default;

protected:
   virtual MaybeStrings validateInputCorrectness(Strings userInput) override;
   virtual MaybeStrings modifyIfRequired(Strings validatedUserInput) override;
};

