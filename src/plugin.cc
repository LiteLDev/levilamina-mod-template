#include <plugin.h>

#include <iostream>
#include <string_view>

Plugin::Plugin(std::string_view plugin_name)
    : logger_(plugin_name), plugin_name_(plugin_name) {}

Plugin::~Plugin() = default;

ll::Logger const &Plugin::GetLogger() const { return this->logger_; }

std::string_view Plugin::GetName() const { return this->plugin_name_; }

bool Plugin::Load(ll::plugin::Plugin &self) {
  this->logger_.info("Test");
  this->logger_.info("{} loaded!", this->plugin_name_);
  return true;
}

bool Plugin::Unload(ll::plugin::Plugin &self) {
  this->logger_.info("{} unloaded!", this->plugin_name_);
  return true;
}

bool Plugin::Enable(ll::plugin::Plugin &self) {
  this->logger_.info("{} enabled!", this->plugin_name_);
  return true;
}

bool Plugin::Disable(ll::plugin::Plugin &self) {
  this->logger_.info("{} disabled!", this->plugin_name_);
  return true;
}
