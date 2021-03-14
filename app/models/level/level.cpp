#include "level.h"

TLevel::TLevel(const std::string text, const std::vector<TOption> options, const std::vector<std::shared_ptr<TAction>>& actions)
	: Text(text)
	, Options(options)
	, Actions(actions) {}

const std::string& TLevel::GetText() const {
	return Text;
}

const std::vector<TOption>& TLevel::GetOptions() {
	return Options;
}

const std::vector<std::shared_ptr<TAction>>& TLevel::GetActions() {
	return Actions;
}