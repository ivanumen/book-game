#pragma once

#include "app/controllers/actions/action.h"
#include "app/controllers/option/option_control.h"


#include <string>
#include <vector>
#include <memory>

class TLevel
{
private:
	std::string Text;
	std::vector<TOption> Options;
	std::vector<std::shared_ptr<TAction>> Actions;
public:
	TLevel() = default;
	TLevel(const std::string text, const std::vector<TOption> options, const std::vector<std::shared_ptr<TAction>>& actions);
	const std::string& GetText() const;
	const std::vector<TOption>& GetOptions() const ;
	const std::vector<std::shared_ptr<TAction>>& GetActions() const;
};

