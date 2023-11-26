#include <Plugin.h>

#include <stdexcept>
#include <string_view>

#include <ll/api/plugin/Plugin.h>

bool Plugin::load(ll::plugin::Plugin& self) {
    if (this->mSelf != nullptr) {
        throw std::runtime_error("plugin is loaded twice");
    }

    // Set the plugin handle.
    this->mSelf = &self;

    // Code for loading the plugin goes here.

    this->getLogger().info("Plugin loaded");
    return true;
}

bool Plugin::unload(ll::plugin::Plugin& self) {

    // Code for unloading the plugin goes here.

    this->getLogger().info("Plugin unloaded");
    return true;
}

bool Plugin::enable(ll::plugin::Plugin& self) {

    // Code for enabling the plugin goes here.

    this->getLogger().info("Plugin enabled");
    return true;
}

bool Plugin::disable(ll::plugin::Plugin& self) {

    // Code for disabling the plugin goes here.

    this->getLogger().info("Plugin disabled");
    return true;
}

ll::Logger const& Plugin::getLogger() const { return this->getSelf().getLogger(); }

std::string_view Plugin::getName() const { return this->getSelf().getManifest().name; }

ll::plugin::Plugin& Plugin::getSelf() const {
    if (this->mSelf == nullptr) {
        throw std::runtime_error("plugin is called before being loaded or after being unloaded");
    }

    return *this->mSelf;
}
