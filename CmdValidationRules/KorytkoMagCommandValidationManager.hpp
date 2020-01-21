#pragma once

#include <string>
#include <Utils/TypeAliases.hpp>
#include "ICmdValidationManager.hpp"

class KorytkoMagCommandValidationManager final : public ICmdValidationManager
{
public:
   explicit KorytkoMagCommandValidationManager(Database& db);
   virtual ~KorytkoMagCommandValidationManager() = default;
   MaybeStrings perform(const Strings& userInput) override;
};
