#include <Plugin.h>
#include <fmt/format.h>
#include <iostream>
#include <mc/server/ServerPlayer.h>
#include <stdexcept>
#include <string_view>

Plugin::Plugin(std::string_view plugin_name) : mSelf(nullptr), mPluginName(plugin_name) {}

Plugin::~Plugin() = default;

ll::Logger const& Plugin::getLogger() const {
    if (this->mSelf == nullptr) {
        throw std::runtime_error("Plugin::getLogger() called before Plugin::load()");
    }
    return this->mSelf->getLogger();
}

std::string_view Plugin::GetName() const { return this->mPluginName; }

bool Plugin::load(ll::plugin::Plugin& self) {
    if (this->mSelf != nullptr) {
        throw std::runtime_error("Plugin::load() called twice");
    }

    // Set the plugin handle.
    this->mSelf = &self;

    // Log the successful load.
    this->getLogger().info("Plugin loaded");

    return true;
}

bool Plugin::unload(ll::plugin::Plugin& self) {
    this->getLogger().info("Plugin unloaded");
    return true;
}

bool Plugin::enable(ll::plugin::Plugin& self) {
    this->getLogger().info("Plugin enabled");
    return true;
}

bool Plugin::disable(ll::plugin::Plugin& self) {
    this->getLogger().info("Plugin disabled");
    return true;
}

void Plugin::onPlayerJoin(ServerPlayer* player) {
    this->getLogger().info(fmt::format("{} joined the server", player->getRealName()));
    player->sendMessage(fmt::format("Hello, {}!", player->getRealName()));
}
